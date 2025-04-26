#ifndef LED_RGB_H
#define LED_RGB_H

#include "pico/stdlib.h"

#define LED_R 13
#define LED_G 11
#define LED_B 12

void SETUP_LED_RGB();
void TOGGLE_LED_COLOR(bool r, bool g, bool b);

#endif