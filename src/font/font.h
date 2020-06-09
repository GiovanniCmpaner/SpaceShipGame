#ifndef FONTE_H
#define FONTE_H

#include <stdint.h>

typedef struct {
	uint32_t code;
	uint8_t height;
	uint8_t width;
	const uint8_t data[];
} character_t;

typedef struct {
	const char* name;
    uint8_t height;
    uint8_t width;
    uint8_t character_spacing;
    uint8_t line_spacing;
    uint8_t characters_quantity;
    uint8_t first_character;
    uint8_t last_character;
	const character_t* characters[];
} font_t;

extern const font_t font7x5;
extern const font_t font9x7;
extern const font_t font14x10;
extern const font_t font20x14;

#endif