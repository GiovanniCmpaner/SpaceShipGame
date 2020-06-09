#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "game/object.h"
#include "lcd/lcd.h"
#include "font/font.h"
#include "image/image.h"
#include "image/asteroid.h"
#include "image/meteor.h"
#include "image/projectile.h"
#include "image/spaceship.h"
#include "image/background.h"
#include "image/info.h"
#include "image/shield.h"

extern game_state_t game_state;
extern const uint8_t fps;

//-----------------------------------------------------------------------------------------
static void game_draw_spaceships()
{
    for (size_t n = 0; n < sizeof(game_state.spaceships) / sizeof(*game_state.spaceships); n++)
    {
        const spaceship_control_t *spaceship_control = &game_state.spaceships[n];

        if (!spaceship_control->active || spaceship_control->collision_active)
        {
            continue;
        }

        const image_t *spaceship_image = image_spaceships[spaceship_control->mode];
        lcd_draw_image(spaceship_control->px, spaceship_control->py, spaceship_image);

        if (spaceship_control->shield_active)
        {
            const image_t *shield_image = image_shields[spaceship_control->shield_animation_number];
            lcd_draw_image(spaceship_control->px + spaceship_image->width / 2 - shield_image->width / 2,
                           spaceship_control->py + spaceship_image->height / 2 - shield_image->height / 2,
                           shield_image);
        }
    }
}
//-----------------------------------------------------------------------------------------
static void game_draw_background()
{
    static const image_t *current_background = &image_background_normal;
    static const image_t *next_background = &image_background_normal;

    static bool transition = false;
    static bool transitioning = false;
    static bool transitioned = false;
    if (!transition && game_state.play_timer > 30000)
    {
        transition = true;
    }

    static double i = 0.0;
    lcd_draw_image(-i, 0, current_background);
    if (i > current_background->width - lcd_width())
    {
        lcd_draw_image(-i + current_background->width, 0, next_background);
    }
    i += fps / 45.0;
    if (i >= current_background->width)
    {
        i = 0.0;
        if (transition)
        {
            if (!transitioned)
            {
                if (!transitioning)
                {
                    transitioning = true;
                    next_background = &image_background_transition;
                }
                else
                {
                    transitioned = true;
                    current_background = &image_background_transition;
                    next_background = &image_background_red;
                }
            }
            else
            {
                current_background = &image_background_red;
            }
        }
    }
}
//-----------------------------------------------------------------------------------------
static void game_draw_projectiles()
{
    for (size_t n = 0; n < sizeof(game_state.projectiles) / sizeof(*game_state.projectiles); n++)
    {
        const projectile_control_t *projectile_control = &game_state.projectiles[n];

        if (!projectile_control->active)
        {
            continue;
        }

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
        lcd_draw_image(projectile_control->px, projectile_control->py, projectile_image);
    }
}
//-----------------------------------------------------------------------------------------
static void game_draw_asteroids()
{
    for (size_t n = 0; n < sizeof(game_state.asteroids) / sizeof(*game_state.asteroids); n++)
    {
        const asteroid_control_t *asteroid_control = &game_state.asteroids[n];

        if (!asteroid_control->active)
        {
            continue;
        }

        const image_t *asteroid_image = image_asteroids[asteroid_control->number][asteroid_control->orientation][asteroid_control->damage_active];
        lcd_draw_image(asteroid_control->px, asteroid_control->py, asteroid_image);
    }
}
//-----------------------------------------------------------------------------------------
static void game_draw_impacts()
{
    for (size_t n = 0; n < sizeof(game_state.impacts) / sizeof(*game_state.impacts); n++)
    {
        const impact_control_t *impact_control = &game_state.impacts[n];

        if (!impact_control->active)
        {
            continue;
        }

        const image_t *impact_image = image_impact_shockwave[impact_control->animation_number];
        lcd_draw_image(impact_control->px, impact_control->py, impact_image);
    }
}
//-----------------------------------------------------------------------------------------
static void game_draw_pickups()
{
    for (size_t n = 0; n < sizeof(game_state.pickups) / sizeof(*game_state.pickups); n++)
    {
        const pickup_control_t *pickup_control = &game_state.pickups[n];

        if (!pickup_control->active)
        {
            continue;
        }

        const image_t *pickup_image = image_pickups[pickup_control->type];
        lcd_draw_image(pickup_control->px, pickup_control->py, pickup_image);
    }
}
//-----------------------------------------------------------------------------------------
static void game_draw_meteors()
{
    for (size_t n = 0; n < sizeof(game_state.meteors) / sizeof(*game_state.meteors); n++)
    {
        const meteor_control_t *meteor_control = &game_state.meteors[n];

        if (!meteor_control->active)
        {
            continue;
        }

        if (meteor_control->arrow_active)
        {
            if (meteor_control->direction == DIRECTION_DOWN)
            {
                const image_t *arrow_image = image_arrow[IMAGE_ROTATED_270];

                double py = meteor_control->py - arrow_image->height + meteor_control->arrow_progress;
                while (py < 162 + arrow_image->height)
                {
                    lcd_draw_image(meteor_control->px, py, arrow_image);
                    py += arrow_image->height;
                }
            }
            else if (meteor_control->direction == DIRECTION_LEFT)
            {
                const image_t *arrow_image = image_arrow[IMAGE_ROTATED_180];

                double px = meteor_control->px + arrow_image->width - meteor_control->arrow_progress;
                while (px > 0.0 - arrow_image->width)
                {
                    lcd_draw_image(px, meteor_control->py, arrow_image);
                    px -= arrow_image->width;
                }
            }
            else if (meteor_control->direction == DIRECTION_RIGHT)
            {
                const image_t *arrow_image = image_arrow[IMAGE_ROTATED_0];

                double px = meteor_control->px - arrow_image->width + meteor_control->arrow_progress;
                while (px < lcd_width() + arrow_image->width)
                {
                    lcd_draw_image(px, meteor_control->py, arrow_image);
                    px += arrow_image->width;
                }
            }
            else if (meteor_control->direction == DIRECTION_UP)
            {
                const image_t *arrow_image = image_arrow[IMAGE_ROTATED_90];

                double py = meteor_control->py + arrow_image->height - meteor_control->arrow_progress;
                while (py > 0.0 - arrow_image->height)
                {
                    lcd_draw_image(meteor_control->px, py, arrow_image);
                    py -= arrow_image->height;
                }
            }
        }
        else
        {
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
            lcd_draw_image(meteor_control->px, meteor_control->py, meteor_image);
        }
    }
}
//-----------------------------------------------------------------------------------------
static void game_draw_infos()
{
    spaceship_control_t *spaceship_control = &game_state.spaceships[game_state.current_player];

    lcd_draw_rectangle_filled(0, 162, lcd_width() - 1, lcd_height() - 1, COLOR_BLACK);

    lcd_set_font(&font9x7);
    for (size_t n = 0; n < image_ammunitions_length; n++)
    {
        lcd_draw_image(8 + 35 * n, 166, image_ammunitions[n]);
        if (n == 0)
        {
            lcd_draw_image(20 + 35 * n, 166, &image_infinity);
        }
        else
        {
            lcd_printf(20 + 35 * n, 166, COLOR_RED, "%02u", spaceship_control->ammunitions[n]);
        }
    }

    for (size_t n = 0; n < 3; n++)
    {
        lcd_draw_image(170 + 12 * n, 166, image_hearts[spaceship_control->life > n]);
    }
}
//-----------------------------------------------------------------------------------------
void game_draw()
{
    game_draw_background();
    game_draw_asteroids();
    game_draw_impacts();
    game_draw_projectiles();
    game_draw_pickups();
    game_draw_meteors();
    game_draw_spaceships();
    game_draw_infos();
    lcd_refresh();
}
//-----------------------------------------------------------------------------------------