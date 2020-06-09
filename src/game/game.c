#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/event_groups.h"
#include "freertos/list.h"

#include "esp_timer.h"
#include "esp_err.h"
#include "esp_log.h"

#include "game.h"
#include "object.h"
#include "network.h"

#include "input.h"
#include "lcd/lcd.h"
#include "font/font.h"
#include "image/spaceship.h"
#include "image/background.h"
#include "image/asteroid.h"
#include "image/info.h"
#include "image/shield.h"

#include "image/impact.h"
#include "image/meteor.h"
#include "image/projectile.h"

//-----------------------------------------------------------------------------------------

#ifndef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif

#ifndef min
#define min(a, b) ((a) < (b) ? (a) : (b))
#endif

static const char *TAG = "game";
static TaskHandle_t game_task_handle = NULL;

game_state_t game_state = {
    .current_player = 0,
    .play_timer = 0};

void game_initialize();
void game_terminate();
static void game_process(void *pvParameters);
//-----------------------------------------------------------------------------------------
void game_initialize(game_mode_t mode)
{
    ESP_LOGI(TAG, "initialize");
    if (game_task_handle == NULL)
    {
        //if (mode == GAME_SERVER)
        //{
        //    network_initialize(NETWORK_SERVER, NETWORK_TCP, &game_state);
        //}
        //else if (mode == GAME_CLIENT)
        //{
        //    network_initialize(NETWORK_CLIENT, NETWORK_TCP, &game_state);
        //}
        xTaskCreatePinnedToCore(game_process, "game_process", 4096, (void *)mode, 5, &game_task_handle, 0);
    }
}
//-----------------------------------------------------------------------------------------
void game_terminate()
{
    ESP_LOGI(TAG, "terminate");
    if (game_task_handle != NULL)
    {
        network_terminate();
        vTaskDelete(game_task_handle);
        game_task_handle = NULL;
    }
}
//-----------------------------------------------------------------------------------------
static void game_receive()
{
}
//-----------------------------------------------------------------------------------------
static void game_send()
{
}
//-----------------------------------------------------------------------------------------
void game_input(uint32_t);
void game_move(uint32_t);
void game_generate(uint32_t);
void game_collide();
void game_draw();
//-----------------------------------------------------------------------------------------
static void game_process(void *pvParameters)
{
    game_mode_t mode = (game_mode_t)pvParameters;

    const spaceship_control_t spaceship_control = {
        .active = true,
        .mode = SPACESHIP_IDLE,
        .px = 50.0,
        .py = 50.0,
        .vi = 0.0,
        .vj = 0.0,
        .life = 3,
        .ammunitions = {0, 20, 10, 30},
    };
    if (mode != GAME_CLIENT)
    {
        game_state.current_player = 0;
    }
    else
    {
        game_state.current_player = 1;
    }
    game_state.spaceships[game_state.current_player] = spaceship_control;

    const TickType_t interval = pdMS_TO_TICKS(30);
    TickType_t current_wake_time = xTaskGetTickCount();
    TickType_t last_wake_time = current_wake_time;
    while (1)
    {
        const uint32_t millisDiff = ((current_wake_time - last_wake_time) * 1000) / configTICK_RATE_HZ;
        last_wake_time = current_wake_time;
        game_state.play_timer += millisDiff;

        game_input();              // task -> wait( BIT_REFRESH )
        game_move(millisDiff);     // task -> wait( BIT_REFRESH | BIT_INPUT )
        game_generate(millisDiff); // task -> wait( BIT_REFRESH )
        game_collide();            // task -> wait( BIT_REFRESH | BIT_MOVE )
        game_draw();               // task -> wait( BIT_REFRESH | BIT_INPUT | BIT_MOVE | BIT_GENERATE )

        vTaskDelayUntil(&current_wake_time, interval);
    }
}
//-----------------------------------------------------------------------------------------