#ifndef ENTRADA_H
#define ENTRADA_H

typedef enum {
    ACTION_UP = 0,
    ACTION_LEFT = 1,
    ACTION_RIGHT = 2,
    ACTION_DOWN = 3
} action_t;

void input_initialize();
void input_on();
void input_off();
bool input_directions( double* x, double* y );
bool input_action( uint8_t n, uint8_t* level );

#endif