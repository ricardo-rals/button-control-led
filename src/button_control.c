#include "pico/stdlib.h"
#include "../includes/button_control.h"

void init_button(int pin, void (*callback)(uint, uint32_t)) {
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_IN);
    gpio_pull_up(pin);
    gpio_set_irq_enabled_with_callback(pin, GPIO_IRQ_EDGE_FALL, true, callback);
}
