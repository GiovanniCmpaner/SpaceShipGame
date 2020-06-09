#ifndef IMAGE_SPACESHIP_H
#define IMAGE_SPACESHIP_H

#include <stdint.h>
#include <string.h>

#include "image.h"
//-----------------------------------------------------------------------------------------
typedef enum {
    SPACESHIP_IDLE    = 0,
    
	SPACESHIP_LEFT    = ( 1 << 0 ),
    SPACESHIP_RIGHT   = ( 1 << 1 ),
	SPACESHIP_UP      = ( 1 << 2 ),
	SPACESHIP_DOWN    = ( 1 << 3 ),

	SPACESHIP_WEAK    = ( 1 << 4 ),
	SPACESHIP_MEDIUM  = ( 1 << 5 ),
	SPACESHIP_STRONG  = ( 1 << 6 )
} spaceship_mode_t;
//-----------------------------------------------------------------------------------------
extern const image_t* const image_spaceships[];
extern const size_t image_spaceships_length;
//-----------------------------------------------------------------------------------------
#endif