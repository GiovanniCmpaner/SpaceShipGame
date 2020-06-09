#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "game/object.h"
#include "lcd/lcd.h"
#include "image/image.h"
#include "image/asteroid.h"
#include "image/meteor.h"
#include "image/projectile.h"

extern game_state_t game_state;

//-----------------------------------------------------------------------------------------
static void game_move_projectiles(uint32_t millisDiff)
{
    for (size_t n = 0; n < sizeof(game_state.projectiles) / sizeof(*game_state.projectiles); n++)
    {
        projectile_control_t *projectile_control = &game_state.projectiles[n];

        if (!projectile_control->active)
        {
            continue;
        }

        if (projectile_control->type == PROJECTILE_MISSILE)
        {
            if (projectile_control->animation_countdown > millisDiff)
            {
                projectile_control->animation_countdown -= millisDiff;
            }
            else
            {
                projectile_control->animation_countdown = 250;
                projectile_control->animation_number = (projectile_control->animation_number + 1) % image_missile_projectile_length;
            }
        }
        else if (projectile_control->type == PROJECTILE_MACHINEGUN)
        {
            // Nothing
        }
        else if (projectile_control->type == PROJECTILE_MINE)
        {
            if (projectile_control->animation_countdown > millisDiff)
            {
                projectile_control->animation_countdown -= millisDiff;
            }
            else
            {
                projectile_control->animation_countdown = 2000;
                if (projectile_control->animation_number == 0)
                {
                    projectile_control->vj = +0.1;
                }
                else if (projectile_control->animation_number == 1)
                {
                    projectile_control->vj = -0.1;
                }
                projectile_control->animation_number = (projectile_control->animation_number + 1) % 2;
            }
        }

        projectile_control->px += projectile_control->vi;
        projectile_control->py += projectile_control->vj;

        const image_t *projectile_image = NULL;
        if (projectile_control->type == PROJECTILE_MACHINEGUN)
        {
            projectile_image = image_machinegun_projectile[0];
        }
        else if (projectile_control->type == PROJECTILE_MISSILE)
        {
            projectile_image = image_missile_projectile[projectile_control->animation_number];
        }
        else if (projectile_control->type == PROJECTILE_MINE)
        {
            projectile_image = image_mine_projectile[0];
        }
        if ((int16_t)projectile_control->px + projectile_image->width < 0 || (int16_t)projectile_control->py + projectile_image->height < 0 || (int16_t)projectile_control->px >= lcd_width() || (int16_t)projectile_control->py >= 162)
        {
            projectile_control->active = false;
        }
    }
}
//-----------------------------------------------------------------------------------------
static void game_move_asteroids(uint32_t millisDiff)
{
    for (size_t n = 0; n < sizeof(game_state.asteroids) / sizeof(*game_state.asteroids); n++)
    {
        asteroid_control_t *asteroid_control = &game_state.asteroids[n];

        if (!asteroid_control->active)
        {
            continue;
        }

        asteroid_control->px += asteroid_control->vi;
        asteroid_control->py += asteroid_control->vj;

        if (asteroid_control->damage_active)
        {
            if (asteroid_control->damage_countdown > millisDiff)
            {
                asteroid_control->damage_countdown -= millisDiff;
            }
            else
            {
                asteroid_control->damage_countdown = 0;
                asteroid_control->damage_active = false;
            }
        }
        else
        {
            if (asteroid_control->damage_countdown + millisDiff < 50)
            {
                asteroid_control->damage_countdown += millisDiff;
            }
            else
            {
                asteroid_control->damage_countdown = 50;
            }
        }

        const image_t *asteroid_image = image_asteroids[asteroid_control->number][asteroid_control->orientation][0];
        if ((int16_t)asteroid_control->px + asteroid_image->width < 0 || (int16_t)asteroid_control->py + asteroid_image->height < 0 || (int16_t)asteroid_control->px >= lcd_width() || (int16_t)asteroid_control->py >= 162)
        {
            asteroid_control->active = false;
        }
    }
}
//-----------------------------------------------------------------------------------------
static void game_move_pickups(uint32_t millisDiff)
{
    for (size_t n = 0; n < sizeof(game_state.pickups) / sizeof(*game_state.pickups); n++)
    {
        pickup_control_t *pickup_control = &game_state.pickups[n];

        if (!pickup_control->active)
        {
            continue;
        }

        pickup_control->trajectory_progress += 0.02;
        if (pickup_control->trajectory_progress > 1.0)
        {
            pickup_control->trajectory_progress = 0.0;
        }

        pickup_control->px += pickup_control->vi;
        pickup_control->py += pickup_control->vj * sin(2.0 * M_PI * pickup_control->trajectory_progress);

        const image_t *pickup_image = image_pickups[pickup_control->type];
        if ((int16_t)pickup_control->px + pickup_image->width < 0 || (int16_t)pickup_control->py + pickup_image->height < 0 || (int16_t)pickup_control->px >= lcd_width() || (int16_t)pickup_control->py >= 162)
        {
            pickup_control->active = false;
        }
    }
}
//-----------------------------------------------------------------------------------------
static void game_move_spaceships(uint32_t millisDiff)
{
    for (size_t n = 0; n < sizeof(game_state.spaceships) / sizeof(*game_state.spaceships); n++)
    {
        spaceship_control_t *spaceship_control = &game_state.spaceships[n];

        if (!spaceship_control->active)
        {
            continue;
        }

        {
            spaceship_control->px += spaceship_control->vi * (spaceship_control->shield_active ? 2.5 : 1.5);
            spaceship_control->py += spaceship_control->vj * (spaceship_control->shield_active ? 2.5 : 1.5);

            const image_t *spaceship_image = image_spaceships[spaceship_control->mode];
            if (spaceship_control->px > (lcd_width() - spaceship_image->width - 1))
            {
                spaceship_control->px = (lcd_width() - spaceship_image->width - 1);
            }
            else if (spaceship_control->px <= 0.00)
            {
                spaceship_control->px = 0.00;
            }

            if (spaceship_control->py > (162 - spaceship_image->height - 1))
            {
                spaceship_control->py = (162 - spaceship_image->height - 1);
            }
            else if (spaceship_control->py <= 0.00)
            {
                spaceship_control->py = 0.00;
            }
        }

        {
            if (spaceship_control->vj > 0.30)
            {
                spaceship_control->mode = SPACESHIP_UP;
            }
            else if (spaceship_control->vj < -0.30)
            {
                spaceship_control->mode = SPACESHIP_DOWN;
            }
            else if (spaceship_control->vi > 0.30)
            {
                spaceship_control->mode = SPACESHIP_RIGHT;
            }
            else if (spaceship_control->vi < -0.30)
            {
                spaceship_control->mode = SPACESHIP_LEFT;
            }
            else
            {
                spaceship_control->mode = SPACESHIP_IDLE;
            }

            if (spaceship_control->mode != SPACESHIP_IDLE)
            {
                double modulus = sqrt(pow(spaceship_control->vi, 2) + pow(spaceship_control->vj, 2));

                if (modulus > 0.90)
                {
                    spaceship_control->mode |= SPACESHIP_STRONG;
                }
                else if (modulus > 0.30)
                {
                    spaceship_control->mode |= SPACESHIP_MEDIUM;
                }
                else
                {
                    spaceship_control->mode |= SPACESHIP_WEAK;
                }
            }
        }

        if (spaceship_control->collision_countdown > millisDiff)
        {
            spaceship_control->collision_countdown -= millisDiff;
            if (spaceship_control->collision_countdown >= 2000)
            {
                spaceship_control->collision_active = (spaceship_control->collision_countdown / 250) % 2;
            }
            else if (spaceship_control->collision_countdown >= 500)
            {
                spaceship_control->collision_active = (spaceship_control->collision_countdown / 100) % 2;
            }
            else
            {
                spaceship_control->collision_active = (spaceship_control->collision_countdown / 50) % 2;
            }
        }
        else
        {
            spaceship_control->collision_active = false;
            spaceship_control->collision_countdown = 0;
        }
    }
}
//-----------------------------------------------------------------------------------------
static void game_move_impacts(uint32_t millisDiff)
{
    for (size_t n = 0; n < sizeof(game_state.impacts) / sizeof(*game_state.impacts); n++)
    {
        impact_control_t *impact_control = &game_state.impacts[n];

        if (!impact_control->active)
        {
            continue;
        }

        if (impact_control->animation_countdown > millisDiff)
        {
            impact_control->animation_countdown -= millisDiff;
        }
        else
        {
            impact_control->animation_countdown = 50;
            impact_control->animation_number++;

            if ((impact_control->size == IMPACT_SMALL && impact_control->animation_number < 1 * image_impact_shockwave_length / 3) || (impact_control->size == IMPACT_MEDIUM && impact_control->animation_number < 2 * image_impact_shockwave_length / 3) || (impact_control->size == IMPACT_BIG && impact_control->animation_number < 3 * image_impact_shockwave_length / 3))
            {
                // Nothing
            }
            else
            {
                impact_control->active = false;
            }
        }
    }
}
//-----------------------------------------------------------------------------------------
static void game_move_meteors(uint32_t millisDiff)
{
    for (size_t n = 0; n < sizeof(game_state.meteors) / sizeof(*game_state.meteors); n++)
    {
        meteor_control_t *meteor_control = &game_state.meteors[n];

        if (!meteor_control->active)
        {
            continue;
        }

        if (meteor_control->arrow_active)
        {
            if (meteor_control->arrow_countdown > millisDiff)
            {
                meteor_control->arrow_countdown -= millisDiff;

                meteor_control->arrow_progress += 1.5;

                if (meteor_control->direction == DIRECTION_DOWN || meteor_control->direction == DIRECTION_UP)
                {
                    const image_t *arrow_image = image_arrow[IMAGE_ROTATED_0];

                    if (meteor_control->arrow_progress > arrow_image->width)
                    {
                        meteor_control->arrow_progress = 0.0;
                    }
                }
                else if (meteor_control->direction == DIRECTION_LEFT || meteor_control->direction == DIRECTION_RIGHT)
                {
                    const image_t *arrow_image = image_arrow[IMAGE_ROTATED_90];

                    if (meteor_control->arrow_progress > arrow_image->height)
                    {
                        meteor_control->arrow_progress = 0.0;
                    }
                }
            }
            else
            {
                meteor_control->arrow_active = false;
            }
        }
        else
        {
            if (meteor_control->animation_countdown > millisDiff)
            {
                meteor_control->animation_countdown -= millisDiff;
            }
            else
            {
                meteor_control->animation_countdown = 100;
                meteor_control->animation_number = (meteor_control->animation_number + 1) % image_meteor_length;
            }

            meteor_control->px += meteor_control->vi;
            meteor_control->py += meteor_control->vj;

            const image_t *meteor_image = NULL;
            if (meteor_control->direction == DIRECTION_DOWN)
            {
                meteor_image = image_meteor[meteor_control->animation_number][IMAGE_ROTATED_0];
            }
            else if (meteor_control->direction == DIRECTION_LEFT)
            {
                meteor_image = image_meteor[meteor_control->animation_number][IMAGE_ROTATED_270];
            }
            else if (meteor_control->direction == DIRECTION_RIGHT)
            {
                meteor_image = image_meteor[meteor_control->animation_number][IMAGE_ROTATED_90];
            }
            else if (meteor_control->direction == DIRECTION_UP)
            {
                meteor_image = image_meteor[meteor_control->animation_number][IMAGE_ROTATED_180];
            }
            if ((int16_t)meteor_control->px + meteor_image->width < 0 || (int16_t)meteor_control->py + meteor_image->height < 0 || (int16_t)meteor_control->px >= lcd_width() || (int16_t)meteor_control->py >= 162)
            {
                meteor_control->active = false;
            }
        }
    }
}
//-----------------------------------------------------------------------------------------
void game_move(uint32_t millisDiff)
{
    //game_move_background();
    game_move_spaceships(millisDiff);
    game_move_asteroids(millisDiff);
    game_move_projectiles(millisDiff);
    game_move_impacts(millisDiff);
    game_move_pickups(millisDiff);
    game_move_meteors(millisDiff);
}
//-----------------------------------------------------------------------------------------