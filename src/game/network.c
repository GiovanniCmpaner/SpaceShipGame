#if 0

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sys/param.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event_loop.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "rom/crc.h"

#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include "lwip/api.h"
#include <lwip/netdb.h>

#include "esp_timer.h"
#include "esp_err.h"
#include "esp_log.h"

#include "network.h"
#include "network_tcp.h"

//-----------------------------------------------------------------------------------------
#define EXAMPLE_WIFI_SSID "WORKGROUP"
#define EXAMPLE_WIFI_PASS "49WNN7F3CD@22"
#define EXAMPLE_MAX_STA_CONN 2
//-----------------------------------------------------------------------------------------
static const char* TAG = "network";

static EventGroupHandle_t wifi_event_group = NULL;

void (*func_send)() = NULL;
void (*func_receive)() = NULL;

const int IPV4_GOTIP_BIT = BIT0;
const int IPV6_GOTIP_BIT = BIT1;
//-----------------------------------------------------------------------------------------
static esp_err_t event_handler(void *ctx, system_event_t *event)
{
    switch (event->event_id) {
    case SYSTEM_EVENT_STA_START:
        esp_wifi_connect();
        ESP_LOGI(TAG, "SYSTEM_EVENT_STA_START");
        break;
    case SYSTEM_EVENT_STA_CONNECTED:
        /* enable ipv6 */
        tcpip_adapter_create_ip6_linklocal(TCPIP_ADAPTER_IF_STA);
        break;
    case SYSTEM_EVENT_STA_GOT_IP:
        xEventGroupSetBits(wifi_event_group, IPV4_GOTIP_BIT);
        ESP_LOGI(TAG, "SYSTEM_EVENT_STA_GOT_IP");
        break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
        /* This is a workaround as ESP32 WiFi libs don't currently auto-reassociate. */
        esp_wifi_connect();
        xEventGroupClearBits(wifi_event_group, IPV4_GOTIP_BIT);
        xEventGroupClearBits(wifi_event_group, IPV6_GOTIP_BIT);
        break;
    case SYSTEM_EVENT_AP_STA_GOT_IP6:
        xEventGroupSetBits(wifi_event_group, IPV6_GOTIP_BIT);
        ESP_LOGI(TAG, "SYSTEM_EVENT_STA_GOT_IP6");

        char *ip6 = ip6addr_ntoa(&event->event_info.got_ip6.ip6_info.ip);
        ESP_LOGI(TAG, "IPv6: %s", ip6);
    case SYSTEM_EVENT_AP_STACONNECTED:
        ESP_LOGI(TAG, "station:"MACSTR" join, AID=%d",
                 MAC2STR(event->event_info.sta_connected.mac),
                 event->event_info.sta_connected.aid);
        break;
    case SYSTEM_EVENT_AP_STADISCONNECTED:
        ESP_LOGI(TAG, "station:"MACSTR"leave, AID=%d",
                 MAC2STR(event->event_info.sta_disconnected.mac),
                 event->event_info.sta_disconnected.aid);
        break;
    default:
        break;
    }
    return ESP_OK;
}
//-----------------------------------------------------------------------------------------
static void wait_for_ip()
{
    uint32_t bits = IPV4_GOTIP_BIT;

    //ESP_LOGI(TAG, "Waiting for AP connection...");
    xEventGroupWaitBits(wifi_event_group, bits, false, true, portMAX_DELAY);
    //ESP_LOGI(TAG, "Connected to AP");
}
//-----------------------------------------------------------------------------------------
static void network_initialize_common()
{
    nvs_flash_init();

    tcpip_adapter_init();
    wifi_event_group = xEventGroupCreate();
    ESP_ERROR_CHECK( esp_event_loop_init(event_handler, NULL) );

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK( esp_wifi_init(&cfg) );
    ESP_ERROR_CHECK( esp_wifi_set_storage(WIFI_STORAGE_RAM) );
}
//-----------------------------------------------------------------------------------------
static void network_initialize_client( network_type_t type, game_state_t* game_state )
{
    wifi_config_t wifi_config = {
        .sta = {
            .ssid = EXAMPLE_WIFI_SSID,
            .password = EXAMPLE_WIFI_PASS,
        },
    };
    //ESP_LOGI(TAG, "Setting WiFi configuration SSID for STA %s...", wifi_config.sta.ssid);
    ESP_ERROR_CHECK( esp_wifi_set_mode(WIFI_MODE_STA) );
    ESP_ERROR_CHECK( esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config) );
    ESP_ERROR_CHECK( esp_wifi_start() );
    
    wait_for_ip();
    if( type == NETWORK_TCP )
    {
        network_initialize_tcp_client( game_state );
        func_send = network_tcp_send;
        func_receive = network_tcp_receive;
    }
    else if( type == NETWORK_UDP )
    {
        //xTaskCreatePinnedToCore( network_process_udp_client, "network_process_udp_client", 4096, NULL, 5, &network_task_handle, 1 );
    }
    
}
//-----------------------------------------------------------------------------------------
static void network_initialize_server( network_type_t type, game_state_t* game_state )
{
    wifi_config_t wifi_config = {
        .ap = {
            .ssid = EXAMPLE_WIFI_SSID,
            .ssid_len = strlen(EXAMPLE_WIFI_SSID),
            .password = EXAMPLE_WIFI_PASS,
            .max_connection = EXAMPLE_MAX_STA_CONN,
            .authmode = WIFI_AUTH_WPA_WPA2_PSK
        },
    };
    ESP_ERROR_CHECK( esp_wifi_set_mode(WIFI_MODE_AP) );
    ESP_ERROR_CHECK( esp_wifi_set_config(ESP_IF_WIFI_AP, &wifi_config) );
    ESP_ERROR_CHECK( esp_wifi_start() );
    
    //ESP_LOGI(TAG, "wifi_init_softap finished.SSID:%s password:%s", EXAMPLE_WIFI_SSID, EXAMPLE_WIFI_PASS);
    if( type == NETWORK_TCP )
    {
        network_initialize_tcp_server( game_state );
        func_send = network_tcp_send;
        func_receive = network_tcp_receive;
    }
    else if( type == NETWORK_UDP )
    {
        
    }
}
//-----------------------------------------------------------------------------------------
void network_initialize( network_mode_t mode, network_type_t type, game_state_t* game_state )
{
    network_initialize_common();
    
    if( mode == NETWORK_CLIENT ){ 
        network_initialize_client( type, game_state );
    }
    else if( mode == NETWORK_SERVER ){
        network_initialize_server( type, game_state );
    }
}
//-----------------------------------------------------------------------------------------
void network_terminate()
{
    
}
//-----------------------------------------------------------------------------------------
void network_send()
{
    if( func_send != NULL )
    {
        func_send();
    }
}
//-----------------------------------------------------------------------------------------
void network_receive()
{
    if( func_receive != NULL )
    {
        func_receive();
    }
}
//-----------------------------------------------------------------------------------------

#endif