#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/i2c.h"

#include "src/components/led_rgb/led.h"

int main()
{
    stdio_init_all();

    // INICIALIZA LEDS
    SETUP_LED_RGB();

    while (true)
    {
        printf("Hello, world!\n");
        // TOGGLE_LED_COLOR(true, false, false); -- CHAMA LED VERMELHO
        // sleep_ms(1000);
        // TOGGLE_LED_COLOR(false, true, false); -- CHAMA LED VERDE
        sleep_ms(1000);
    }
}
