#include "j.h"

void SETUP_JOYSTICK(){
    adc_init();
    // Make sure GPIO is high-impedance, no pullups etc
    adc_gpio_init(VRX);
    adc_gpio_init(VRY);
}