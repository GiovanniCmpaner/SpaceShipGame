#ifndef GAME_H
#define GAME_H

typedef enum {
    GAME_OFFLINE,
    GAME_SERVER,
    GAME_CLIENT
} game_mode_t;

void game_initialize( game_mode_t mode );
void game_terminate();

#endif