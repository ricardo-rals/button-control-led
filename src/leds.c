#include "pico/stdlib.h"
#include "../includes/leds.h"

#define LED1_GPIO 13
#define LED2_GPIO 12
#define LED3_GPIO 11

static int led_state = 0;

void leds_init() {
    gpio_init(LED1_GPIO);
    gpio_init(LED2_GPIO);
    gpio_init(LED3_GPIO);

    gpio_set_dir(LED1_GPIO, GPIO_OUT);
    gpio_set_dir(LED2_GPIO, GPIO_OUT);
    gpio_set_dir(LED3_GPIO, GPIO_OUT);
}

void leds_turn_on_all() {
    gpio_put(LED1_GPIO, 1);
    gpio_put(LED2_GPIO, 1);
    gpio_put(LED3_GPIO, 1);
    led_state = 7;
}

void leds_turn_off_all() {
    gpio_put(LED1_GPIO, 0);
    gpio_put(LED2_GPIO, 0);
    gpio_put(LED3_GPIO, 0);
    led_state = 0;
}

void leds_toggle() {
    if (led_state == 7) {
        leds_turn_on_two();
    } else if (led_state == 3) {
        leds_turn_on_one();
    } else {
        leds_turn_off_all();
    }
}

void leds_turn_on_two() {
    gpio_put(LED1_GPIO, 1);
    gpio_put(LED2_GPIO, 1);
    gpio_put(LED3_GPIO, 0);
    led_state = 3;
}

void leds_turn_on_one() {
    gpio_put(LED1_GPIO, 1);
    gpio_put(LED2_GPIO, 0);
    gpio_put(LED3_GPIO, 0);
    led_state = 1; 
}
