#ifndef image_impact_shockwave_H
#define image_impact_shockwave_H

#include <stdint.h>
#include <string.h>

#include "image.h"
//-----------------------------------------------------------------------------------------
typedef enum {
    IMPACT_SHOCKWAVE
} impact_type_t;

typedef enum {
    IMPACT_SMALL,
    IMPACT_MEDIUM,
    IMPACT_BIG
} impact_size_t;
//-----------------------------------------------------------------------------------------
extern const image_t* const image_impact_shockwave[];
extern const size_t image_impact_shockwave_length;
//-----------------------------------------------------------------------------------------
#endif