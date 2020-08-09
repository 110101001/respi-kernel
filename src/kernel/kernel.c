#include <stdint.h>
#include "uart.h"

void kernel_main(uint32_t r0, uint32_t r1, uint32_t atags)
{
    (void) r0;
    (void) r1;
    (void) atags;

    uart_t *u = UART0_BASE;

    uart_init(u);
    uart_puts(u,"Hello, kernel World!\r\n");

    while (1) {
        uart_putc(u,uart_getc(u));
        uart_putc(u,'\n');
    }
}
