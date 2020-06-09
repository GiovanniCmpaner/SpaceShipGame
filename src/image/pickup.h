#ifndef IMAGE_PICKUP_H
#define IMAGE_PICKUP_H

#include <stdint.h>
#include <string.h>

#include "image.h"
//-----------------------------------------------------------------------------------------
typedef enum {
    PICKUP_MACHINEGUN,
    PICKUP_HEART,
    PICKUP_MISSILE,
    PICKUP_MINE,
    PICKUP_SHIELD
} pickup_type_t;
//-----------------------------------------------------------------------------------------
extern const image_t* const image_pickups[];
extern const size_t image_pickups_length;
//-----------------------------------------------------------------------------------------
#endif