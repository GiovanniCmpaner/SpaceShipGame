
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "esp_system.h"

#include "game/object.h"
#include "lcd/lcd.h"
#include "image/meteor.h"
#include "image/asteroid.h"

extern game_state_t game_state;

//-----------------------------------------------------------------------------------------
static void game_generate_meteor(uint32_t milliseconds)
{
    if (game_state.play_timer < 30000)
    {
        return;
    }

    static uint32_t generator_countdown = 5000;

    if (generator_countdown > milliseconds)
    {
        generator_countdown -= milliseconds;
    }
    else
    {
        generator_countdown = 5000;

        for (size_t n = 0; n < sizeof(game_state.meteors) / sizeof(*game_state.meteors); n++)
        {
            meteor_control_t *meteor_control = &game_state.meteors[n];

            if (meteor_control->active)
            {
                continue;
            }

            meteor_control->active = true;
            meteor_control->arrow_active = true;
            meteor_control->arrow_countdown = 2000;
            meteor_control->arrow_progress = 0.0;
            meteor_control->animation_number = 0;
            meteor_control->animation_countdown = 100;

            meteor_control->direction = esp_random() % 4;
            if (meteor_control->direction == DIRECTION_DOWN)
            {
                const image_t *meteor_image = image_meteor[meteor_control->animation_number][IMAGE_ROTATED_0];
                meteor_control->vi = 0.0;
                meteor_control->vj = +6.0;
                meteor_control->px = (double)(meteor_image->width + esp_random() % (lcd_width() - 2 * meteor_image->width));
                meteor_control->py = 0.0;
            }
            else if (meteor_control->direction == DIRECTION_LEFT)
            {
                const image_t *meteor_image = image_meteor[meteor_control->animation_number][IMAGE_ROTATED_270];
                meteor_control->vi = -6.0;
                meteor_control->vj = 0.0;
                meteor_control->px = (double)(lcd_width() - 1);
                meteor_control->py = (double)(meteor_image->height + esp_random() % (162 - 2 * meteor_image->height));
            }
            else if (meteor_control->direction == DIRECTION_RIGHT)
            {
                const image_t *meteor_image = image_meteor[meteor_control->animation_number][IMAGE_ROTATED_90];
                meteor_control->vi = +6.0;
                meteor_control->vj = 0.0;
                meteor_control->px = 0.0;
                meteor_control->py = (double)(meteor_image->height + esp_random() % (162 - 2 * meteor_image->height));
            }
            else if (meteor_control->direction == DIRECTION_UP)
            {
                const image_t *meteor_image = image_meteor[meteor_control->animation_number][IMAGE_ROTATED_180];
                meteor_control->vi = 0.0;
                meteor_control->vj = -6.0;
                meteor_control->px = (double)(meteor_image->width + (esp_random() % lcd_width() - 2 * meteor_image->width));
                meteor_control->py = (double)(162 - 1);
            }
            break;
        }
    }
}
//-----------------------------------------------------------------------------------------
static void game_generate_pickup(uint32_t milliseconds)
{
    static uint32_t generator_countdown = 10000;

    if (generator_countdown > milliseconds)
    {
        generator_countdown -= milliseconds;
    }
    else
    {
        if (game_state.play_timer > 80000)
        {
            generator_countdown = 5000;
        }
        else
        {
            generator_countdown = 10000;
        }

        for (size_t n = 0; n < sizeof(game_state.pickups) / sizeof(*game_state.pickups); n++)
        {
            pickup_control_t *pickup_control = &game_state.pickups[n];

            if (pickup_control->active)
            {
                continue;
            }

            pickup_control->active = true;
            pickup_control->type = 1 + esp_random() % (image_pickups_length - 1);

            const image_t *pickup_image = image_pickups[pickup_control->type];
            pickup_control->px = lcd_width() - 1;
            pickup_control->py = (pickup_image->height) + esp_random() % (162 - pickup_image->height * 2);
            pickup_control->vi = -(double)(2 + esp_random() % 3);
            pickup_control->vj = 2.0 + (esp_random() % 4) / 4.0;
            pickup_control->trajectory_progress = 0.0;
            break;
        }
    }
}
//-----------------------------------------------------------------------------------------
static void game_generate_asteroid(uint32_t milliseconds)
{
    static uint16_t generator_countdown = 1000;

    if (generator_countdown > milliseconds)
    {
        generator_countdown -= milliseconds;
    }
    else
    {
        if (game_state.play_timer > 40000)
        {
            generator_countdown = 500;
        }
        else
        {
            generator_countdown = 1000;
        }

        for (size_t n = 0; n < sizeof(game_state.asteroids) / sizeof(*game_state.asteroids); n++)
        {
            asteroid_control_t *asteroid_control = &game_state.asteroids[n];

            if (asteroid_control->active)
            {
                continue;
            }

            asteroid_control->active = true;
            asteroid_control->number = esp_random() % image_asteroids_length;
            asteroid_control->life = 2 + asteroid_control->number * 3;
            {
                const uint8_t rotate = esp_random() % 4;
                const uint8_t mirror = esp_random() % 4;

                asteroid_control->orientation = IMAGE_ROTATED_0;
                if (rotate == 1)
                {
                    asteroid_control->orientation = IMAGE_ROTATED_90;
                }
                else if (rotate == 2)
                {
                    asteroid_control->orientation = IMAGE_ROTATED_180;
                }
                else if (rotate == 3)
                {
                    asteroid_control->orientation = IMAGE_ROTATED_270;
                }

                if (mirror == 1)
                {
                    asteroid_control->orientation |= IMAGE_MIRRORED_HORIZONTAL;
                }
                else if (mirror == 2)
                {
                    asteroid_control->orientation |= IMAGE_MIRRORED_VERTICAL;
                }
                else if (mirror == 3)
                {
                    asteroid_control->orientation |= IMAGE_MIRRORED_BOTH;
                }
            }
            const image_t *asteroid_image = image_asteroids[asteroid_control->number][asteroid_control->orientation][0];
            asteroid_control->px = lcd_width() - 1;
            asteroid_control->py = asteroid_image->height + esp_random() % (162 - 2 * asteroid_image->height);
            asteroid_control->vi = -(double)((game_state.play_timer > 60000 ? 3 : 1) + esp_random() % 3);
            asteroid_control->vj = 0;
            break;
        }
    }
}
//-----------------------------------------------------------------------------------------
void game_generate(uint32_t milliseconds)
{
    game_generate_asteroid(milliseconds);
    game_generate_pickup(milliseconds);
    game_generate_meteor(milliseconds);
}
//-----------------------------------------------------------------------------------------