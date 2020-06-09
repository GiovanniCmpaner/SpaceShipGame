#include <stdint.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/spi_master.h"
#include "driver/spi_common.h"
#include "driver/gpio.h"

#include "lcd_spi.h"
#include "lcd_reg.h"
#include "../pins.h"
//-----------------------------------------------------------------------------------------
static const lcd_cmd_t lcd_init_cmds[] = {
    { .cmd = ILI9225_SOFT_RESET,              .length = 2, .data = { 0x00, 0xCE }, .delay = 150 },
    
    { .cmd = ILI9225_POWER_CTRL1,             .length = 2, .data = { 0x00, 0x00 } }, // Set SAP,DSTB,STB
    { .cmd = ILI9225_POWER_CTRL2,             .length = 2, .data = { 0x00, 0x00 } }, // Set APON,PON,AON,VCI1EN,VC
    { .cmd = ILI9225_POWER_CTRL3,             .length = 2, .data = { 0x00, 0x00 } }, // Set BT,DC1,DC2,DC3
    { .cmd = ILI9225_POWER_CTRL4,             .length = 2, .data = { 0x00, 0x00 } }, // Set GVDD
    { .cmd = ILI9225_POWER_CTRL5,             .length = 2, .data = { 0x00, 0x00 }, .delay = 40 }, // Set VCOMH/VCOML voltage

    { .cmd = ILI9225_POWER_CTRL2,             .length = 2, .data = { 0x00, 0x18 } }, // Set APON,PON,AON,VCI1EN,VC
    { .cmd = ILI9225_POWER_CTRL3,             .length = 2, .data = { 0x61, 0x21 } }, // Set BT,DC1,DC2,DC3
    { .cmd = ILI9225_POWER_CTRL4,             .length = 2, .data = { 0x00, 0x6F } }, // Set GVDD
    { .cmd = ILI9225_POWER_CTRL5,             .length = 2, .data = { 0x49, 0x5F } }, // Set VCOMH/VCOML voltage
    { .cmd = ILI9225_POWER_CTRL1,             .length = 2, .data = { 0x08, 0x00 }, .delay = 10 }, // Set SAP,DSTB,STB

    { .cmd = ILI9225_POWER_CTRL2,             .length = 2, .data = { 0x10, 0x3B }, .delay = 50 }, // Set APON,PON,AON,VCI1EN,VC

    { .cmd = ILI9225_DRIVER_OUTPUT_CTRL,      .length = 2, .data = { 0x01, 0x1C } }, // set the display line number and display direction
    { .cmd = ILI9225_LCD_AC_DRIVING_CTRL,     .length = 2, .data = { 0x01, 0x00 } }, // set 1 line inversion
    { .cmd = ILI9225_ENTRY_MODE,              .length = 2, .data = { 0x10, 0x28 } },
    { .cmd = ILI9225_DISP_CTRL1,              .length = 2, .data = { 0x00, 0x00 } }, // Display off
    { .cmd = ILI9225_BLANK_PERIOD_CTRL1,      .length = 2, .data = { 0x08, 0x08 } }, // set the back porch and front porch
    { .cmd = ILI9225_FRAME_CYCLE_CTRL,        .length = 2, .data = { 0x11, 0x00 } }, // set the clocks number per line
    { .cmd = ILI9225_INTERFACE_CTRL,          .length = 2, .data = { 0x00, 0x00 } }, // CPU interface
    { .cmd = ILI9225_OSC_CTRL,                .length = 2, .data = { 0x0D, 0x01 } }, // Set Osc
    { .cmd = ILI9225_VCI_RECYCLING,           .length = 2, .data = { 0x00, 0x20 } }, // Set VCI recycling
    { .cmd = ILI9225_RAM_ADDR_SET1,           .length = 2, .data = { 0x00, LCD_HEIGHT - 1 } }, // RAM Address
    { .cmd = ILI9225_RAM_ADDR_SET2,           .length = 2, .data = { 0x00, 0x00 } }, // RAM Address
    
    // Set GRAM area
    { .cmd = ILI9225_GATE_SCAN_CTRL,          .length = 2, .data = { 0x00, 0x00 } },
    { .cmd = ILI9225_VERTICAL_SCROLL_CTRL1,   .length = 2, .data = { 0x00, 0x00 } },
    { .cmd = ILI9225_VERTICAL_SCROLL_CTRL2,   .length = 2, .data = { 0x00, 0x00 } },
    { .cmd = ILI9225_VERTICAL_SCROLL_CTRL3,   .length = 2, .data = { 0x00, 0x00 } },
    { .cmd = ILI9225_PARTIAL_DRIVING_POS1,    .length = 2, .data = { 0x00, LCD_WIDTH - 1 } },
    { .cmd = ILI9225_PARTIAL_DRIVING_POS2,    .length = 2, .data = { 0x00, 0x00 } },
    { .cmd = ILI9225_HORIZONTAL_WINDOW_ADDR1, .length = 2, .data = { 0x00, LCD_HEIGHT - 1} },
    { .cmd = ILI9225_HORIZONTAL_WINDOW_ADDR2, .length = 2, .data = { 0x00, 0x00 } },
    { .cmd = ILI9225_VERTICAL_WINDOW_ADDR1,   .length = 2, .data = { 0x00, LCD_WIDTH - 1} },
    { .cmd = ILI9225_VERTICAL_WINDOW_ADDR2,   .length = 2, .data = { 0x00, 0x00 } },
    
    // Set GAMMA curve
    { .cmd = ILI9225_GAMMA_CTRL1,             .length = 2, .data = { 0x00, 0x00 } },
    { .cmd = ILI9225_GAMMA_CTRL2,             .length = 2, .data = { 0x08, 0x08 } },
    { .cmd = ILI9225_GAMMA_CTRL3,             .length = 2, .data = { 0x08, 0x0A } },
    { .cmd = ILI9225_GAMMA_CTRL4,             .length = 2, .data = { 0x00, 0x0A } },
    { .cmd = ILI9225_GAMMA_CTRL5,             .length = 2, .data = { 0x0A, 0x08 } },
    { .cmd = ILI9225_GAMMA_CTRL6,             .length = 2, .data = { 0x08, 0x08 } },
    { .cmd = ILI9225_GAMMA_CTRL7,             .length = 2, .data = { 0x00, 0x00 } },
    { .cmd = ILI9225_GAMMA_CTRL8,             .length = 2, .data = { 0x0A, 0x00 } },
    { .cmd = ILI9225_GAMMA_CTRL9,             .length = 2, .data = { 0x07, 0x10 } },
    { .cmd = ILI9225_GAMMA_CTRL10,            .length = 2, .data = { 0x07, 0x10 } },
    
    { .cmd = ILI9225_DISP_CTRL1,              .length = 2, .data = { 0x00, 0x17 }, .delay = 50 },
    
    { .cmd = ILI9225_GRAM_DATA_REG,           .length = 0 }
};     
//-----------------------------------------------------------------------------------------
static const char* tag = "lcd_spi";
static const size_t lcd_init_cmds_length = sizeof(lcd_init_cmds)/sizeof(*lcd_init_cmds);
static spi_device_handle_t spi_handle = NULL;
//-----------------------------------------------------------------------------------------
void lcd_spi_init(){
    gpio_set_direction(LCD_CS, GPIO_MODE_OUTPUT);
    gpio_set_direction(LCD_DC, GPIO_MODE_OUTPUT);
    gpio_set_direction(LCD_RST, GPIO_MODE_OUTPUT);
    gpio_set_direction(LCD_LED, GPIO_MODE_OUTPUT);
    
    {
        const spi_bus_config_t bus_config = {
            .mosi_io_num = LCD_MOSI,
            .miso_io_num = -1,
            .sclk_io_num = LCD_SCLK,
            .quadwp_io_num = -1,
            .quadhd_io_num = -1,
            .max_transfer_sz = LCD_WIDTH * LCD_HEIGHT * 2,
            .flags = SPICOMMON_BUSFLAG_MASTER | SPICOMMON_BUSFLAG_NATIVE_PINS
        };
        spi_bus_initialize(VSPI_HOST,&bus_config,1);
    }
    {
        const spi_device_interface_config_t dev_config = {
            .clock_speed_hz = SPI_MASTER_FREQ_40M,
            .spics_io_num = LCD_CS,
            .queue_size = 1
        };
        spi_bus_add_device(VSPI_HOST,&dev_config,&spi_handle);
    }
    lcd_spi_on();
}
//-----------------------------------------------------------------------------------------
void lcd_spi_on(){
    gpio_set_level( LCD_CS, 1 );
    gpio_set_level( LCD_DC, 1 );
    gpio_set_level( LCD_LED, 1 );
    gpio_set_level( LCD_RST, 1 );
    vTaskDelay( 10 / portTICK_PERIOD_MS );
    gpio_set_level( LCD_RST, 0 );
    vTaskDelay( 10 / portTICK_PERIOD_MS );
    gpio_set_level(LCD_RST, 1 );
    vTaskDelay( 50 / portTICK_PERIOD_MS);

    for(uint8_t n = 0; n < lcd_init_cmds_length; n++){
        lcd_spi_write(&lcd_init_cmds[n]);
    }
}
//-----------------------------------------------------------------------------------------
void lcd_spi_off(){
    const lcd_cmd_t cmd = { .cmd = ILI9225_POWER_CTRL1, .length = 2, .data = { 0x00, 0x01 } };
    lcd_spi_write(&cmd);
    
    gpio_set_level( LCD_LED, 0 );
}
//-----------------------------------------------------------------------------------------
void lcd_spi_write(const lcd_cmd_t* cmd){
	if(cmd->cmd){
		gpio_set_level( LCD_DC, 0 );
		
		spi_transaction_t trans_desc = {
			.length = 8,
			.tx_buffer = &cmd->cmd
		};
		spi_device_polling_transmit(spi_handle,&trans_desc);
	}
	if(cmd->length){
		gpio_set_level( LCD_DC, 1 );
		
		spi_transaction_t trans_desc = {
			.length = cmd->length * 8,
			.tx_buffer = cmd->ptr ? cmd->ptr : cmd->data
		};
		spi_device_polling_transmit(spi_handle,&trans_desc);
	}
	vTaskDelay( cmd->delay / portTICK_PERIOD_MS);
}
//-----------------------------------------------------------------------------------------

