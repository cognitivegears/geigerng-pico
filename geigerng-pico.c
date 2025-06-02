#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/irq.h"

#define GEIGER_PIN 20

volatile uint16_t current_value = 0;
volatile uint32_t interrupt_count = 0;

void interrupt_handler()
{
    // Acknowledge interrupt first
    gpio_acknowledge_irq(GEIGER_PIN, GPIO_IRQ_EDGE_RISE);

    // Increment counter to trigger the interrupt
    interrupt_count++;
}

void init()
{
    stdio_init_all();

    gpio_init(GEIGER_PIN);
    gpio_set_dir(GEIGER_PIN, GPIO_IN);
    gpio_pull_down(GEIGER_PIN);

    gpio_set_irq_enabled_with_callback(GEIGER_PIN, GPIO_IRQ_EDGE_RISE,
        true, &interrupt_handler);
}

int main()
{
    init();

    uint32_t last_interrupt_count = 0;
    bool last_gpio_state = false;

    while (true) {

        if (interrupt_count != last_interrupt_count) {
            // Print current_value as a series of binary digits
            for(int i = 15; i >= 0; i--) {
                printf("%d", (current_value >> i) & 1);
            }
            last_interrupt_count = interrupt_count;
        }

        current_value++;
    }
}
