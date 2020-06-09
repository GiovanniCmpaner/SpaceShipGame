#ifndef GAME_NETWORK_H
#define GAME_NETWORK_H

#include "object.h"

typedef enum {
    NETWORK_CLIENT,
    NETWORK_SERVER
} network_mode_t;

typedef enum {
    NETWORK_TCP,
    NETWORK_UDP
} network_type_t;

void network_initialize( network_mode_t mode, network_type_t type, game_state_t* game_state );
void network_terminate();
void network_send();
void network_receive();

#endif