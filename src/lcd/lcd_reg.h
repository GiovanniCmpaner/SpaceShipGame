#ifndef LCD_REG_H
#define LCD_REG_H

typedef enum {
    ILI9225_DRIVER_OUTPUT_CTRL      = 0x01,  // Driver Output Control
    ILI9225_LCD_AC_DRIVING_CTRL     = 0x02,  // LCD AC Driving Control
    ILI9225_ENTRY_MODE              = 0x03,  // Entry Mode
    ILI9225_DISP_CTRL1              = 0x07,  // Display Control 1
    ILI9225_BLANK_PERIOD_CTRL1      = 0x08,  // Blank Period Control
    ILI9225_FRAME_CYCLE_CTRL        = 0x0B,  // Frame Cycle Control
    ILI9225_INTERFACE_CTRL          = 0x0C,  // Interface Control
    ILI9225_OSC_CTRL                = 0x0F,  // Osc Control
    ILI9225_POWER_CTRL1             = 0x10,  // Power Control 1
    ILI9225_POWER_CTRL2             = 0x11,  // Power Control 2
    ILI9225_POWER_CTRL3             = 0x12,  // Power Control 3
    ILI9225_POWER_CTRL4             = 0x13,  // Power Control 4
    ILI9225_POWER_CTRL5             = 0x14,  // Power Control 5
    ILI9225_VCI_RECYCLING           = 0x15,  // VCI Recycling
    ILI9225_RAM_ADDR_SET1           = 0x20,  // Horizontal GRAM Address Set
    ILI9225_RAM_ADDR_SET2           = 0x21,  // Vertical GRAM Address Set
    ILI9225_GRAM_DATA_REG           = 0x22,  // GRAM Data Register
    ILI9225_SOFT_RESET              = 0x28,  // Software Reset    
    ILI9225_GATE_SCAN_CTRL          = 0x30,  // Gate Scan Control Register
    ILI9225_VERTICAL_SCROLL_CTRL1   = 0x31,  // Vertical Scroll Control 1 Register
    ILI9225_VERTICAL_SCROLL_CTRL2   = 0x32,  // Vertical Scroll Control 2 Register
    ILI9225_VERTICAL_SCROLL_CTRL3   = 0x33,  // Vertical Scroll Control 3 Register
    ILI9225_PARTIAL_DRIVING_POS1    = 0x34,  // Partial Driving Position 1 Register
    ILI9225_PARTIAL_DRIVING_POS2    = 0x35,  // Partial Driving Position 2 Register
    ILI9225_HORIZONTAL_WINDOW_ADDR1 = 0x36,  // Horizontal Address Start Position
    ILI9225_HORIZONTAL_WINDOW_ADDR2 = 0x37,  // Horizontal Address End Position
    ILI9225_VERTICAL_WINDOW_ADDR1   = 0x38,  // Vertical Address Start Position
    ILI9225_VERTICAL_WINDOW_ADDR2   = 0x39,  // Vertical Address End Position
    ILI9225_GAMMA_CTRL1             = 0x50,  // Gamma Control 1
    ILI9225_GAMMA_CTRL2             = 0x51,  // Gamma Control 2
    ILI9225_GAMMA_CTRL3             = 0x52,  // Gamma Control 3
    ILI9225_GAMMA_CTRL4             = 0x53,  // Gamma Control 4
    ILI9225_GAMMA_CTRL5             = 0x54,  // Gamma Control 5
    ILI9225_GAMMA_CTRL6             = 0x55,  // Gamma Control 6
    ILI9225_GAMMA_CTRL7             = 0x56,  // Gamma Control 7
    ILI9225_GAMMA_CTRL8             = 0x57,  // Gamma Control 8
    ILI9225_GAMMA_CTRL9             = 0x58,  // Gamma Control 9
    ILI9225_GAMMA_CTRL10            = 0x59   // Gamma Control 10
} lcd_reg_t;

#endif