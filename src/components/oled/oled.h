#ifndef OLED_H
#define OLED_H

#include "pico/stdlib.h"
#include <string.h>
#include "../../external_libs/inc/ssd1306.h"
#include "hardware/i2c.h"

#define I2C_SDA 14
#define I2C_SCL 15

extern uint8_t ssd[ssd1306_buffer_length];
extern struct render_area frame_area;

void SETUP_I2C();

void CLEAR_OLED();

void TEXT_ON_OLED(char *text[]);

// escreve painel

// desenha painel

#endif