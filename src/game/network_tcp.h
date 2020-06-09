#ifndef GAME_NETWORK_TCP_H
#define GAME_NETWORK_TCP_H

//-----------------------------------------------------------------------------------------
void network_initialize_tcp_client( game_state_t* game_state );
void network_initialize_tcp_server( game_state_t* game_state );
void network_tcp_send( );
void network_tcp_receive( );
//-----------------------------------------------------------------------------------------

#endif