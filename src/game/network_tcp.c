#if 0

//-----------------------------------------------------------------------------------------
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

#include "object.h"
#include "network_tcp.h"
#include "protocol.h"

//-----------------------------------------------------------------------------------------
#define HOST_IP_ADDR "192.168.1.109"
#define PORT 5000
//-----------------------------------------------------------------------------------------
static const char* TAG = "network_tcp";

typedef enum {
    NETWORK_CONNECTED = BIT(0),
    NETWORK_RECEIVE   = BIT(1),
    NETWORK_RECEIVED  = BIT(2),
    NETWORK_SEND      = BIT(3),
    NETWORK_SENT      = BIT(4)
} network_event_t;

static TaskHandle_t network_task_handle = NULL;
static EventGroupHandle_t network_event_group = NULL;

static const size_t receive_buffer_size = 10000;
static char* receive_buffer = NULL;
static size_t receive_position = 0;
static bool receive_valid = false;
static bool receive_completed = true;
static int64_t receive_timeout = 0;
static size_t receive_packet_end = 0;

static const size_t send_buffer_size = 10000;
static char* send_buffer = NULL;
static size_t send_position = 0;
static bool send_completed = true;
static size_t send_packet_end = 0;

//-----------------------------------------------------------------------------------------
static void network_process_tcp_next_receive( )
{
    receive_completed = false;
    receive_valid = false;
    receive_packet_end = 0;
    receive_timeout = 0;
    
    if( receive_packet_end < receive_position - 1 )
    {
        memmove( receive_buffer + 0, receive_buffer + receive_packet_end  + 1, receive_position - receive_packet_end );
        receive_position -= receive_packet_end + 1;
    }
    else
    {
        receive_position = 0;
    }
}
//-----------------------------------------------------------------------------------------
static bool network_process_tcp_receive_packet( int sock )
{
    if( receive_completed )
    {
        return true;
    }

    struct sockaddr_in source_addr;
    socklen_t socklen = sizeof(source_addr);
    
    const int length_received = lwip_recvfrom( 
        sock, 
        receive_buffer + receive_position, 
        receive_buffer_size - receive_position, 
        MSG_DONTWAIT, 
        (struct sockaddr *)&source_addr, 
        &socklen 
    );
    //ESP_LOGI( TAG, "length_received = %d / errno = %d", length_received, errno );
    if( length_received < 0 )
    {
        if( errno == EAGAIN )
        {
            return true;
        }
        ESP_LOGE( TAG, "recv error: errno %d", errno );
        receive_position = 0;
        receive_completed = false;
        receive_valid = false;
        return false;
    }
    if( length_received == 0 )
    {
        if( receive_position != 0 && esp_timer_get_time() - receive_timeout > 50000 )
        {
            ESP_LOGE( TAG, "timeout" );
            receive_position = 0;
        }
        return true;
    }
    receive_timeout = esp_timer_get_time();
    receive_position += length_received;
    
    while( 1 )
    {
        size_t start = SIZE_MAX;
        size_t end = SIZE_MAX;
        
        for( size_t n = 0; n < receive_position; n++ )
        {
            if( *( receive_buffer + n ) == '\x02' )
            {
                start = n;
                end = SIZE_MAX;
            }
            if( *( receive_buffer + n ) == '\x03' )
            {
                end = n;
                if( end > start )
                {
                    break;
                }
            }
        }
        if( start == SIZE_MAX || end == SIZE_MAX )
        {
            break;
        }
        
        if( start > 0 ){
            if( start < receive_position )
            {
                memmove( receive_buffer + 0, receive_buffer + start, receive_position - start + 1 );
                receive_position -= start;
            }
            else
            {
                receive_position = 0;
            }
            end -= start;
            start = 0;
        }
        
        //---------------------------------------------------------------------------------------
        receive_completed = true;
        receive_valid = false;

        if( end - start >= 16 ){
            uint32_t crc;
            uint16_t length;
            
            sscanf( receive_buffer + 1, "%08X", &crc );
            sscanf( receive_buffer + 10, "%04hX", &length );
            
            const uint32_t crc_calculated = crc32_be( 0, (const uint8_t*)( receive_buffer + 15 ), length );
            
            //----------
            for( size_t n = 0; n < 16 + length; n++ )
            {
                if( n % 80 == 0 )
                    printf("\n");
                
                if( receive_buffer[n] > 32 && receive_buffer[n] < 127 )
                    printf("%c ", receive_buffer[n] );
                else
                    printf("<%02X> ", receive_buffer[n] );
            }
            //----------
            
            if( crc == crc_calculated )
            {
                receive_valid = true;
                receive_packet_end = end;
            }
            else 
            {
                ESP_LOGE( TAG, "crc mismatch" );
            }
        }
        //---------------------------------------------------------------------------------------
    }
    return true;
}
//-----------------------------------------------------------------------------------------
static void network_process_tcp_next_send( )
{
    send_position = 0;
    send_completed = false;
}
//-----------------------------------------------------------------------------------------
static bool network_process_tcp_send_packet( int sock )
{
    if( send_completed )
    {
        return true;
    }

    if( send_position < send_packet_end )
    {
        const struct sockaddr_in dest_addr = {
            .sin_addr.s_addr = inet_addr(HOST_IP_ADDR),
            .sin_family = AF_INET,
            .sin_port = htons(PORT)
        };

        const int length_sent = lwip_sendto( sock, send_buffer, send_packet_end - send_position, MSG_DONTWAIT, (struct sockaddr *)&dest_addr, sizeof(dest_addr) );
        if ( length_sent < 0 )
        {
            if( errno != EAGAIN )
            {
                ESP_LOGE( TAG, "send error: errno %d", errno );
                send_position = 0;
                send_completed = true;
                return false;
            }
        }
        if ( length_sent == 0 )
        {
            return true;
        }
        send_position += length_sent;
        ESP_LOGI( TAG, "sent = %u", length_sent );
    }
    if( send_position >= send_packet_end )
    {
        send_packet_end = 0;
        send_position = 0;
        send_completed = true;
    }
    return true;
}
//-----------------------------------------------------------------------------------------
static void network_tcp_prepare_send( uint16_t length )
{
    *( send_buffer + 0 ) = '\x02';
    sprintf( send_buffer + 1, "%08X", crc32_be( 0, (const uint8_t*)( send_buffer + 15 ), length ) );
    sprintf( send_buffer + 10, "%04X", length );
    *( send_buffer + 15 + length ) = '\x03';

    send_packet_end = 16 + length;

    //ESP_LOGI( TAG, "send_packet" );

    //for( size_t n = 0; n < 16 + length; n++ )
    //{
    //    if( n % 80 == 0 )
    //        printf("\n");
    //    
    //    if( send_buffer[n] > 32 && send_buffer[n] < 127 )
    //        printf("%c ", send_buffer[n] );
    //    else
    //        printf("<%02X> ", send_buffer[n] );
    //}
}
//-----------------------------------------------------------------------------------------
static void network_process_tcp_client_receive_event( game_state_t* game_state )
{
    if( xEventGroupGetBits( network_event_group ) & NETWORK_RECEIVE )
    {
        if( receive_completed )
        {
            //ESP_LOGI( TAG, "process_tcp_client_receive_event" );
            //if( receive_valid )
            //{
            //    protocol_game_from_server( game_state, receive_buffer + 15, receive_position - 16 ); 
            //}    
            //// Checa as regras -> munições / movimento
            //network_process_tcp_next_receive();
        }
        xEventGroupClearBits( network_event_group, NETWORK_RECEIVE );
        xEventGroupSetBits( network_event_group, NETWORK_RECEIVED );
    }
}
//-----------------------------------------------------------------------------------------
static void network_process_tcp_client_send_event( game_state_t* game_state )
{
    if( xEventGroupGetBits( network_event_group ) & NETWORK_SEND )
    {
        if( send_completed )
        {
            network_tcp_prepare_send( protocol_game_to_server( game_state, send_buffer + 15, send_buffer_size - 16 ) );
            // Checa as regras -> munições / movimento
            network_process_tcp_next_send();
        }
        xEventGroupClearBits( network_event_group, NETWORK_SEND );
        xEventGroupSetBits( network_event_group, NETWORK_SENT );
    }
}
//-----------------------------------------------------------------------------------------
static void network_process_tcp_client( void *pvParameters )
{
    game_state_t* game_state = pvParameters;

    const struct sockaddr_in dest_addr = {
        .sin_addr.s_addr = htonl(INADDR_ANY),
        .sin_family = AF_INET,
        .sin_port = htons(PORT)
    };

    const int client_sock = lwip_socket( AF_INET, SOCK_DGRAM, IPPROTO_IP );
    if (client_sock < 0)
    {
        ESP_LOGE(TAG, "unable to create socket: %s", lwip_strerr( errno ) );
        return;
    }
    ESP_LOGI(TAG, "socket created");
    
    //const int rcvbuf = 5000;
    //setsockopt( client_sock , SOL_SOCKET, SO_RCVBUF, &rcvbuf, sizeof(rcvbuf));
    
    const int err = lwip_bind( client_sock, (struct sockaddr *)&dest_addr, sizeof(dest_addr) );
    if (err < 0)
    {
        ESP_LOGE( TAG, "socket unable to bind: %s", lwip_strerr( errno ) );
        return;
    }
    ESP_LOGI(TAG, "socket binded");

    while(1)
    {
        xEventGroupSetBits( network_event_group, NETWORK_CONNECTED );
        while (1) {
            if( ! network_process_tcp_receive_packet( client_sock ) || ! network_process_tcp_send_packet( client_sock ) )
            {
                break;
            }
            network_process_tcp_client_receive_event( game_state );
            network_process_tcp_client_send_event( game_state );
            
            vTaskDelay( pdMS_TO_TICKS( 10 ) );
        }
        xEventGroupClearBits( network_event_group, NETWORK_CONNECTED );

        if ( client_sock != -1 ) {
            ESP_LOGE( TAG, "Shutting down socket and restarting...");
            lwip_shutdown( client_sock, 0 );
            lwip_close( client_sock );
        }
    }
    vTaskDelete( NULL );
}
//-----------------------------------------------------------------------------------------
static void network_process_tcp_server_receive_event( game_state_t* game_state )
{
    if( xEventGroupGetBits( network_event_group ) & NETWORK_RECEIVE )
    {
        if( receive_completed )
        {
            protocol_game_from_client( game_state, receive_buffer + 15, receive_position - 16 ); 
            // Checa as regras -> munições / movimento
            network_process_tcp_next_receive();
        }
        xEventGroupClearBits( network_event_group, NETWORK_RECEIVE );
        xEventGroupSetBits( network_event_group, NETWORK_RECEIVED );
    }
}
//-----------------------------------------------------------------------------------------
static void network_process_tcp_server_send_event( game_state_t* game_state )
{
    if( xEventGroupGetBits( network_event_group ) & NETWORK_SEND )
    {
        if( send_completed )
        {
            network_tcp_prepare_send( protocol_game_to_client( game_state, send_buffer + 15, send_buffer_size - 16 ) );
            // Checa as regras -> munições / movimento
            network_process_tcp_next_send();
        }
        xEventGroupClearBits( network_event_group, NETWORK_SEND );
        xEventGroupSetBits( network_event_group, NETWORK_SENT );
    }
}
//-----------------------------------------------------------------------------------------
static void network_process_tcp_server( void *pvParameters )
{
    game_state_t* game_state = pvParameters;
    
    const struct sockaddr_in dest_addr = {
        .sin_addr.s_addr = htonl(INADDR_ANY),
        .sin_family = AF_INET,
        .sin_port = htons(PORT)
    };
    
    const int server_sock = lwip_socket( AF_INET, SOCK_DGRAM, IPPROTO_IP );
    if (server_sock < 0)
    {
        ESP_LOGE( TAG, "unable to create socket: %s", lwip_strerr( errno ) );
        return;
    }
    ESP_LOGI( TAG, "socket created" );
    
    {
        const int err = lwip_bind(server_sock, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
        if (err < 0)
        {
            ESP_LOGE( TAG, "Socket unable to bind: %s", lwip_strerr( errno ) );
            return;
        }
        ESP_LOGI(TAG, "socket binded");
    }

    while(1)
    {
        xEventGroupSetBits( network_event_group, NETWORK_CONNECTED );
        while(1){
            if( ! network_process_tcp_receive_packet( server_sock ) || ! network_process_tcp_send_packet( server_sock ) )
            {
                break;
            }
            network_process_tcp_server_receive_event( game_state );
            network_process_tcp_server_send_event( game_state );
            
            vTaskDelay( pdMS_TO_TICKS( 10 ) );
        }
        xEventGroupClearBits( network_event_group, NETWORK_CONNECTED );

        if ( server_sock != -1) 
        {
            ESP_LOGE( TAG, "Shutting down socket and restarting...");
            lwip_shutdown( server_sock, 0 );
            lwip_close( server_sock );
        }

        //char* str = NULL;
        //size_t length_received = 0;
        //{
        //    game_state_t* game_state;
        //    if( xTaskNotifyWait( 0, ULONG_MAX, (uint32_t*)&game_state, portMAX_DELAY ) ){
        //        
        //        for( size_t index = 0; index < sizeof(game_state->spaceships)/sizeof(*game_state->spaceships); index++ ){
        //            game_state->spaceships[ index ].active                  = 12;
        //            game_state->spaceships[ index ].px                      = 123.456;
        //            game_state->spaceships[ index ].py                      = 123.456;
        //            game_state->spaceships[ index ].vi                      = 12.345;
        //            game_state->spaceships[ index ].vj                      = 12.345;
        //            game_state->spaceships[ index ].mode                    = 12;
        //            game_state->spaceships[ index ].life                    = 12;
        //            game_state->spaceships[ index ].collision_countdown     = 12345;
        //            game_state->spaceships[ index ].collision_active        = 12;
        //            game_state->spaceships[ index ].shield_active           = 12;
        //            game_state->spaceships[ index ].shield_animation_number = 12;
        //            game_state->spaceships[ index ].alive_timer             = 123456;
        //            game_state->spaceships[ index ].asteroids_counter       = 12345;
        //        }
        //        for( size_t index = 0; index < sizeof(game_state->asteroids)/sizeof(*game_state->asteroids); index++ ){
        //            game_state->asteroids[ index ].active                   = 12;
        //            game_state->asteroids[ index ].px                       = 123.456;
        //            game_state->asteroids[ index ].py                       = 123.456;
        //            game_state->asteroids[ index ].vi                       = 12.345;
        //            game_state->asteroids[ index ].vj                       = 12.345;
        //            game_state->asteroids[ index ].number                   = 12;
        //            game_state->asteroids[ index ].orientation              = 12;
        //            game_state->asteroids[ index ].life                     = 12;
        //            game_state->asteroids[ index ].damage_countdown         = 12345;
        //            game_state->asteroids[ index ].damage_active            = 12;
        //        }
        //        for( size_t index = 0; index < sizeof(game_state->impacts)/sizeof(*game_state->impacts); index++ ){
        //            game_state->impacts[ index ].active                     = 12;
        //            game_state->impacts[ index ].px                         = 123.456;
        //            game_state->impacts[ index ].py                         = 123.456;
        //            game_state->impacts[ index ].type                       = 12;
        //            game_state->impacts[ index ].size                       = 12;
        //            game_state->impacts[ index ].animation_number           = 12;
        //            game_state->impacts[ index ].animation_countdown        = 12345;
        //        }
        //        for( size_t index = 0; index < sizeof(game_state->projectiles)/sizeof(*game_state->projectiles); index++ ){
        //            game_state->projectiles[ index ].active                 = 12;
        //            game_state->projectiles[ index ].px                     = 123.456;
        //            game_state->projectiles[ index ].py                     = 123.456;
        //            game_state->projectiles[ index ].vi                     = 12.345;
        //            game_state->projectiles[ index ].vj                     = 12.345;
        //            game_state->projectiles[ index ].owner                  = 12;
        //            game_state->projectiles[ index ].type                   = 12;
        //            game_state->projectiles[ index ].animation_number       = 12;
        //            game_state->projectiles[ index ].animation_countdown    = 12345;
        //        }
        //        for( size_t index = 0; index < sizeof(game_state->pickups)/sizeof(*game_state->pickups); index++ ){
        //            game_state->pickups[ index ].active                     = 12;
        //            game_state->pickups[ index ].px                         = 123.456;
        //            game_state->pickups[ index ].py                         = 123.456;
        //            game_state->pickups[ index ].vi                         = 12.345;
        //            game_state->pickups[ index ].vj                         = 12.345;
        //            game_state->pickups[ index ].type                       = 12;
        //            game_state->pickups[ index ].trajectory_progress        = 12.345;
        //        }
        //        for( size_t index = 0; index < sizeof(game_state->meteors)/sizeof(*game_state->meteors); index++ ){
        //            game_state->meteors[ index ].active                     = 12;
        //            game_state->meteors[ index ].px                         = 123.456;
        //            game_state->meteors[ index ].py                         = 123.456;
        //            game_state->meteors[ index ].vi                         = 12.345;
        //            game_state->meteors[ index ].vj                         = 12.345;
        //            game_state->meteors[ index ].direction                  = 12;
        //            game_state->meteors[ index ].animation_number           = 12;
        //            game_state->meteors[ index ].animation_countdown        = 12345;
        //            game_state->meteors[ index ].arrow_active               = 12;
        //            game_state->meteors[ index ].arrow_countdown            = 12345;
        //            game_state->meteors[ index ].arrow_progress             = 12.345;
        //        }
        //        
        //        const int64_t start = esp_timer_get_time();
        //        length_received = protocol_game_to_client( &str, game_state );
        //        ////ESP_LOGI(TAG,"length_received = %zu",length_received);
        //        //puts(str);
        //        const int64_t end = esp_timer_get_time();
        //        //ESP_LOGI(TAG,"t = %lld",end-start);
        //    }
        //}
    }
    vTaskDelete(NULL);
}
//-----------------------------------------------------------------------------------------
void network_initialize_tcp_client( game_state_t* game_state )
{
    if( network_task_handle == NULL )
    {
        ESP_LOGI( TAG, "initialize_tcp_client" );
        
        receive_buffer = pvPortMalloc( receive_buffer_size );
        memset( receive_buffer, 0, receive_buffer_size );
        send_buffer = pvPortMalloc( send_buffer_size );
        memset( send_buffer, 0, send_buffer_size );
        
        network_event_group = xEventGroupCreate();
        xTaskCreatePinnedToCore( network_process_tcp_client, "network_process_tcp_client", 8192, game_state, 5, &network_task_handle, 1 );
    }
}
//-----------------------------------------------------------------------------------------
void network_initialize_tcp_server( game_state_t* game_state )
{
    if( network_task_handle == NULL )
    {
        ESP_LOGI( TAG, "initialize_tcp_server" );
        
        receive_buffer = pvPortMalloc( receive_buffer_size );
        memset( receive_buffer, 0, receive_buffer_size );
        send_buffer = pvPortMalloc( send_buffer_size );
        memset( send_buffer, 0, send_buffer_size );
        
        network_event_group = xEventGroupCreate();
        xTaskCreatePinnedToCore( network_process_tcp_server, "network_process_tcp_server", 8192, game_state, 5, &network_task_handle, 1 );
    }
}
//-----------------------------------------------------------------------------------------
void network_tcp_send( )
{
    if( network_task_handle != NULL )
    {
        if( xEventGroupGetBits( network_event_group ) & NETWORK_CONNECTED ){
            xEventGroupSetBits( network_event_group, NETWORK_SEND );
            xEventGroupWaitBits( network_event_group, NETWORK_SENT, pdTRUE, pdTRUE, portMAX_DELAY );
        }
    }
}
//-----------------------------------------------------------------------------------------
void network_tcp_receive( )
{
    if( network_task_handle != NULL )
    {   
        if( xEventGroupGetBits( network_event_group ) & NETWORK_CONNECTED ){
            xEventGroupSetBits( network_event_group, NETWORK_RECEIVE );
            xEventGroupWaitBits( network_event_group, NETWORK_RECEIVED, pdTRUE, pdTRUE, portMAX_DELAY );
        }
    }
}
//-----------------------------------------------------------------------------------------

#endif