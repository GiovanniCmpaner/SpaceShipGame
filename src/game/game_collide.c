#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "game/object.h"
#include "image/image.h"
#include "image/asteroid.h"
#include "image/meteor.h"
#include "image/projectile.h"
#include "image/info.h"

extern game_state_t game_state;

#ifndef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif

#ifndef min
#define min(a, b) ((a) < (b) ? (a) : (b))
#endif

//-----------------------------------------------------------------------------------------
static bool game_objects_collide(int16_t x0, int16_t y0, const image_t *image0, int16_t x1, int16_t y1, const image_t *image1, int16_t *collision_x, int16_t *collision_y)
{
    // intersection
    // https://stackoverflow.com/questions/19753134/get-the-points-of-intersection-from-2-rectangles
    const int16_t x5 = max(x0, x1);
    const int16_t y5 = max(y0, y1);
    const int16_t x6 = min(x0 + image0->width, x1 + image1->width);
    const int16_t y6 = min(y0 + image0->height, y1 + image1->height);

    if (x5 < x6 && y5 < y6)
    {
        for (int16_t y = y5; y < y6; y++)
        {
            const uint16_t *control1_row_ptr = &image0->data[(y - y0) * image0->width + (x5 - x0)];
            const uint16_t *control2_row_ptr = &image1->data[(y - y1) * image1->width + (x5 - x1)];

            for (int16_t x = x5; x < x6; x++)
            {
                // check non-transparent pixels
                if (*control1_row_ptr != image0->transparent_color && *control2_row_ptr != image1->transparent_color)
                {
                    if (collision_x != NULL)
                    {
                        *collision_x = x;
                    }
                    if (collision_y != NULL)
                    {
                        *collision_y = y;
                    }
                    return true;
                }
                control1_row_ptr++;
                control2_row_ptr++;
            }
        }
    }
    return false;
}
//-----------------------------------------------------------------------------------------
static void game_generate_impact(int16_t x, int16_t y, impact_type_t type, impact_size_t size)
{
    for (size_t n = 0; n < sizeof(game_state.impacts) / sizeof(*game_state.impacts); n++)
    {
        impact_control_t *impact_control = &game_state.impacts[n];

        if (impact_control->active)
        {
            continue;
        }

        impact_control->active = true;
        impact_control->animation_number = 0;
        impact_control->animation_countdown = 50;
        const image_t *impact_image = image_impact_shockwave[impact_control->animation_number];
        impact_control->px = x - impact_image->width / 2;
        impact_control->py = y - impact_image->height / 2;
        impact_control->type = type;
        impact_control->size = size;

        break;
    }
}
//-----------------------------------------------------------------------------------------
static void game_collide_projectiles_asteroids()
{
    for (size_t n = 0; n < sizeof(game_state.projectiles) / sizeof(*game_state.projectiles); n++)
    {
        projectile_control_t *projectile_control = &game_state.projectiles[n];

        if (!projectile_control->active)
        {
            continue;
        }

        for (size_t n = 0; n < sizeof(game_state.asteroids) / sizeof(*game_state.asteroids); n++)
        {
            asteroid_control_t *asteroid_control = &game_state.asteroids[n];

            if (!asteroid_control->active)
            {
                continue;
            }

            const image_t *asteroid_image = image_asteroids[asteroid_control->number][asteroid_control->orientation][asteroid_control->damage_active];
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
            int16_t collision_x, collision_y;
            if (!game_objects_collide(projectile_control->px,
                                      projectile_control->py,
                                      projectile_image,
                                      asteroid_control->px,
                                      asteroid_control->py,
                                      asteroid_image,
                                      &collision_x,
                                      &collision_y))
            {
                continue;
            }

            projectile_control->active = false;

            uint8_t damage = 0;
            if (projectile_control->type == PROJECTILE_MACHINEGUN)
            {
                damage = 1;
            }
            else if (projectile_control->type == PROJECTILE_MISSILE)
            {
                damage = 12;
                game_generate_impact(collision_x, collision_y, IMPACT_SHOCKWAVE, IMPACT_MEDIUM);
            }
            else if (projectile_control->type == PROJECTILE_MINE)
            {
                damage = 24;
                game_generate_impact(collision_x, collision_y, IMPACT_SHOCKWAVE, IMPACT_BIG);
            }

            if (asteroid_control->life > damage)
            {
                asteroid_control->life -= damage;
                if (!asteroid_control->damage_active && asteroid_control->damage_countdown == 50)
                {
                    asteroid_control->damage_active = true;
                }
            }
            else
            {
                asteroid_control->active = false;
            }

            break;
        }
    }
}
//-----------------------------------------------------------------------------------------
static void game_collide_spaceships_asteroids()
{
    for (size_t n = 0; n < sizeof(game_state.spaceships) / sizeof(*game_state.spaceships); n++)
    {
        spaceship_control_t *spaceship_control = &game_state.spaceships[n];

        if (!spaceship_control->active || spaceship_control->collision_countdown > 0 || spaceship_control->shield_active)
        {
            continue;
        }

        for (size_t n = 0; n < sizeof(game_state.asteroids) / sizeof(*game_state.asteroids); n++)
        {
            asteroid_control_t *asteroid_control = &game_state.asteroids[n];

            if (!asteroid_control->active)
            {
                continue;
            }

            const image_t *spaceship_image = image_spaceships[spaceship_control->mode];
            const image_t *asteroid_image = image_asteroids[asteroid_control->number][asteroid_control->orientation][asteroid_control->damage_active];
            if (!game_objects_collide(spaceship_control->px,
                                      spaceship_control->py,
                                      spaceship_image,
                                      asteroid_control->px,
                                      asteroid_control->py,
                                      asteroid_image,
                                      NULL,
                                      NULL))
            {
                continue;
            }

            if (spaceship_control->life > 0)
            {
                spaceship_control->life--;
                spaceship_control->collision_countdown = 3000;
                spaceship_control->collision_active = true;
            }
            else
            {
                spaceship_control->active = false;
                game_generate_impact(spaceship_control->px + spaceship_image->width / 2,
                                     spaceship_control->py + spaceship_image->height / 2,
                                     IMPACT_SHOCKWAVE, IMPACT_BIG);
            }

            break;
        }
    }
}
//-----------------------------------------------------------------------------------------
static void game_collide_meteors_spaceships_asteroids()
{
    for (size_t n = 0; n < sizeof(game_state.meteors) / sizeof(*game_state.meteors); n++)
    {
        meteor_control_t *meteor_control = &game_state.meteors[n];

        if (!meteor_control->active || meteor_control->arrow_active)
        {
            continue;
        }

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

        for (size_t n = 0; n < sizeof(game_state.asteroids) / sizeof(*game_state.asteroids); n++)
        {
            asteroid_control_t *asteroid_control = &game_state.asteroids[n];

            if (!asteroid_control->active)
            {
                continue;
            }

            const image_t *asteroid_image = image_asteroids[asteroid_control->number][asteroid_control->orientation][asteroid_control->damage_active];

            int16_t collision_x, collision_y;
            if (!game_objects_collide(asteroid_control->px,
                                      asteroid_control->py,
                                      asteroid_image,
                                      meteor_control->px,
                                      meteor_control->py,
                                      meteor_image,
                                      &collision_x,
                                      &collision_y))
            {
                continue;
            }

            game_generate_impact(collision_x, collision_y, IMPACT_SHOCKWAVE, IMPACT_BIG);
            asteroid_control->active = false;
        }

        for (size_t n = 0; n < sizeof(game_state.spaceships) / sizeof(*game_state.spaceships); n++)
        {
            spaceship_control_t *spaceship_control = &game_state.spaceships[n];

            if (!spaceship_control->active || spaceship_control->collision_countdown > 0 || spaceship_control->shield_active)
            {
                continue;
            }

            const image_t *spaceship_image = image_spaceships[spaceship_control->mode];
            if (!game_objects_collide(spaceship_control->px,
                                      spaceship_control->py,
                                      spaceship_image,
                                      meteor_control->px,
                                      meteor_control->py,
                                      meteor_image,
                                      NULL,
                                      NULL))
            {
                continue;
            }

            if (spaceship_control->life > 0)
            {
                spaceship_control->life--;
                spaceship_control->collision_countdown = 3000;
                spaceship_control->collision_active = true;
            }
            else
            {
                spaceship_control->active = false;
                game_generate_impact(spaceship_control->px + spaceship_image->width / 2, spaceship_control->py + spaceship_image->height / 2, IMPACT_SHOCKWAVE, IMPACT_BIG);
            }
        }
    }
}
//-----------------------------------------------------------------------------------------
static void game_collide_spaceships_pickups()
{
    for (size_t n = 0; n < sizeof(game_state.spaceships) / sizeof(*game_state.spaceships); n++)
    {
        spaceship_control_t *spaceship_control = &game_state.spaceships[n];

        if (!spaceship_control->active)
        {
            continue;
        }

        for (size_t n = 0; n < sizeof(game_state.pickups) / sizeof(*game_state.pickups); n++)
        {
            pickup_control_t *pickup_control = &game_state.pickups[n];

            if (!pickup_control->active)
            {
                continue;
            }

            const image_t *spaceship_image = image_spaceships[spaceship_control->mode];
            const image_t *pickup_image = image_pickups[pickup_control->type];
            if (!game_objects_collide(spaceship_control->px, spaceship_control->py, spaceship_image, pickup_control->px, pickup_control->py, pickup_image, NULL, NULL))
            {
                continue;
            }

            if (pickup_control->type == PICKUP_HEART)
            {
                if (spaceship_control->life < 3)
                {
                    spaceship_control->life++;
                    pickup_control->active = false;
                }
            }
            else if (pickup_control->type == PICKUP_MISSILE)
            {
                if (spaceship_control->ammunitions[AMMUNITION_MISSILE] < 20)
                {
                    spaceship_control->ammunitions[AMMUNITION_MISSILE] = 20;
                    pickup_control->active = false;
                }
            }
            else if (pickup_control->type == PICKUP_MINE)
            {
                if (spaceship_control->ammunitions[AMMUNITION_MINE] < 10)
                {
                    spaceship_control->ammunitions[AMMUNITION_MINE] = 10;
                    pickup_control->active = false;
                }
            }
            else if (pickup_control->type == PICKUP_SHIELD)
            {
                if (spaceship_control->ammunitions[AMMUNITION_SHIELD] < 30)
                {
                    spaceship_control->ammunitions[AMMUNITION_SHIELD] = 30;
                    pickup_control->active = false;
                }
            }

            break;
        }
    }
}
//-----------------------------------------------------------------------------------------
void game_collide()
{
    game_collide_spaceships_asteroids();
    game_collide_spaceships_pickups();
    game_collide_projectiles_asteroids();
    game_collide_meteors_spaceships_asteroids();
}
//-----------------------------------------------------------------------------------------