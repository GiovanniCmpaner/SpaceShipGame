#ifndef OBJECT_H
#define OBJECT_H

#include <stdint.h>
#include <stdbool.h>

#include "image/image.h"
#include "image/spaceship.h"
#include "image/projectile.h"
#include "image/impact.h"
#include "image/pickup.h"

typedef enum
{
    DIRECTION_UP,
    DIRECTION_DOWN,
    DIRECTION_LEFT,
    DIRECTION_RIGHT,
} direction_t;

typedef struct
{
    uint8_t active;
    float px;
    float py;
    float vi;
    float vj;
    //spaceship_mode_t mode;
    uint8_t mode;
    uint8_t life;
    uint16_t collision_countdown;
    uint8_t collision_active;
    uint16_t ammunitions[4];
    uint8_t shield_active;
    uint8_t shield_animation_number;
    uint32_t alive_timer;
    uint16_t asteroids_counter;
} spaceship_control_t;

typedef struct
{
    uint8_t active;
    float px;
    float py;
    //impact_type_t type;
    uint8_t type;
    //impact_size_t size;
    uint8_t size;
    uint8_t animation_number;
    uint32_t animation_countdown;
} impact_control_t;

typedef struct
{
    uint8_t active;
    float px;
    float py;
    float vi;
    float vj;
    uint8_t owner;
    //projectile_type_t type;
    uint8_t type;
    uint8_t animation_number;
    uint32_t animation_countdown;
} projectile_control_t;

typedef struct
{
    uint8_t active;
    float px;
    float py;
    float vi;
    float vj;
    uint8_t number;
    //image_orientation_t orientation;
    uint8_t orientation;
    uint8_t life;
    uint32_t damage_countdown;
    uint8_t damage_active;
} asteroid_control_t;

typedef struct
{
    uint8_t active;
    float px;
    float py;
    float vi;
    float vj;
    //pickup_type_t type;
    uint8_t type;
    float trajectory_progress;
} pickup_control_t;

typedef struct
{
    uint8_t active;
    float px;
    float py;
    float vi;
    float vj;
    //direction_t direction;
    uint8_t direction;
    uint8_t animation_number;
    uint32_t animation_countdown;
    uint8_t arrow_active;
    uint32_t arrow_countdown;
    float arrow_progress;
} meteor_control_t;

typedef struct
{
    uint8_t current_player;
    uint32_t play_timer;
    uint8_t fps;

    spaceship_control_t  spaceships [2];
    asteroid_control_t   asteroids  [20];
    impact_control_t     impacts    [15];
    projectile_control_t projectiles[50];
    pickup_control_t     pickups    [5];
    meteor_control_t     meteors    [5];
} game_state_t;

#endif