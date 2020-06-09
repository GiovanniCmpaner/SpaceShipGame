#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "esp_timer.h"

#include "input.h"
#include "game/object.h"
#include "image/shield.h"
#include "image/info.h"

extern game_state_t game_state;

//-----------------------------------------------------------------------------------------
static void game_control_shield(bool activate)
{
    spaceship_control_t *spaceship_control = &game_state.spaceships[game_state.current_player];

    if (activate && spaceship_control->ammunitions[AMMUNITION_SHIELD] > 0)
    {
        spaceship_control->shield_active = true;
        spaceship_control->shield_animation_number = (spaceship_control->shield_animation_number + 1) % image_shields_length;
        spaceship_control->ammunitions[AMMUNITION_SHIELD]--;
    }
    else
    {
        spaceship_control->shield_active = false;
    }
}
//-----------------------------------------------------------------------------------------
static void game_generate_projectile(projectile_type_t type)
{
    spaceship_control_t *spaceship_control = &game_state.spaceships[game_state.current_player];

    if (type != PROJECTILE_MACHINEGUN)
    {
        if (spaceship_control->ammunitions[type] == 0)
        {
            return;
        }
        spaceship_control->ammunitions[type]--;
    }

    for (size_t n = sizeof(game_state.spaceships) / sizeof(*game_state.spaceships); n < sizeof(game_state.projectiles) / sizeof(*game_state.projectiles); n++)
    {
        projectile_control_t *projectile_control = &game_state.projectiles[n];

        if (projectile_control->active)
        {
            continue;
        }

        projectile_control->active = true;
        projectile_control->type = type;
        projectile_control->animation_number = 0;
        projectile_control->animation_countdown = 250;

        const image_t *spaceship_image = image_spaceships[spaceship_control->mode];
        if (projectile_control->type == PROJECTILE_MACHINEGUN)
        {
            static int8_t output = +1;

            const image_t *projectile_image = image_machinegun_projectile[projectile_control->animation_number];
            projectile_control->px = spaceship_control->px + 2 * spaceship_image->width / 3;
            projectile_control->py = spaceship_control->py + spaceship_image->height / 2 - projectile_image->height / 2 + (spaceship_image->height / 3) * output;
            projectile_control->vi = +6.0;
            projectile_control->vj = 0.0;
            output *= -1;
        }
        else if (projectile_control->type == PROJECTILE_MISSILE)
        {
            const image_t *projectile_image = image_missile_projectile[projectile_control->animation_number];
            projectile_control->px = spaceship_control->px + spaceship_image->width;
            projectile_control->py = spaceship_control->py + spaceship_image->height / 2 - projectile_image->height / 2;
            projectile_control->vi = +3.0;
            projectile_control->vj = 0.0;
        }
        else if (projectile_control->type == PROJECTILE_MINE)
        {
            const image_t *projectile_image = image_mine_projectile[projectile_control->animation_number];
            projectile_control->px = spaceship_control->px + spaceship_image->width / 2 - projectile_image->width / 2,
            projectile_control->py = spaceship_control->py + spaceship_image->height / 2 - projectile_image->height / 2,
            projectile_control->vi = 0.0;
            projectile_control->vj = -0.1;
        }

        break;
    }
}
//-----------------------------------------------------------------------------------------
static void game_input_actions(uint32_t millisDiff)
{
    spaceship_control_t *spaceship_control = &game_state.spaceships[game_state.current_player];

    if (!spaceship_control->active)
    {
        return;
    }

    static uint8_t levels[4] = {};
    for (size_t n = 0; n < 4; n++)
    {
        input_action(n, &levels[n]);
    }

    static int64_t timers[4] = {};
    const int64_t current_time = esp_timer_get_time();

    if (levels[ACTION_UP])
    {
        const uint32_t time_diff = (current_time - timers[ACTION_UP]) / 1000;
        if (time_diff >= 50)
        {
            timers[ACTION_UP] = current_time;
            game_generate_projectile(PROJECTILE_MACHINEGUN);
        }
    }
    if (levels[ACTION_LEFT])
    {
        const uint32_t time_diff = (current_time - timers[ACTION_LEFT]) / 1000;
        if (time_diff >= 250)
        {
            levels[ACTION_LEFT] = 0;
            timers[ACTION_LEFT] = current_time;
            game_generate_projectile(PROJECTILE_MISSILE);
        }
    }
    if (levels[ACTION_RIGHT])
    {
        const uint32_t time_diff = (current_time - timers[ACTION_RIGHT]) / 1000;
        if (time_diff >= 1000)
        {
            levels[ACTION_RIGHT] = 0;
            timers[ACTION_RIGHT] = current_time;
            game_generate_projectile(PROJECTILE_MINE);
        }
    }

    const uint32_t time_diff = (current_time - timers[ACTION_DOWN]) / 1000;
    if (time_diff >= 100)
    {
        if (levels[ACTION_DOWN])
        {
            timers[ACTION_DOWN] = current_time;
        }
        game_control_shield(levels[ACTION_DOWN]);
    }
}
//-----------------------------------------------------------------------------------------
static void game_input_directions()
{
    spaceship_control_t *spaceship_control = &game_state.spaceships[game_state.current_player];

    if (!spaceship_control->active)
    {
        return;
    }

    static double x = 0.0;
    static double y = 0.0;
    input_directions(&x, &y);

    spaceship_control->vi = x;
    spaceship_control->vj = y;
}
//-----------------------------------------------------------------------------------------
void game_input(uint32_t millisDiff)
{
    game_input_actions();
    game_input_directions();
}
//-----------------------------------------------------------------------------------------