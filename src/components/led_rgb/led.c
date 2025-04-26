#include "led.h"

// Função de inicialização

void SETUP_LED_RGB()
{
    gpio_init(LED_R);
    gpio_init(LED_G);
    gpio_init(LED_B);

    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_set_dir(LED_B, GPIO_OUT);
}

void TOGGLE_LED_COLOR(bool r, bool g, bool b)
{
    gpio_put(LED_R, r);
    gpio_put(LED_G, g);
    gpio_put(LED_B, b);
}


// Ligar LED_RGB