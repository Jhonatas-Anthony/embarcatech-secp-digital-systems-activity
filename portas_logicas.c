#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/i2c.h"

#include "src/components/led_rgb/led.h"
#include "src/components/oled/oled.h"

int main()
{
    stdio_init_all();

    // INICIALIZA LEDS
    SETUP_LED_RGB();

    // INICIALIZA OLED
    SETUP_I2C();
    CLEAR_OLED();

    while (true)
    {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}

// TOGGLE_LED_COLOR(true, false, false); -- CHAMA LED VERMELHO
// TOGGLE_LED_COLOR(false, true, false); -- CHAMA LED VERDE
