#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/i2c.h"

#include "src/components/led_rgb/led.h"
#include "src/components/oled/oled.h"
#include "src/components/joystick/j.h"
#include "src/components/buttons/buttons.h"

#include "ports.h"

const char *menu_items[7] = {
    "AND",
    "OR",
    "NOT",
    "NAND",
    "NOR",
    "XOR",
    "XNOR"};

int selected_item = 0;
int last_selected_item = -1;

// PROTOTIPOS

void HANDLE_MENU();
void CHANGE_PORT();

void PL_AND(bool a, bool b);
void PL_OR(bool a, bool b);
void PL_NOT(bool a);
void PL_NAND(bool a, bool b);
void PL_NOR(bool a, bool b);
void PL_XOR(bool a, bool b);
void PL_XNOR(bool a, bool b);

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

        /* struct repeating_timer timer;
        add_repeating_timer_ms(50, JOYSTICK_CALLBACK, NULL, &timer); */

        HANDLE_MENU();
        CHANGE_PORT();

        switch (selected_item)
        {
        case 0:
            PL_AND(button_a_state, button_b_state);
            break;
        case 1:
            PL_OR(button_a_state, button_b_state);
            break;
        case 2:
            PL_NOT(button_a_state);
            break;
        case 3:
            PL_NAND(button_a_state, button_b_state);
            break;
        case 4:
            PL_NOR(button_a_state, button_b_state);
            break;
        case 5:
            PL_XOR(button_a_state, button_b_state);
            break;
        case 6:
            PL_XNOR(button_a_state, button_b_state);
            break;
        }

        sleep_ms(150);
    }
}

void HANDLE_MENU()
{
    // Leitura do eixo Y
    uint adc_y_raw = adc_read();

    // Verifica a direção do movimento e impede que o valor de selected_item seja menor que 0 ou maior que 6
    if (adc_y_raw < 100 && selected_item < 6)
    {
        selected_item++;
    }
    else if (adc_y_raw > 3900 && selected_item > 0)
    {
        selected_item--;
    }
}

void CHANGE_PORT()
{
    if (selected_item == last_selected_item) // Se não mudou, evita redesenhar
        return;

    last_selected_item = selected_item; // Atualiza o último item selecionado
    adc_select_input(0);

    switch (selected_item)
    {
    case 0:
        DRAW_BITMAP(_AND_PORT);
        break;
    case 1:
        DRAW_BITMAP(_OR_PORT);
        break;
    case 2:
        DRAW_BITMAP(_NOT_PORT);
        break;
    case 3:
        DRAW_BITMAP(_NAND_PORT);
        break;
    case 4:
        DRAW_BITMAP(_NOR_PORT);
        break;
    case 5:
        DRAW_BITMAP(_XOR_PORT);
        break;
    case 6:
        DRAW_BITMAP(_XNOR_PORT);
        break;
    }
}

////////////////////
// A // B // A B ///
// 0    0     0   //
// 0    1     0   //
// 1    0     0   //
// 1    1     1   //
////////////////////
void PL_AND(bool a, bool b)
{
    if (!a && !b)
    {
        TOGGLE_LED_COLOR(false, true, false);
    }
    else
    {
        TOGGLE_LED_COLOR(true, false, false);
    }
}

////////////////////
// A // B // A B ///
// 0    0     0   //
// 0    1     1   //
// 1    0     1   //
// 1    1     1   //
////////////////////
void PL_OR(bool a, bool b)
{
    if (!a || !b)
    {
        TOGGLE_LED_COLOR(false, true, false);
    }
    else
    {
        TOGGLE_LED_COLOR(true, false, false);
    }
}

//////////////
// A // !A ///
// 0     1  //
// 1     0  //
//////////////
void PL_NOT(bool a)
{
    if (a)
    {
        TOGGLE_LED_COLOR(false, true, false);
    }
    else
    {
        TOGGLE_LED_COLOR(true, false, false);
    }
}

////////////////////
// A // B // A B ///
// 0    0     1   //
// 0    1     1   //
// 1    0     1   //
// 1    1     0   //
////////////////////
void PL_NAND(bool a, bool b)
{
    if (!(!a && !b))
    {
        TOGGLE_LED_COLOR(false, true, false);
    }
    else
    {
        TOGGLE_LED_COLOR(true, false, false);
    }
}

////////////////////
// A // B // A B ///
// 0    0     1   //
// 0    1     0   //
// 1    0     0   //
// 1    1     0   //
////////////////////
void PL_NOR(bool a, bool b)
{
    if (!(!a || !b))
    {
        TOGGLE_LED_COLOR(false, true, false);
    }
    else
    {
        TOGGLE_LED_COLOR(true, false, false);
    }
}

////////////////////
// A // B // A B ///
// 0    0     1   //
// 0    1     0   //
// 1    0     0   //
// 1    1     1   //
////////////////////
void PL_XOR(bool a, bool b)
{
    if (!(a ^ b))
    {
        TOGGLE_LED_COLOR(false, true, false);
    }
    else
    {
        TOGGLE_LED_COLOR(true, false, false);
    }
}

////////////////////
// A // B // A B ///
// 0    0     0   //
// 0    1     1   //
// 1    0     1   //
// 1    1     0   //
////////////////////
void PL_XNOR(bool a, bool b)
{
    if (!a ^ !b)
    {
        TOGGLE_LED_COLOR(false, true, false);
    }
    else
    {
        TOGGLE_LED_COLOR(true, false, false);
    }
}
// TOGGLE_LED_COLOR(true, false, false); -- CHAMA LED VERMELHO
// TOGGLE_LED_COLOR(false, true, false); -- CHAMA LED VERDE
