#ifndef IMAGE_INFO_H
#define IMAGE_INFO_H

#include <stdint.h>
#include <string.h>

#include "image.h"
//-----------------------------------------------------------------------------------------

typedef enum {
    AMMUNITION_MACHINEGUN,
    AMMUNITION_MISSILE,
    AMMUNITION_MINE,
    AMMUNITION_SHIELD
} ammunition_type_t;

//-----------------------------------------------------------------------------------------
extern const image_t* const image_ammunitions[];
extern const size_t image_ammunitions_length;

extern const image_t* const image_hearts[];
extern const size_t image_hearts_length;

extern const image_t image_infinity;
//-----------------------------------------------------------------------------------------
#endif