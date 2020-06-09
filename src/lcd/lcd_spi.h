#ifndef LCD_SPI_H
#define LCD_SPI_H

#include <stdint.h>


#define LCD_WIDTH    220
#define LCD_HEIGHT   176

typedef struct {
    uint8_t cmd;
    size_t length;
    uint8_t data[16];
    uint8_t* ptr;
    uint16_t delay;
} lcd_cmd_t;

void lcd_spi_init();
void lcd_spi_on();
void lcd_spi_off();
void lcd_spi_write(const lcd_cmd_t* cmd);

#endif


