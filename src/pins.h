#ifndef PINOS_H
#define PINOS_H

typedef enum {
    LCD_LED       = 19,
    LCD_RST       = 17,
    LCD_DC        = 16,
    LCD_MOSI      = 23,
    LCD_SCLK      = 18,
    LCD_CS        = 5,
    //LCD_SPI       = VSPI,

    SD_MISO       = 12,
    SD_MOSI       = 13,
    SD_SCLK       = 14,
    SD_CS         = 15,
    //SD_SPI        = HSPI,

    BTN_1         = 27,
    BTN_2         = 4,
    BTN_3         = 22,
    BTN_4         = 21,

    ROUT          = 25,
    ROUT_CH       = 1,
    LOUT          = 26,
    LOUT_CH       = 2,

    JOY_VRX       = 35,
    JOY_VRX_UNIT  = 1,
    JOY_VRX_CH    = 7,
    JOY_VRY       = 32,
    JOY_VRY_UNIT  = 1,
    JOY_VRY_CH    = 4,
    JOY_SW        = 34,
    JOY_SW_UNIT   = 1,
    JOY_SW_CH     = 6,

    VBAT          = 33,
    VBAT_VRX_UNIT = 1,
    VBAT_VRX_CH   = 5
} pin_t;

#endif