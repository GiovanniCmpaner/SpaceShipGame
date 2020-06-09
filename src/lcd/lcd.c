#include <stdint.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/spi_master.h"
#include "driver/spi_common.h"
#include "esp_err.h"
#include "esp_log.h"

#include "lcd.h"
#include "lcd_spi.h"
//-----------------------------------------------------------------------------------------
static const char* tag = "lcd";
static uint16_t frame[LCD_HEIGHT][LCD_WIDTH] = {};
//-----------------------------------------------------------------------------------------
void lcd_initialize(){
    ESP_LOGI(tag,"initialize");
    
    lcd_spi_init();
    lcd_on();
}
//-----------------------------------------------------------------------------------------
void lcd_refresh(){
    const lcd_cmd_t cmd = {
        .length = sizeof(frame),
        .ptr = (uint8_t*)frame
    };
    lcd_spi_write(&cmd);
}
//-----------------------------------------------------------------------------------------
void lcd_fill(uint16_t color){
    uint16_t* frame_ptr = frame;
    
    uint32_t n = LCD_WIDTH * LCD_HEIGHT;
    while(n--){
        *frame_ptr++ = color;
    }
}
//-----------------------------------------------------------------------------------------
void lcd_on(){
    ESP_LOGI(tag,"on");

    lcd_spi_on();
    
    lcd_fill(COLOR_BLACK);
    lcd_refresh();
}
//-----------------------------------------------------------------------------------------
void lcd_off(){
    ESP_LOGI(tag,"off");
    
    lcd_spi_off();
}
//-----------------------------------------------------------------------------------------
void lcd_draw_image( int16_t x, int16_t y, const image_t* image ){

    if( x >= LCD_WIDTH || y >= LCD_HEIGHT ){
        return;
    }

    int16_t i = 0;
    if( x < 0 ){
        i += -x;
        x = 0;
    }
    
    int16_t j = 0;
    if( y < 0 ){
        j += -y;
        y = 0;
    }

    int16_t w = image->width - i;
    if( w > LCD_WIDTH - x ){
        w = LCD_WIDTH - x;
    }
    
    int16_t h = image->height - j;
    if( h > LCD_HEIGHT - y ){
        h = LCD_HEIGHT - y;
    }
    
    if( w <= 0 || h <= 0 ){
        return;
    }

    while(h--){
        
        uint16_t* frame_ptr = &frame[y++][x];
        const uint16_t* image_ptr = &image->data[j++ * image->width + i];
    
        const int16_t w0 = w;
        while(w--){
            
            const uint16_t color = *image_ptr++;
            if( color != image->transparent_color ){
                *frame_ptr = color;
            }
            frame_ptr++;
        }
        w = w0;
    }
}
//-----------------------------------------------------------------------------------------
void lcd_draw_image_orientation_print( const char* name, const image_t* image, image_orientation_t orientation ){
    printf("static const image_t image_%s",name);
    if( orientation & IMAGE_ROTATED_270 ){
        printf("_rotated270");
    }
    else if( orientation & IMAGE_ROTATED_180 ){
        printf("_rotated180");
    }         
    else if( orientation & IMAGE_ROTATED_90 ){
        printf("_rotated90");
    }
    else {
        printf("_rotated0");
    }
    if( orientation & ( IMAGE_MIRRORED_HORIZONTAL | IMAGE_MIRRORED_VERTICAL ) ){
        if( orientation & IMAGE_MIRRORED_HORIZONTAL && orientation & IMAGE_MIRRORED_VERTICAL ){
            printf("_both");
        }
        else {
            if( orientation & IMAGE_MIRRORED_HORIZONTAL ){
                printf("_horizontal");
            }
            if( orientation & IMAGE_MIRRORED_VERTICAL ){
                printf("_vertical");
            }
        }
    }
    printf(" = {\r\n");
    
    int16_t rw = ( ( orientation & ( IMAGE_ROTATED_270 | IMAGE_ROTATED_90 ) ) ? image->height : image->width );
    int16_t rh = ( ( orientation & ( IMAGE_ROTATED_270 | IMAGE_ROTATED_90 ) ) ? image->width : image->height );
    
    printf("    .width = %u,\r\n", rw  );
    printf("    .height = %u,\r\n", rh );
    printf("    .transparent_color = 0x1FF8,\r\n");
    printf("    .data = {\r\n");
    
    for( int16_t j = 0; j < rh; j++ ){
        printf("        ");
        for( int16_t i = 0; i < rw; i++ ){
            int16_t rj, ri;
            if( orientation & IMAGE_ROTATED_270 ){
                ri = ( orientation & IMAGE_MIRRORED_VERTICAL ? rh - j - 1 : j );
                rj = ( orientation & IMAGE_MIRRORED_HORIZONTAL ? i : rw - i - 1 );
            }
            else if( orientation & IMAGE_ROTATED_180 ){
                ri = ( orientation & IMAGE_MIRRORED_HORIZONTAL ? i : rw - i - 1 );
                rj = ( orientation & IMAGE_MIRRORED_VERTICAL ? j : rh - j - 1 );
            }         
            else if( orientation & IMAGE_ROTATED_90 ){
                ri = ( orientation & IMAGE_MIRRORED_VERTICAL ? j : rh - j - 1 );
                rj = ( orientation & IMAGE_MIRRORED_HORIZONTAL ? rw - i - 1 : i );
            }
            else {
                ri = ( orientation & IMAGE_MIRRORED_HORIZONTAL ? rw - i - 1 : i );
                rj = ( orientation & IMAGE_MIRRORED_VERTICAL ? rh - j - 1 : j );
            }
            printf("0x%04X, ", image->data[rj * image->width + ri]);
        }
        printf("\r\n");
    }
    printf("    }\r\n");
    printf("};\r\n");
}
//-----------------------------------------------------------------------------------------
uint16_t lcd_width(){
    return LCD_WIDTH;
}
//-----------------------------------------------------------------------------------------
uint16_t lcd_height(){
    return LCD_HEIGHT;
}
//-----------------------------------------------------------------------------------------
void lcd_draw_pixel(int16_t x, int16_t y, color_t color) {
    if( x >= 0 && x < LCD_WIDTH && y >= 0 && y < LCD_HEIGHT ){
        frame[y][x] = color;
    }
}
//-----------------------------------------------------------------------------------------
void lcd_draw_line(int16_t x0, int16_t y0, int16_t x1, int16_t y1, color_t color) {
    const int16_t dx = abs(x1 - x0);
    const int16_t sx = x0 < x1 ? 1 : -1;
    const int16_t dy = -abs(y1 - y0);
    const int16_t sy = y0 < y1 ? 1 : -1;
    int16_t err = dx + dy;
    
    while (1) {
        lcd_draw_pixel(x0, y0, color);
        
        if (x0 == x1 && y0 == y1){
            break;
        }
        
        const int16_t e2 = 2 * err;
        if (e2 >= dy){
            err += dy; 
            x0 += sx; 
        }
        if (e2 <= dx){
            err += dx; 
            y0 += sy; 
        }
    }
}
//-----------------------------------------------------------------------------------------
void lcd_draw_rectangle( int16_t x0, int16_t y0, int16_t x1, int16_t y1, color_t color ){
    lcd_draw_line(x0, y0, x1, y0, color);
    lcd_draw_line(x0, y1, x1, y1, color);
    lcd_draw_line(x0, y0, x0, y1, color);
    lcd_draw_line(x1, y0, x1, y1, color);
}
//-----------------------------------------------------------------------------------------
void lcd_draw_rectangle_filled( int16_t x0, int16_t y0, int16_t x1, int16_t y1, color_t color ){
    const int16_t sx = x0 < x1 ? 1 : -1;
    
    while(1){
        lcd_draw_line(x0, y0, x0, y1, color );
        
        if(x0 == x1){
            break;
        }
        x0 += sx; 
    }
}
//-----------------------------------------------------------------------------------------
void lcd_draw_circle( int16_t x, int16_t y, uint16_t raio, color_t color ){
    int16_t sx = raio;
    int16_t sy = 0;
    int16_t err = 0;
    while (sx >= sy){
        lcd_draw_pixel(x + sx, y + sy, color);
        lcd_draw_pixel(x + sy, y + sx, color);
        lcd_draw_pixel(x - sy, y + sx, color);
        lcd_draw_pixel(x - sx, y + sy, color);
        lcd_draw_pixel(x - sx, y - sy, color);
        lcd_draw_pixel(x - sy, y - sx, color);
        lcd_draw_pixel(x + sy, y - sx, color);
        lcd_draw_pixel(x + sx, y - sy, color);

        sy += 1;
        if (err <= 0){
            err += 2 * sy + 1;
        }
        if (err > 0){
            sx -= 1;
            err -= 2 * sx + 1;
        }
    }
}
//-----------------------------------------------------------------------------------------
void lcd_draw_circle_filled( int16_t x, int16_t y, uint16_t raio, color_t color ){
    int16_t sx = raio;
    int16_t sy = 0;
    int16_t err = 0;

    while (sx >= sy){
        lcd_draw_line(x + sx, y + sy, x + sx, y - sy, color);
        lcd_draw_line(x - sx, y + sy, x - sx, y - sy, color);
        lcd_draw_line(x + sy, y + sx, x + sy, y - sx, color);
        lcd_draw_line(x - sy, y + sx, x - sy, y - sx, color);

        sy += 1;
        if (err <= 0){
            err += 2 * sy + 1;
        }
        if (err > 0){
            sx -= 1;
            err -= 2 * sx + 1;
        }
    }
}
//-----------------------------------------------------------------------------------------
static const font_t* _font;
void lcd_set_font( const font_t* font ){
    _font = font;
}
//-----------------------------------------------------------------------------------------
void lcd_printf(int16_t x, int16_t y, color_t color, const char* format, ...){
    char* buffer;
	va_list args;
	va_start (args, format);
	vasprintf (&buffer,format, args);
	va_end (args);
	
    const int16_t x0 = x;
    const int16_t y0 = y;
    
	char* ptr = buffer;
	while(*ptr != '\0'){
        if(*ptr == '\r'){
            x = x0;
        }
        else if(*ptr == '\n'){
            y += _font->height + _font->line_spacing;
        }
        else if (*ptr >= _font->first_character && *ptr <= _font->last_character) {
			const character_t* character = _font->characters[*ptr - _font->first_character];
			
			for (int16_t j = 0; j < character->height; j++) {
				for (int16_t i = 0; i < character->width; i++) {
					if(character->data[j * character->width + i]){
						lcd_draw_pixel(x + i,y + j,color);
					}
				}
			}
			x += character->width + _font->character_spacing;
		}
		ptr++;
	}
    free(buffer);
}
//-----------------------------------------------------------------------------------------

