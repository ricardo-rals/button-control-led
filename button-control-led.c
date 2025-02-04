#include "pico/stdlib.h"
#include "./includes/leds_control.h"
#include "./includes/button_control.h"

#define BUTTON_PIN 5

volatile bool button_pressed = false;
volatile bool leds_active = false;
volatile int led_state = 0;

void button_callback(uint gpio, uint32_t events) {
    if (!leds_active) {
        button_pressed = true;
    }
}

int main() {
    stdio_init_all();
    
    init_leds();
    init_button(BUTTON_PIN, button_callback);

    uint64_t last_time = 0;

    while (true) {
        if (button_pressed) {
            button_pressed = false;
            leds_active = true;
            led_state = 0;
            update_leds(led_state);
            last_time = to_ms_since_boot(get_absolute_time());
        }

        if (leds_active) {
            uint64_t current_time = to_ms_since_boot(get_absolute_time());
            if (current_time - last_time >= 3000) {
                led_state++;
                if (led_state > 3) {
                    leds_active = false;
                }
                update_leds(led_state);
                last_time = current_time;
            }
        }

        sleep_ms(10);
    }
}
