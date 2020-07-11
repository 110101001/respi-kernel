#include "uart.h"
#include "gpio.h"

void uart_init(uart_t *u)
{
    mmio_write(&u->cr, 0x00000000);

    gpio_select_func(36,2);
    gpio_select_func(37,2);

    mmio_write(&u->icr, 0x7FF);

    mmio_write(&u->ibrd, 1);
    mmio_write(&u->fbrd, 40);

    mmio_write(&u->lcrh, (1 << 4) | (1 << 5) | (1 << 6));

    mmio_write(&u->imsc, (1 << 1) | (1 << 4) | (1 << 5) | (1 << 6) |
            (1 << 7) | (1 << 8) | (1 << 9) | (1 << 10));

    mmio_write(&u->cr, (1 << 0) | (1 << 8) | (1 << 9));
}