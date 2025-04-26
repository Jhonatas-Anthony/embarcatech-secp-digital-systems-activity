#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/i2c.h"

#include "src/components/led_rgb/led.h"
#include "src/components/oled/oled.h"
#include "src/components/joystick/j.h"
#include "src/components/buttons/buttons.h"

int main()
{
    stdio_init_all();

    // INICIALIZA LEDS
    SETUP_LED_RGB();

    // INICIALIZA OLED
    SETUP_I2C();
    CLEAR_OLED();

    // INICIALIZA JOYSTICK
    SETUP_JOYSTICK();

    // INICIALIZA BOTOES
    SETUP_BUTTONS();

    while (true)
    {
        bool button_a_state = gpio_get(B_A);
        bool button_b_state = gpio_get(B_B);

        TOGGLE_LED_COLOR(true, false, false);

        if (!button_a_state && !button_b_state) {
            TOGGLE_LED_COLOR(false, true, false);
        }
        sleep_ms(50);
    }
}

// TOGGLE_LED_COLOR(true, false, false); -- CHAMA LED VERMELHO
// TOGGLE_LED_COLOR(false, true, false); -- CHAMA LED VERDE
