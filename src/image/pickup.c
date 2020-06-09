#include <stdint.h>
#include <string.h>

#include "image.h"
#include "pickup.h"
//-----------------------------------------------------------------------------------------
static const image_t image_pickup_heart = {
    .width = 24,
    .height = 22,
    .transparent_color = 0x1FF8,
    .data = {
        0x1FF8, 0x1FF8, 0x1FF8, 0x1FF8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2421, 0x1FF8, 0x1FF8, 0x1FF8, 0x1FF8, 
        0x1FF8, 0x1FF8, 0x0000, 0x0000, 0xFFFF, 0xB2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0x2FA5, 0x0963, 0x0000, 0x0000, 0x1FF8, 0x1FF8, 
        0x1FF8, 0x0000, 0xFFFF, 0xFFFF, 0xF3BD, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0642, 0x91B5, 0x8973, 0x696B, 0x0100, 0x1FF8, 
        0x1FF8, 0x0000, 0xFFFF, 0xD2BD, 0x2000, 0x771B, 0x7613, 0x7613, 0x7613, 0x7613, 0x7713, 0x7713, 0x7613, 0x7713, 0x7713, 0x7713, 0x7613, 0x7613, 0x4E2A, 0xC218, 0xF3BD, 0x696B, 0x0000, 0x1FF8, 
        0x2000, 0xFFFF, 0xD3BD, 0x0000, 0x760B, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0xD022, 0x0000, 0xF2BD, 0x6B73, 0x2108, 
        0x0000, 0xFFFF, 0xF3BD, 0x0000, 0x7613, 0x7713, 0x7713, 0xFFFF, 0xFFFF, 0xFFFF, 0x0842, 0x7713, 0x7713, 0xFFFF, 0xFFFF, 0xFFFF, 0x0842, 0x7713, 0x7713, 0x7613, 0x0100, 0xF3BD, 0x8973, 0x0000, 
        0x0000, 0xFFFF, 0xF3BD, 0x0000, 0x7613, 0x7713, 0xFFFF, 0x00F8, 0x00F8, 0x00F8, 0xFFFF, 0x0842, 0xFFFF, 0x00F8, 0x00F8, 0x0088, 0xFFFF, 0x0842, 0x7713, 0x7613, 0x0000, 0xF3BD, 0x6973, 0x0000, 
        0x0000, 0xFFFF, 0xF3BD, 0x0000, 0x7613, 0xFFFF, 0x00F8, 0xFFFF, 0xFFFF, 0x00F8, 0x00F8, 0xFFFF, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x0090, 0xFFFF, 0x0842, 0x7613, 0x0000, 0xF3BD, 0x6973, 0x0000, 
        0x0000, 0xFFFF, 0xF3BD, 0x0000, 0x7613, 0xFFFF, 0x00F8, 0xFFFF, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x0088, 0xFFFF, 0x0842, 0x7613, 0x0000, 0xF3BD, 0x6A73, 0x0000, 
        0x0000, 0xFFFF, 0xF3BD, 0x0000, 0x960B, 0xFFFF, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x0088, 0xFFFF, 0x0842, 0x7613, 0x0000, 0xF3BD, 0x8973, 0x0000, 
        0x1FF8, 0x0000, 0x0000, 0x0000, 0x0300, 0xFFFF, 0x00F8, 0xFFFF, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x0090, 0xFFFF, 0x0300, 0x0300, 0x0000, 0x0000, 0x0000, 0x1FF8, 
        0x1FF8, 0x0000, 0x0000, 0x0000, 0x0300, 0x0300, 0xFFFF, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x0078, 0xFFFF, 0x0300, 0x0300, 0x0300, 0x0000, 0x0000, 0x0000, 0x1FF8, 
        0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x970B, 0x7713, 0xFFFF, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x0088, 0xFFFF, 0x0842, 0x7713, 0xD022, 0x0000, 0xFFFF, 0xD2BD, 0x0000, 
        0x0000, 0xFFFF, 0xF2B5, 0x0000, 0x760B, 0x7713, 0x7713, 0xFFFF, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x0080, 0xFFFF, 0x0842, 0x7713, 0x7713, 0xD122, 0x0000, 0xD2C5, 0x8973, 0x0000, 
        0x0000, 0xFFFF, 0xD2BD, 0x0000, 0x960B, 0x7713, 0x7713, 0x7713, 0xFFFF, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x0080, 0xFFFF, 0x0842, 0x7713, 0x7713, 0x7713, 0xD122, 0x0100, 0xF3BD, 0x6973, 0x0000, 
        0x0000, 0xFFFF, 0xD3BD, 0x0000, 0x6800, 0x7713, 0x7713, 0x7713, 0x7713, 0xFFFF, 0x00F8, 0x00F8, 0x0080, 0xFFFF, 0x0842, 0x7713, 0x7713, 0x7713, 0x7713, 0x4500, 0x0000, 0xF3BD, 0x6973, 0x0000, 
        0x0000, 0xFFFF, 0xD2BD, 0x0000, 0x0600, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0xFFFF, 0x0090, 0xFFFF, 0x0842, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x2300, 0x0000, 0xD3BD, 0x8A73, 0x0000, 
        0x0000, 0xFFFF, 0x92B5, 0x0000, 0x0500, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0xFFFF, 0x0842, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x2200, 0x0000, 0xD3BD, 0xAA73, 0x2000, 
        0x1FF8, 0x0000, 0xFFFF, 0xD2B5, 0x0000, 0x961B, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x2E0A, 0xC118, 0xF2BD, 0x696B, 0x0000, 0x1FF8, 
        0x1FF8, 0x0000, 0xFFFF, 0xFFFF, 0xD3BD, 0x0008, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0642, 0x71AD, 0x8973, 0x8973, 0x0000, 0x1FF8, 
        0x1FF8, 0x1FF8, 0x0000, 0x0000, 0xFFFF, 0xD2B5, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0x10A5, 0x2A63, 0x0000, 0x0000, 0x1FF8, 0x1FF8, 
        0x1FF8, 0x1FF8, 0x1FF8, 0x1FF8, 0x2000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2529, 0x1FF8, 0x1FF8, 0x1FF8, 0x1FF8 
    }
};
//-----------------------------------------------------------------------------------------
static const image_t image_pickup_machinegun = {
    .width = 24,
    .height = 22,
    .transparent_color = 0x1FF8,
    .data = {
        0x1FF8, 0x1FF8, 0x1FF8, 0x1FF8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2421, 0x1FF8, 0x1FF8, 0x1FF8, 0x1FF8, 
        0x1FF8, 0x1FF8, 0x0000, 0x0000, 0xFFFF, 0xB2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0x2FA5, 0x0963, 0x0000, 0x0000, 0x1FF8, 0x1FF8, 
        0x1FF8, 0x0000, 0xFFFF, 0xFFFF, 0xF3BD, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0642, 0x91B5, 0x8973, 0x696B, 0x0100, 0x1FF8, 
        0x1FF8, 0x0000, 0xFFFF, 0xD2BD, 0x2000, 0x771B, 0x7613, 0x7613, 0x7613, 0x7613, 0x7713, 0x7713, 0x7613, 0x7713, 0x7713, 0x7713, 0x7613, 0x7613, 0x4E2A, 0xC218, 0xF3BD, 0x696B, 0x0000, 0x1FF8, 
        0x2000, 0xFFFF, 0xD3BD, 0x0000, 0x760B, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0xD022, 0x0000, 0xF2BD, 0x6B73, 0x2108, 
        0x0000, 0xFFFF, 0xF3BD, 0x0000, 0x7613, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7613, 0x0100, 0xF3BD, 0x8973, 0x0000, 
        0x0000, 0xFFFF, 0xF3BD, 0x0000, 0x7613, 0x7713, 0x7713, 0xE0FF, 0xE0FF, 0x0042, 0x7713, 0xE0FF, 0xE0FF, 0x0042, 0x7713, 0xE0FF, 0xE0FF, 0x0042, 0x7713, 0x7613, 0x0000, 0xF3BD, 0x6973, 0x0000, 
        0x0000, 0xFFFF, 0xF3BD, 0x0000, 0x7613, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7613, 0x0000, 0xF3BD, 0x6973, 0x0000, 
        0x0000, 0xFFFF, 0xF3BD, 0x0000, 0x7613, 0x7713, 0x7713, 0xE0FF, 0xE0FF, 0x0042, 0x7713, 0xE0FF, 0xE0FF, 0x0042, 0x7713, 0xE0FF, 0xE0FF, 0x0042, 0x7613, 0x7613, 0x0000, 0xF3BD, 0x6A73, 0x0000, 
        0x0000, 0xFFFF, 0xF3BD, 0x0000, 0x960B, 0x7713, 0x7713, 0xE0FF, 0xE0FF, 0x0042, 0x7713, 0xE0FF, 0xE0FF, 0x0042, 0x7713, 0xE0FF, 0xE0FF, 0x0042, 0x7613, 0x7613, 0x0000, 0xF3BD, 0x8973, 0x0000, 
        0x1FF8, 0x0000, 0x0000, 0x0000, 0x0300, 0x0300, 0x0300, 0xE0FF, 0xE0FF, 0x0300, 0x0300, 0xE0FF, 0xE0FF, 0x0300, 0x0300, 0xE0FF, 0xE0FF, 0x0300, 0x0300, 0x0300, 0x0000, 0x0000, 0x0000, 0x1FF8, 
        0x1FF8, 0x0000, 0x0000, 0x0000, 0x0300, 0x0300, 0x0300, 0xE0FF, 0xE0FF, 0x0300, 0x0300, 0xE0FF, 0xE0FF, 0x0300, 0x0300, 0xE0FF, 0xE0FF, 0x0300, 0x0300, 0x0300, 0x0000, 0x0000, 0x0000, 0x1FF8, 
        0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x970B, 0x7713, 0x7713, 0xE0FF, 0xE0FF, 0x0042, 0x7713, 0xE0FF, 0xE0FF, 0x0042, 0x7713, 0xE0FF, 0xE0FF, 0x0042, 0x7713, 0xD022, 0x0000, 0xFFFF, 0xD2BD, 0x0000, 
        0x0000, 0xFFFF, 0xF2B5, 0x0000, 0x760B, 0x7713, 0x7713, 0xE0FF, 0xE0FF, 0x0042, 0x7713, 0xE0FF, 0xE0FF, 0x0042, 0x7713, 0xE0FF, 0xE0FF, 0x0042, 0x7713, 0xD122, 0x0000, 0xD2C5, 0x8973, 0x0000, 
        0x0000, 0xFFFF, 0xD2BD, 0x0000, 0x960B, 0x7713, 0x7713, 0xE0FF, 0xE0FF, 0x0042, 0x7713, 0xE0FF, 0xE0FF, 0x0042, 0x7713, 0xE0FF, 0xE0FF, 0x0042, 0x7713, 0xD122, 0x0100, 0xF3BD, 0x6973, 0x0000, 
        0x0000, 0xFFFF, 0xD3BD, 0x0000, 0x6800, 0x7713, 0x7713, 0xE0FF, 0xE0FF, 0x0042, 0x7713, 0xE0FF, 0xE0FF, 0x0042, 0x7713, 0xE0FF, 0xE0FF, 0x0042, 0x7713, 0x4500, 0x0000, 0xF3BD, 0x6973, 0x0000, 
        0x0000, 0xFFFF, 0xD2BD, 0x0000, 0x0600, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x2300, 0x0000, 0xD3BD, 0x8A73, 0x0000, 
        0x0000, 0xFFFF, 0x92B5, 0x0000, 0x0500, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x2200, 0x0000, 0xD3BD, 0xAA73, 0x2000, 
        0x1FF8, 0x0000, 0xFFFF, 0xD2B5, 0x0000, 0x961B, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x2E0A, 0xC118, 0xF2BD, 0x696B, 0x0000, 0x1FF8, 
        0x1FF8, 0x0000, 0xFFFF, 0xFFFF, 0xD3BD, 0x0008, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0642, 0x71AD, 0x8973, 0x8973, 0x0000, 0x1FF8, 
        0x1FF8, 0x1FF8, 0x0000, 0x0000, 0xFFFF, 0xD2B5, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0x10A5, 0x2A63, 0x0000, 0x0000, 0x1FF8, 0x1FF8, 
        0x1FF8, 0x1FF8, 0x1FF8, 0x1FF8, 0x2000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2529, 0x1FF8, 0x1FF8, 0x1FF8, 0x1FF8 
    }
};
//-----------------------------------------------------------------------------------------
static const image_t image_pickup_mine = {
    .width = 24,
    .height = 22,
    .transparent_color = 0x1FF8,
    .data = {
        0x1FF8, 0x1FF8, 0x1FF8, 0x1FF8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2421, 0x1FF8, 0x1FF8, 0x1FF8, 0x1FF8, 
        0x1FF8, 0x1FF8, 0x0000, 0x0000, 0xFFFF, 0xB2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0x2FA5, 0x0963, 0x0000, 0x0000, 0x1FF8, 0x1FF8, 
        0x1FF8, 0x0000, 0xFFFF, 0xFFFF, 0xF3BD, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0642, 0x91B5, 0x8973, 0x696B, 0x0100, 0x1FF8, 
        0x1FF8, 0x0000, 0xFFFF, 0xD2BD, 0x2000, 0x771B, 0x7613, 0x7613, 0x7613, 0x7613, 0x7713, 0x7713, 0x7613, 0x7713, 0x7713, 0x7713, 0x7613, 0x7613, 0x4E2A, 0xC218, 0xF3BD, 0x696B, 0x0000, 0x1FF8, 
        0x2000, 0xFFFF, 0xD3BD, 0x0000, 0x760B, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0xD022, 0x0000, 0xF2BD, 0x6B73, 0x2108, 
        0x0000, 0xFFFF, 0xF3BD, 0x0000, 0x7613, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7613, 0x0100, 0xF3BD, 0x8973, 0x0000, 
        0x0000, 0xFFFF, 0xF3BD, 0x0000, 0x7613, 0x7713, 0x7713, 0x00F8, 0x0040, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x00F8, 0x0040, 0x7713, 0x7613, 0x0000, 0xF3BD, 0x6973, 0x0000, 
        0x0000, 0xFFFF, 0xF3BD, 0x0000, 0x7613, 0x7713, 0x7713, 0x7713, 0x00F8, 0x0040, 0x7713, 0x00F8, 0x00F8, 0x0040, 0x7713, 0x00F8, 0x0040, 0x7713, 0x7713, 0x7613, 0x0000, 0xF3BD, 0x6973, 0x0000, 
        0x0000, 0xFFFF, 0xF3BD, 0x0000, 0x7613, 0x7713, 0x7713, 0x7713, 0x7713, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x0040, 0x7713, 0x7713, 0x7613, 0x7613, 0x0000, 0xF3BD, 0x6A73, 0x0000, 
        0x0000, 0xFFFF, 0xF3BD, 0x0000, 0x960B, 0x7713, 0x7713, 0x7713, 0x7713, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x0040, 0x7713, 0x7713, 0x7613, 0x7613, 0x0000, 0xF3BD, 0x8973, 0x0000, 
        0x1FF8, 0x0000, 0x0000, 0x0000, 0x0300, 0x0300, 0x0300, 0x0300, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x0300, 0x0300, 0x0300, 0x0300, 0x0000, 0x0000, 0x0000, 0x1FF8, 
        0x1FF8, 0x0000, 0x0000, 0x0000, 0x0300, 0x0300, 0x0300, 0x0300, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x0300, 0x0300, 0x0300, 0x0300, 0x0000, 0x0000, 0x0000, 0x1FF8, 
        0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x970B, 0x7713, 0x7713, 0x7713, 0x7713, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x0040, 0x7713, 0x7713, 0x7713, 0xD022, 0x0000, 0xFFFF, 0xD2BD, 0x0000, 
        0x0000, 0xFFFF, 0xF2B5, 0x0000, 0x760B, 0x7713, 0x7713, 0x7713, 0x7713, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x00F8, 0x0040, 0x7713, 0x7713, 0x7713, 0xD122, 0x0000, 0xD2C5, 0x8973, 0x0000, 
        0x0000, 0xFFFF, 0xD2BD, 0x0000, 0x960B, 0x7713, 0x7713, 0x7713, 0x00F8, 0x0040, 0x7713, 0x00F8, 0x00F8, 0x0040, 0x7713, 0x00F8, 0x0040, 0x7713, 0x7713, 0xD122, 0x0100, 0xF3BD, 0x6973, 0x0000, 
        0x0000, 0xFFFF, 0xD3BD, 0x0000, 0x6800, 0x7713, 0x7713, 0x00F8, 0x0040, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x00F8, 0x0040, 0x7713, 0x4500, 0x0000, 0xF3BD, 0x6973, 0x0000, 
        0x0000, 0xFFFF, 0xD2BD, 0x0000, 0x0600, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x2300, 0x0000, 0xD3BD, 0x8A73, 0x0000, 
        0x0000, 0xFFFF, 0x92B5, 0x0000, 0x0500, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x2200, 0x0000, 0xD3BD, 0xAA73, 0x2000, 
        0x1FF8, 0x0000, 0xFFFF, 0xD2B5, 0x0000, 0x961B, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x2E0A, 0xC118, 0xF2BD, 0x696B, 0x0000, 0x1FF8, 
        0x1FF8, 0x0000, 0xFFFF, 0xFFFF, 0xD3BD, 0x0008, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0642, 0x71AD, 0x8973, 0x8973, 0x0000, 0x1FF8, 
        0x1FF8, 0x1FF8, 0x0000, 0x0000, 0xFFFF, 0xD2B5, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0x10A5, 0x2A63, 0x0000, 0x0000, 0x1FF8, 0x1FF8, 
        0x1FF8, 0x1FF8, 0x1FF8, 0x1FF8, 0x2000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2529, 0x1FF8, 0x1FF8, 0x1FF8, 0x1FF8 
    }
};
//-----------------------------------------------------------------------------------------
static const image_t image_pickup_missile = {
    .width = 24,
    .height = 22,
    .transparent_color = 0x1FF8,
    .data = {
        0x1FF8, 0x1FF8, 0x1FF8, 0x1FF8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2421, 0x1FF8, 0x1FF8, 0x1FF8, 0x1FF8, 
        0x1FF8, 0x1FF8, 0x0000, 0x0000, 0xFFFF, 0xB2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0x2FA5, 0x0963, 0x0000, 0x0000, 0x1FF8, 0x1FF8, 
        0x1FF8, 0x0000, 0xFFFF, 0xFFFF, 0xF3BD, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0642, 0x91B5, 0x8973, 0x696B, 0x0100, 0x1FF8, 
        0x1FF8, 0x0000, 0xFFFF, 0xD2BD, 0x2000, 0x771B, 0x7613, 0x7613, 0x7613, 0x7613, 0x7713, 0x7713, 0x7613, 0x7713, 0x7713, 0x7713, 0x7613, 0x7613, 0x4E2A, 0xC218, 0xF3BD, 0x696B, 0x0000, 0x1FF8, 
        0x2000, 0xFFFF, 0xD3BD, 0x0000, 0x760B, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0xD022, 0x0000, 0xF2BD, 0x6B73, 0x2108, 
        0x0000, 0xFFFF, 0xF3BD, 0x0000, 0x7613, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0xE007, 0xE007, 0x0002, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7613, 0x0100, 0xF3BD, 0x8973, 0x0000, 
        0x0000, 0xFFFF, 0xF3BD, 0x0000, 0x7613, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0xE007, 0xE007, 0xE007, 0xE007, 0x0002, 0x7713, 0x7713, 0x7713, 0x7713, 0x7613, 0x0000, 0xF3BD, 0x6973, 0x0000, 
        0x0000, 0xFFFF, 0xF3BD, 0x0000, 0x7613, 0x7713, 0x7713, 0x7713, 0x7713, 0xE007, 0xE007, 0xE007, 0xE007, 0xE007, 0xE007, 0x0002, 0x7713, 0x7713, 0x7713, 0x7613, 0x0000, 0xF3BD, 0x6973, 0x0000, 
        0x0000, 0xFFFF, 0xF3BD, 0x0000, 0x7613, 0x7713, 0x7713, 0x7713, 0x7713, 0xE007, 0xE007, 0xE007, 0xE007, 0xE007, 0xE007, 0x0002, 0x7713, 0x7713, 0x7613, 0x7613, 0x0000, 0xF3BD, 0x6A73, 0x0000, 
        0x0000, 0xFFFF, 0xF3BD, 0x0000, 0x960B, 0x7713, 0x7713, 0x7713, 0x7713, 0xE007, 0xE007, 0xE007, 0xE007, 0xE007, 0xE007, 0x0002, 0x7713, 0x7713, 0x7613, 0x7613, 0x0000, 0xF3BD, 0x8973, 0x0000, 
        0x1FF8, 0x0000, 0x0000, 0x0000, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0xE007, 0xE007, 0xE007, 0xE007, 0xE007, 0xE007, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0000, 0x0000, 0x0000, 0x1FF8, 
        0x1FF8, 0x0000, 0x0000, 0x0000, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0xE007, 0xE007, 0xE007, 0xE007, 0xE007, 0xE007, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0000, 0x0000, 0x0000, 0x1FF8, 
        0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x970B, 0x7713, 0x7713, 0x7713, 0x7713, 0xE007, 0xE007, 0xE007, 0xE007, 0xE007, 0xE007, 0x0002, 0x7713, 0x7713, 0x7713, 0xD022, 0x0000, 0xFFFF, 0xD2BD, 0x0000, 
        0x0000, 0xFFFF, 0xF2B5, 0x0000, 0x760B, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0xE007, 0xE007, 0xE007, 0xE007, 0x0002, 0x7713, 0x7713, 0x7713, 0x7713, 0xD122, 0x0000, 0xD2C5, 0x8973, 0x0000, 
        0x0000, 0xFFFF, 0xD2BD, 0x0000, 0x960B, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0xE007, 0xE007, 0x0002, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0xD122, 0x0100, 0xF3BD, 0x6973, 0x0000, 
        0x0000, 0xFFFF, 0xD3BD, 0x0000, 0x6800, 0x7713, 0x7713, 0x7713, 0x7713, 0xE007, 0xE007, 0xE007, 0xE007, 0xE007, 0xE007, 0x0002, 0x7713, 0x7713, 0x7713, 0x4500, 0x0000, 0xF3BD, 0x6973, 0x0000, 
        0x0000, 0xFFFF, 0xD2BD, 0x0000, 0x0600, 0x7713, 0x7713, 0x7713, 0x7713, 0xE007, 0xE007, 0xE007, 0xE007, 0xE007, 0xE007, 0x0002, 0x7713, 0x7713, 0x7713, 0x2300, 0x0000, 0xD3BD, 0x8A73, 0x0000, 
        0x0000, 0xFFFF, 0x92B5, 0x0000, 0x0500, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x2200, 0x0000, 0xD3BD, 0xAA73, 0x2000, 
        0x1FF8, 0x0000, 0xFFFF, 0xD2B5, 0x0000, 0x961B, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x2E0A, 0xC118, 0xF2BD, 0x696B, 0x0000, 0x1FF8, 
        0x1FF8, 0x0000, 0xFFFF, 0xFFFF, 0xD3BD, 0x0008, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0642, 0x71AD, 0x8973, 0x8973, 0x0000, 0x1FF8, 
        0x1FF8, 0x1FF8, 0x0000, 0x0000, 0xFFFF, 0xD2B5, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0x10A5, 0x2A63, 0x0000, 0x0000, 0x1FF8, 0x1FF8, 
        0x1FF8, 0x1FF8, 0x1FF8, 0x1FF8, 0x2000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2529, 0x1FF8, 0x1FF8, 0x1FF8, 0x1FF8 
    }
};
//-----------------------------------------------------------------------------------------
static const image_t image_pickup_shield = {
    .width = 24,
    .height = 22,
    .transparent_color = 0x1FF8,
    .data = {
        0x1FF8, 0x1FF8, 0x1FF8, 0x1FF8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2421, 0x1FF8, 0x1FF8, 0x1FF8, 0x1FF8, 
        0x1FF8, 0x1FF8, 0x0000, 0x0000, 0xFFFF, 0xB2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0x2FA5, 0x0963, 0x0000, 0x0000, 0x1FF8, 0x1FF8, 
        0x1FF8, 0x0000, 0xFFFF, 0xFFFF, 0xF3BD, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0642, 0x91B5, 0x8973, 0x696B, 0x0100, 0x1FF8, 
        0x1FF8, 0x0000, 0xFFFF, 0xD2BD, 0x2000, 0x771B, 0x7613, 0x7613, 0x7613, 0x7613, 0x7713, 0x7713, 0x7613, 0x7713, 0x7713, 0x7713, 0x7613, 0x7613, 0x4E2A, 0xC218, 0xF3BD, 0x696B, 0x0000, 0x1FF8, 
        0x2000, 0xFFFF, 0xD3BD, 0x0000, 0x760B, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0xD022, 0x0000, 0xF2BD, 0x6B73, 0x2108, 
        0x0000, 0xFFFF, 0xF3BD, 0x0000, 0x7613, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0xFF07, 0xFF07, 0x0802, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7613, 0x0100, 0xF3BD, 0x8973, 0x0000, 
        0x0000, 0xFFFF, 0xF3BD, 0x0000, 0x7613, 0x7713, 0x7713, 0xFF07, 0x0802, 0x7713, 0x7713, 0xFF07, 0xFF07, 0x0802, 0x7713, 0x7713, 0xFF07, 0x0802, 0x7713, 0x7613, 0x0000, 0xF3BD, 0x6973, 0x0000, 
        0x0000, 0xFFFF, 0xF3BD, 0x0000, 0x7613, 0x7713, 0x7713, 0xFF07, 0xFF07, 0x0802, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0x0802, 0xFF07, 0xFF07, 0x0802, 0x7713, 0x7613, 0x0000, 0xF3BD, 0x6973, 0x0000, 
        0x0000, 0xFFFF, 0xF3BD, 0x0000, 0x7613, 0x7713, 0x7713, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0x0802, 0x7613, 0x7613, 0x0000, 0xF3BD, 0x6A73, 0x0000, 
        0x0000, 0xFFFF, 0xF3BD, 0x0000, 0x960B, 0x7713, 0x7713, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0x0802, 0x7613, 0x7613, 0x0000, 0xF3BD, 0x8973, 0x0000, 
        0x1FF8, 0x0000, 0x0000, 0x0000, 0x0300, 0x0300, 0x0300, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0x0300, 0x0300, 0x0300, 0x0000, 0x0000, 0x0000, 0x1FF8, 
        0x1FF8, 0x0000, 0x0000, 0x0000, 0x0300, 0x0300, 0x0300, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0x0300, 0x0300, 0x0300, 0x0000, 0x0000, 0x0000, 0x1FF8, 
        0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x970B, 0x7713, 0x7713, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0x0802, 0x7713, 0xD022, 0x0000, 0xFFFF, 0xD2BD, 0x0000, 
        0x0000, 0xFFFF, 0xF2B5, 0x0000, 0x760B, 0x7713, 0x7713, 0x7713, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0x0802, 0x7713, 0x7713, 0xD122, 0x0000, 0xD2C5, 0x8973, 0x0000, 
        0x0000, 0xFFFF, 0xD2BD, 0x0000, 0x960B, 0x7713, 0x7713, 0x7713, 0x7713, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0x0802, 0x7713, 0x7713, 0x7713, 0xD122, 0x0100, 0xF3BD, 0x6973, 0x0000, 
        0x0000, 0xFFFF, 0xD3BD, 0x0000, 0x6800, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0xFF07, 0xFF07, 0xFF07, 0xFF07, 0x0802, 0x7713, 0x7713, 0x7713, 0x7713, 0x4500, 0x0000, 0xF3BD, 0x6973, 0x0000, 
        0x0000, 0xFFFF, 0xD2BD, 0x0000, 0x0600, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0xFF07, 0xFF07, 0x0802, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x2300, 0x0000, 0xD3BD, 0x8A73, 0x0000, 
        0x0000, 0xFFFF, 0x92B5, 0x0000, 0x0500, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x7713, 0x2200, 0x0000, 0xD3BD, 0xAA73, 0x2000, 
        0x1FF8, 0x0000, 0xFFFF, 0xD2B5, 0x0000, 0x961B, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x9713, 0x2E0A, 0xC118, 0xF2BD, 0x696B, 0x0000, 0x1FF8, 
        0x1FF8, 0x0000, 0xFFFF, 0xFFFF, 0xD3BD, 0x0008, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0642, 0x71AD, 0x8973, 0x8973, 0x0000, 0x1FF8, 
        0x1FF8, 0x1FF8, 0x0000, 0x0000, 0xFFFF, 0xD2B5, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0xD2BD, 0x10A5, 0x2A63, 0x0000, 0x0000, 0x1FF8, 0x1FF8, 
        0x1FF8, 0x1FF8, 0x1FF8, 0x1FF8, 0x2000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2529, 0x1FF8, 0x1FF8, 0x1FF8, 0x1FF8 
    }
};
//-----------------------------------------------------------------------------------------
const image_t* const image_pickups[] = {
    [PICKUP_HEART]       = &image_pickup_heart,
    [PICKUP_MISSILE]     = &image_pickup_missile,
    [PICKUP_MACHINEGUN]  = &image_pickup_machinegun,
    [PICKUP_MINE]        = &image_pickup_mine,
    [PICKUP_SHIELD]      = &image_pickup_shield
};

const size_t image_pickups_length = sizeof(image_pickups)/sizeof(*image_pickups);
//-----------------------------------------------------------------------------------------