#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"
#include "esp_err.h"
#include "esp_log.h"

#include "input.h"
#include "audio/audio.h"
#include "pins.h"
//-----------------------------------------------------------------------------------------
typedef struct
{
    double x;
    double y;
} direction_control_t;

static const char *tag = "input";

static uint8_t gpio_buttons[4] = {BTN_1, BTN_2, BTN_3, BTN_4};
static const size_t gpio_buttons_length = sizeof(gpio_buttons) / sizeof(*gpio_buttons);

static QueueHandle_t direction_control_queue = NULL;
static QueueHandle_t action_control_queues[4] = {NULL};
//-----------------------------------------------------------------------------------------
void input_initialize();
void input_terminate();
void input_on();
void input_off();
bool input_directions(double *x, double *y);
bool input_action(uint8_t n, uint8_t *level);

static void input_process_directions();
static void input_process_actions(void *parameters);
//-----------------------------------------------------------------------------------------
void input_initialize()
{
    ESP_LOGI(tag, "initialize");

    input_on();

    direction_control_queue = xQueueCreate(1, sizeof(direction_control_t));
    xTaskCreatePinnedToCore(input_process_directions, "input_process_directions", 2048, NULL, 5, NULL, 0);

    for (size_t n = 0; n < gpio_buttons_length; n++)
    {
        action_control_queues[n] = xQueueCreate(1, sizeof(bool));
        xTaskCreatePinnedToCore(input_process_actions, "input_process_actions", 1024, (void *)n, 5, NULL, 0);
    }
}
//-----------------------------------------------------------------------------------------
void input_terminate()
{
    ESP_LOGI(tag, "terminate");

    input_off();
}
//-----------------------------------------------------------------------------------------
void input_on()
{
    ESP_LOGI(tag, "on");

    for (size_t n = 0; n < gpio_buttons_length; n++)
    {
        gpio_set_direction(gpio_buttons[n], GPIO_MODE_INPUT);
        gpio_set_pull_mode(gpio_buttons[n], GPIO_PULLUP_ONLY);
    }
}
//-----------------------------------------------------------------------------------------
void input_off()
{
    ESP_LOGI(tag, "off");

    for (size_t n = 0; n < gpio_buttons_length; n++)
    {
        gpio_set_pull_mode(gpio_buttons[n], GPIO_FLOATING);
        gpio_set_direction(gpio_buttons[n], GPIO_MODE_DISABLE);
    }
}
//-----------------------------------------------------------------------------------------
bool input_directions(double *x, double *y)
{
    if (direction_control_queue != NULL)
    {
        direction_control_t directions;
        if (xQueuePeek(direction_control_queue, &directions, 0))
        {
            *x = directions.x;
            *y = directions.y;
            return true;
        }
    }
    return false;
}
//-----------------------------------------------------------------------------------------
bool input_action(uint8_t n, uint8_t *level)
{
    return action_control_queues[n] != NULL ? xQueueReceive(action_control_queues[n], level, 0) : false;
}
//-----------------------------------------------------------------------------------------
static void input_process_directions()
{

    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(JOY_VRX_CH, ADC_ATTEN_DB_11);
    adc1_config_channel_atten(JOY_VRY_CH, ADC_ATTEN_DB_11);

    const TickType_t interval = pdMS_TO_TICKS(30);
    TickType_t last_wake_time = xTaskGetTickCount();
    while (1)
    {
        int16_t raw_x = adc1_get_raw(JOY_VRX_CH) - 1845;
        int16_t raw_y = adc1_get_raw(JOY_VRY_CH) - 1845;

        if (raw_x > 1845)
        {
            raw_x = 1845;
        }
        if (raw_y > 1845)
        {
            raw_y = 1845;
        }

        direction_control_t direction = {
            .x = 0.0,
            .y = 0.0};

        if (raw_x < -32 || raw_x > 32)
        {
            direction.x = -raw_x / 1845.0;
        }
        if (raw_y < -32 || raw_y > 32)
        {
            direction.y = +raw_y / 1845.0;
        }

        const double modulus = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
        if (modulus > 1.0)
        {
            direction.x /= modulus;
            direction.y /= modulus;
        }

        xQueueOverwrite(direction_control_queue, &direction);

        vTaskDelayUntil(&last_wake_time, interval);
    }
}
//-----------------------------------------------------------------------------------------
static void input_process_actions(void *parameters)
{
    const size_t n = (size_t)parameters;

    uint8_t level = false;

    const TickType_t interval = pdMS_TO_TICKS(30);
    TickType_t last_wake_time = xTaskGetTickCount();
    while (1)
    {
        if (gpio_get_level(gpio_buttons[n]) == 0)
        {
            if (level == 0)
            {
                vTaskDelayUntil(&last_wake_time, interval);
                if (gpio_get_level(gpio_buttons[n]) == 0)
                {
                    level = 1;
                    xQueueSend(action_control_queues[n], &level, 0);
                }
            }
        }
        else if (level == 1)
        {
            level = 0;
            xQueueSend(action_control_queues[n], &level, 0);
        }
        vTaskDelayUntil(&last_wake_time, interval);
    }
}
//-----------------------------------------------------------------------------------------
