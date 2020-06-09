#ifndef IMAGE_PROJECTILE_H
#define IMAGE_PROJECTILE_H

#include <stdint.h>
#include <string.h>

#include "image.h"
//-----------------------------------------------------------------------------------------
typedef enum {
    PROJECTILE_MACHINEGUN,
    PROJECTILE_MISSILE,
    PROJECTILE_MINE
} projectile_type_t;
//-----------------------------------------------------------------------------------------
extern const image_t* const image_mine_projectile[];
extern const size_t image_mine_projectile_length;
//-----------------------------------------------------------------------------------------
extern const image_t* const image_missile_projectile[];
extern const size_t image_missile_projectile_length;
//-----------------------------------------------------------------------------------------
extern const image_t* const image_machinegun_projectile[];
extern const size_t image_machinegun_projectile_length;
//-----------------------------------------------------------------------------------------

#endif