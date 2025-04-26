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
extern ssd1306_t ssd_bm;

void SETUP_I2C();

void CLEAR_OLED();

void TEXT_ON_OLED(char *text[]);

void DRAW_BITMAP(const uint8_t *bitmap);

void DISPLAY_RENDER(char *text, int y_pos);

#endif