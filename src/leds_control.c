#include "pico/stdlib.h"
#include "../includes/leds_control.h"

#define LED1_PIN 11
#define LED2_PIN 12
#define LED3_PIN 13

void init_leds() {
    gpio_init(LED1_PIN);
    gpio_init(LED2_PIN);
    gpio_init(LED3_PIN);

    gpio_set_dir(LED1_PIN, GPIO_OUT);
    gpio_set_dir(LED2_PIN, GPIO_OUT);
    gpio_set_dir(LED3_PIN, GPIO_OUT);
}

void update_leds(int state) {
    switch (state) {
        case 0:
            gpio_put(LED1_PIN, 1);
            gpio_put(LED2_PIN, 1);
            gpio_put(LED3_PIN, 1);
            break;
        case 1:
            gpio_put(LED1_PIN, 0);
            gpio_put(LED2_PIN, 1);
            gpio_put(LED3_PIN, 1);
            break;
        case 2:
            gpio_put(LED1_PIN, 0);
            gpio_put(LED2_PIN, 0);
            gpio_put(LED3_PIN, 1);
            break;
        case 3:
            gpio_put(LED1_PIN, 0);
            gpio_put(LED2_PIN, 0);
            gpio_put(LED3_PIN, 0);
            break;
    }
}
