#include "buttons.h"

void SETUP_BUTTONS(){
    gpio_init(B_A);
    gpio_init(B_B);

    gpio_set_dir(B_A, GPIO_IN);
    gpio_set_dir(B_B, GPIO_IN);

    gpio_pull_up(B_A);
    gpio_pull_up(B_B);
}