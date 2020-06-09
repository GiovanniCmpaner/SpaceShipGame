#include <stdint.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "driver/uart.h"

#include "menu.h"
#include "input.h"
#include "lcd/lcd.h"
#include "audio/audio.h"
#include "game/game.h"
#include "game/network.h"
//-----------------------------------------------------------------------------------------
static const char *tag = "menu";
static TaskHandle_t menu_task_handle = NULL;

void menu_initialize();
static void menu_process();
//-----------------------------------------------------------------------------------------
void menu_initialize()
{
    ESP_LOGI(tag, "initialize");
    if (menu_task_handle == NULL)
    {
        xTaskCreatePinnedToCore(menu_process, "menu_process", 3072, NULL, 1, &menu_task_handle, 1);
    }
    //vTaskResume( menu_task_handle );
}
//-----------------------------------------------------------------------------------------
void menu_terminate()
{
    ESP_LOGI(tag, "terminate");
    if (menu_task_handle != NULL)
    {
        vTaskDelete(menu_task_handle);
        menu_task_handle = NULL;
    }
}
//-----------------------------------------------------------------------------------------
static void menu_draw(uint8_t menu)
{
    lcd_fill(COLOR_BLACK);
    //lcd_draw_image( -50, 20, &image_space );

    //static int16_t i = 0;
    //{
    //    const int64_t start = esp_timer_get_time();
    //    lcd_draw_image( i, 0, &image_space );
    //    if( i + image_space.width < 220 ){
    //        lcd_draw_image( i + image_space.width, 0, &image_space );
    //    }
    //    const int64_t end = esp_timer_get_time();
    //    ESP_LOGI(tag,"t1 = %lld",end-start);
    //
    //    i -= 5;
    //    if(i < -image_space.width){
    //        i += image_space.width;
    //    }
    //}

    lcd_set_font(&font14x10);
    lcd_printf(30, 10, menu == 0 ? COLOR_WHITE : COLOR_RED, "Iniciar Offline");
    lcd_printf(30, 35, menu == 1 ? COLOR_WHITE : COLOR_RED, "Iniciar Servidor");
    lcd_printf(30, 60, menu == 2 ? COLOR_WHITE : COLOR_RED, "Iniciar Cliente");
    lcd_printf(30, 85, menu == 3 ? COLOR_WHITE : COLOR_RED, "Volume %u%%", audio_get_volume());

    lcd_draw_circle_filled(20, 160, 7, COLOR_RED);
    lcd_draw_circle_filled(70, 160, 7, COLOR_GREEN);
    lcd_draw_circle_filled(120, 160, 7, COLOR_BLUE);
    lcd_draw_circle_filled(170, 160, 7, COLOR_YELLOW);

    //for(uint8_t n = 0; n < 3; n++){
    //    char buffer[128];
    //    sprintf(buffer,"meteor%u",n);
    //
    //    lcd_draw_image_orientation_print( buffer, image_meteor[n][ IMAGE_ROTATED_0 ], IMAGE_ROTATED_0   );
    //    lcd_draw_image_orientation_print( buffer, image_meteor[n][ IMAGE_ROTATED_0 ], IMAGE_ROTATED_90  );
    //    vTaskDelay( 2 );
    //    lcd_draw_image_orientation_print( buffer, image_meteor[n][ IMAGE_ROTATED_0 ], IMAGE_ROTATED_180 );
    //    lcd_draw_image_orientation_print( buffer, image_meteo[n][ IMAGE_ROTATED_0 ], IMAGE_ROTATED_270 );
    //    vTaskDelay( 2 );
    //}

    //for(uint8_t n = 0; n < 6; n++){
    //    char buffer[128];
    //    sprintf(buffer,"asteroid%u",n);
    //
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_normal2[n], IMAGE_ROTATED_0   );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_normal2[n], IMAGE_ROTATED_90  );
    //    vTaskDelay( 2 );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_normal2[n], IMAGE_ROTATED_180 );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_normal2[n], IMAGE_ROTATED_270 );
    //    vTaskDelay( 2 );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_normal2[n], IMAGE_ROTATED_0   | IMAGE_MIRRORED_HORIZONTAL );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_normal2[n], IMAGE_ROTATED_90  | IMAGE_MIRRORED_HORIZONTAL );
    //    vTaskDelay( 2 );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_normal2[n], IMAGE_ROTATED_180 | IMAGE_MIRRORED_HORIZONTAL );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_normal2[n], IMAGE_ROTATED_270 | IMAGE_MIRRORED_HORIZONTAL );
    //    vTaskDelay( 2 );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_normal2[n], IMAGE_ROTATED_0   | IMAGE_MIRRORED_VERTICAL );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_normal2[n], IMAGE_ROTATED_90  | IMAGE_MIRRORED_VERTICAL );
    //    vTaskDelay( 2 );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_normal2[n], IMAGE_ROTATED_180 | IMAGE_MIRRORED_VERTICAL );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_normal2[n], IMAGE_ROTATED_270 | IMAGE_MIRRORED_VERTICAL );
    //    vTaskDelay( 2 );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_normal2[n], IMAGE_ROTATED_0   | IMAGE_MIRRORED_HORIZONTAL | IMAGE_MIRRORED_VERTICAL );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_normal2[n], IMAGE_ROTATED_90  | IMAGE_MIRRORED_HORIZONTAL | IMAGE_MIRRORED_VERTICAL );
    //    vTaskDelay( 2 );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_normal2[n], IMAGE_ROTATED_180 | IMAGE_MIRRORED_HORIZONTAL | IMAGE_MIRRORED_VERTICAL );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_normal2[n], IMAGE_ROTATED_270 | IMAGE_MIRRORED_HORIZONTAL | IMAGE_MIRRORED_VERTICAL );
    //    vTaskDelay( 2 );
    //}
    //for(uint8_t n = 0; n < 6; n++){
    //    char buffer[128];
    //    sprintf(buffer,"asteroid%u_damaged",n);
    //
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_damaged2[n], IMAGE_ROTATED_0   );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_damaged2[n], IMAGE_ROTATED_90  );
    //    vTaskDelay( 2 );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_damaged2[n], IMAGE_ROTATED_180 );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_damaged2[n], IMAGE_ROTATED_270 );
    //    vTaskDelay( 2 );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_damaged2[n], IMAGE_ROTATED_0   | IMAGE_MIRRORED_HORIZONTAL );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_damaged2[n], IMAGE_ROTATED_90  | IMAGE_MIRRORED_HORIZONTAL );
    //    vTaskDelay( 2 );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_damaged2[n], IMAGE_ROTATED_180 | IMAGE_MIRRORED_HORIZONTAL );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_damaged2[n], IMAGE_ROTATED_270 | IMAGE_MIRRORED_HORIZONTAL );
    //    vTaskDelay( 2 );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_damaged2[n], IMAGE_ROTATED_0   | IMAGE_MIRRORED_VERTICAL );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_damaged2[n], IMAGE_ROTATED_90  | IMAGE_MIRRORED_VERTICAL );
    //    vTaskDelay( 2 );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_damaged2[n], IMAGE_ROTATED_180 | IMAGE_MIRRORED_VERTICAL );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_damaged2[n], IMAGE_ROTATED_270 | IMAGE_MIRRORED_VERTICAL );
    //    vTaskDelay( 2 );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_damaged2[n], IMAGE_ROTATED_0   | IMAGE_MIRRORED_HORIZONTAL | IMAGE_MIRRORED_VERTICAL );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_damaged2[n], IMAGE_ROTATED_90  | IMAGE_MIRRORED_HORIZONTAL | IMAGE_MIRRORED_VERTICAL );
    //    vTaskDelay( 2 );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_damaged2[n], IMAGE_ROTATED_180 | IMAGE_MIRRORED_HORIZONTAL | IMAGE_MIRRORED_VERTICAL );
    //    lcd_draw_image_orientation_print( buffer, 45, 75, image_asteroids_damaged2[n], IMAGE_ROTATED_270 | IMAGE_MIRRORED_HORIZONTAL | IMAGE_MIRRORED_VERTICAL );
    //    vTaskDelay( 2 );
    //}

    //lcd_draw_image_orientation( 190, 100, image_spaceships[0], IMAGE_ROTATED_90 );
    //lcd_draw_image_orientation( 190, 30, image_spaceships[0], IMAGE_ROTATED_270 );
    //
    //lcd_draw_image_orientation( -5, -5, image_spaceships[0], IMAGE_ROTATED_90 );
    //lcd_draw_image_orientation( -5, 170, image_spaceships[0], IMAGE_ROTATED_270 );

    lcd_draw_rectangle(0, 0, lcd_width() - 1, lcd_height() - 1, COLOR_WHITE);
    lcd_refresh();
}
//-----------------------------------------------------------------------------------------
static void menu_process()
{
    uint8_t actual_menu = 0;

    audio_set_volume(10);
    menu_draw(actual_menu);

    TickType_t interval = pdMS_TO_TICKS(200);
    TickType_t last_wake_time = xTaskGetTickCount();
    while (1)
    {
        bool redraw = false;

        for (size_t n = 0; n < 4; n++)
        {
            uint8_t level;
            if (input_action(n, &level) && level)
            {
                if (n == ACTION_UP)
                {
                    if (actual_menu < 3)
                    {
                        actual_menu++;
                        audio_play(&audio_cursor_move);
                        redraw = true;
                    }
                }
                else if (n == ACTION_LEFT)
                {
                    if (actual_menu == 3)
                    {
                        uint8_t volume_percentage = audio_get_volume();
                        if (volume_percentage >= 10)
                        {
                            volume_percentage -= 10;

                            audio_set_volume(volume_percentage);
                            audio_play(&audio_cursor_move);
                            redraw = true;
                        }
                    }
                }
                else if (n == ACTION_RIGHT)
                {
                    if (actual_menu == 3)
                    {
                        uint8_t volume_percentage = audio_get_volume();
                        if (volume_percentage <= 90)
                        {
                            volume_percentage += 10;

                            audio_set_volume(volume_percentage);
                            audio_play(&audio_cursor_move);
                            redraw = true;
                        }
                    }
                    else if (actual_menu == 2)
                    {
                        game_initialize(GAME_CLIENT);
                        menu_terminate();
                        break;
                    }
                    else if (actual_menu == 1)
                    {
                        game_initialize(GAME_SERVER);
                        menu_terminate();
                        break;
                    }
                    else if (actual_menu == 0)
                    {
                        game_initialize(GAME_OFFLINE);
                        menu_terminate();
                        break;
                    }
                }
                else if (n == ACTION_DOWN)
                {
                    if (actual_menu > 0)
                    {
                        actual_menu--;
                        audio_play(&audio_cursor_move);
                        redraw = true;
                    }
                }
            }
        }
        if (redraw)
        {
            menu_draw(actual_menu);
        }
        vTaskDelayUntil(&last_wake_time, interval);
    }
}
//-----------------------------------------------------------------------------------------