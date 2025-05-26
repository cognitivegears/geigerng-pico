#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/irq.h"

#define GEIGER_PIN 2

volatile uint16_t random_value = 0;

void interrupt_handler()
{
    printf("%u\n", random_value);
    gpio_acknowledge_irq(GEIGER_PIN, GPIO_IRQ_EDGE_RISE);
}

void init()
{
    stdio_init_all();
    gpio_init(GEIGER_PIN);
    gpio_set_dir(GEIGER_PIN, GPIO_IN);
    gpio_pull_down(GEIGER_PIN); // Enable pull-down resistor
    gpio_set_irq_enabled_with_callback(GEIGER_PIN, GPIO_IRQ_EDGE_RISE, true, &interrupt_handler);
}

int main()
{
    // Initialize the Pico
    init();

    while (true)
    {
        random_value++;
    }
}
