#ifndef GAME_protocol_H
#define GAME_protocol_H

void protocol_game_from_server( game_state_t* game_state, const char* buffer, size_t length );
size_t protocol_game_to_client  ( const game_state_t* game_state, char* buffer, size_t length );
void protocol_game_from_client( game_state_t* game_state, const char* buffer, size_t length );
size_t protocol_game_to_server  ( const game_state_t* game_state, char* buffer, size_t length );

#endif