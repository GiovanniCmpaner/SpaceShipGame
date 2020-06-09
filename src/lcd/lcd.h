#ifndef LCD_H
#define LCD_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h> 
#include <stdint.h>
#include <stdarg.h>
#include <stdarg.h>

#include "font/font.h"
#include "image/image.h"
#include "lcd/color.h"

void lcd_initialize();
void lcd_on();
void lcd_off();
void lcd_fill(uint16_t color);
void lcd_refresh();

uint16_t lcd_width();
uint16_t lcd_height();

void lcd_draw_image( int16_t x, int16_t y, const image_t* image );
void lcd_draw_image_orientation_print( const char* name, const image_t* image, image_orientation_t orientation );
void lcd_draw_pixel( int16_t x, int16_t y, color_t color);
void lcd_draw_line( int16_t x0, int16_t y0, int16_t x1, int16_t y1, color_t color );
void lcd_draw_rectangle( int16_t x0, int16_t y0, int16_t x1, int16_t y1, color_t color );
void lcd_draw_rectangle_filled( int16_t x0, int16_t y0, int16_t x1, int16_t y1, color_t color );
void lcd_draw_circle( int16_t x, int16_t y, uint16_t raio, color_t color );
void lcd_draw_circle_filled( int16_t x, int16_t y, uint16_t raio, color_t color );

void lcd_set_font( const font_t* font );
void lcd_printf(int16_t x, int16_t y, color_t color, const char * format, ...);

#endif