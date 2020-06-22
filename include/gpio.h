#ifndef __GPIO_H_
#define __GPIO_H_

#include "mmio.h"

#define GPIO_BASE LMA2PHY(0x7E215000)

typedef unsigned char pin_t;

typedef struct
{
    r32 gpfsel[6];
    r8 reserved0[0x04];

    r32 gpset[2];
    r8 reserved1[0x04];

    r32 gplev[2];
    r8 reserved2[0x04];

    r32 gpeds[2];
    r8 reserved3[0x04];

    r32 gpren[2];
    r8 reserved4[0x04];

    r32 gpfen[2];
    r8 reserved5[0x04];

    r32 gphen[2];
    r8 reserved6[0x04];

    r32 gplen[2];
    r8 reserved7[0x04];

    r32 gparen[2];
    r8 reserved8[0x04];

    r32 gpafen[2];
    r8 reserved9[0x04];

    r32 gppupr[4]; // short for GPIO_PUP_PDN_CNTRL_REG
} gpio_t;

gpio_t *gpio=(gpio_t *)GPIO_BASE;

void gpio_select_func(pin_t pin, u8 func);

#endif
