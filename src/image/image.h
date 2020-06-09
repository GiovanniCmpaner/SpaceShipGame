#ifndef IMAGE_H
#define IMAGE_H

#include <stdint.h>
//-----------------------------------------------------------------------------------------
typedef enum {
    IMAGE_ROTATED_0           = 0,
    IMAGE_ROTATED_90          = 1,
    IMAGE_ROTATED_180         = 2,
    IMAGE_ROTATED_270         = 4,
    IMAGE_MIRRORED_VERTICAL   = 8,
    IMAGE_MIRRORED_HORIZONTAL = 16,
    IMAGE_MIRRORED_BOTH       = IMAGE_MIRRORED_HORIZONTAL | IMAGE_MIRRORED_VERTICAL
} image_orientation_t;
//-----------------------------------------------------------------------------------------
typedef struct {
    uint16_t width;
    uint16_t height;
    uint16_t transparent_color;
    uint16_t data[];
} image_t;
//-----------------------------------------------------------------------------------------
extern const image_t image_cursor;
extern const image_t image_space;

#endif