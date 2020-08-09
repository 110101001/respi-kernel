#include "uart.h"
#include "gpio.h"

const int uart_tx_pins[]={
    36,
    32,
    0,
    4,
    8,
    12,
};

const int uart_rx_pins[]={
    37,
    33,
    1,
    5,
    9,
    13,
};

const int uart_tx_pins_func[]={
    2,
    5,
    4,
    4,
    4,
    4,
};

const int uart_rx_pins_func[]={
    2,
    5,
    4,
    4,
    4,
    4,
};

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

void uart_putc(uart_t *u,unsigned char c)
{
    while ( mmio_read(&u->fr) & (1 << 5) ) { }
    mmio_write(&u->dr, c);
}

unsigned char uart_getc(uart_t *u)
{
    while ( mmio_read(&u->fr) & (1 << 4) ) { }
    return mmio_read(&u->dr);
}

void uart_puts(uart_t *u,const char* str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
        uart_putc(u,(unsigned char)str[i]);
}