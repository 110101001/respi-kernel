#include "gpio.h"

const u8 func2bit[6] = {
    0x4,
    0x5,
    0x6,
    0x7,
    0x3,
    0x2,
};

void gpio_select_func(pin_t pin, u8 func)
{
    r32 gpfsel = mmio_read(gpio->gpfsel[pin/10]);
    REG_EMPTYBIT(gpfsel,3*pin%10,3);
    REG_SETBIT(gpfsel,3*pin%10,func2bit[func]);
    mmio_write(&gpio->gpfsel[pin/10],gpfsel);
}