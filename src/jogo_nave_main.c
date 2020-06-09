//-----------------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdint.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_err.h"
#include "esp_log.h"

#include "esp_sleep.h"
#include "esp32/ulp.h"
#include "driver/rtc_io.h"

#include "lcd/lcd.h"
#include "audio/audio.h"
#include "input.h"
#include "pins.h"
#include "menu.h"
//-----------------------------------------------------------------------------------------
static const char* tag = "main";

void app_main();
static void dorme();
//-----------------------------------------------------------------------------------------
void app_main()
{
    input_initialize();
    lcd_initialize();
    audio_initialize();
    menu_initialize();
    
    while(1){
        
        
        
        //{
        //    lcd_draw_rectangle(0,0,100,100,0xF800);
        //    lcd_draw_rectangle_filled(150,100,200,150,0xF800);
        //    
        //    lcd_draw_circle(150,75,20,0xF800);
        //    lcd_draw_circle(50,150,20,0xF800);
        //    
        //    lcd_draw_line(50,50,100,100,0xF800);
        //    lcd_draw_line(25,50,100,100,0xF800);
        //    lcd_draw_line(0,50,100,100,0xF800);
        //    lcd_draw_line(50,75,100,100,0xF800);
        //    lcd_draw_line(75,50,100,100,0xF800);
        //    lcd_draw_line(100,50,100,100,0xF800);
        //    
        //    lcd_define_font( &font20x10 );
        //    lcd_escreve( 50, 50, COLOR_WHITE, "teste\r\no que e isso?\r\nasdab");
        //    lcd_draw_file( 0,0, "/sdcard/rgb.bmp" );
        //}
        //lcd_refresh();

        //audio_play("/sdcard/cursor_move_mono.wav");
        //vTaskDelay( pdMS_TO_TICKS(2000) );
        //audio_play("/sdcard/cursor_move_mono.wav");
        //vTaskDelay( pdMS_TO_TICKS(2000) );
        //audio_play("/sdcard/cursor_move_mono.wav");
        //vTaskDelay( pdMS_TO_TICKS(2000) );
        //audio_play("/sdcard/cursor_move_mono.wav");
        //vTaskDelay( pdMS_TO_TICKS(2000) );

        vTaskDelay( portMAX_DELAY );

        //vTaskDelay( pdMS_TO_TICKS(20000) );
        //dorme();
    }
}
//-----------------------------------------------------------------------------------------
static void dorme(){
    lcd_off();
    input_off();
    
    rtc_gpio_pullup_en(BTN_1);
    esp_sleep_enable_ext0_wakeup(BTN_1,0);
    esp_deep_sleep_start();
    rtc_gpio_deinit(BTN_1);
    
    input_on();
    lcd_on();
}
//-----------------------------------------------------------------------------------------