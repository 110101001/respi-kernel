#ifndef __GPIO_H_
#define __GPIO_H_

#include "base_address.h"

typedef struct
{
    r32 gpfsel0;
    r32 gpfsel1;
    r32 gpfsel2;
    r32 gpfsel3;
    r32 gpfsel4;
    r32 gpfsel5;
    r8 reserved0[0x04];

    r32 gpset0;
    r32 gpset1;
    r8 reserved1[0x04];

    r32 gplev0;
    r32 gplev1;
    r8 reserved2[0x04];

    r32 gpeds0;
    r32 gpeds1;
    r8 reserved3[0x04];

    r32 gpren0;
    r32 gpren1;
    r8 reserved4[0x04];

    r32 gpfen0;
    r32 gpfen1;
    r8 reserved5[0x04];

    r32 gphen0;
    r32 gphen1;
    r8 reserved6[0x04];

    r32 gplen0;
    r32 gplen1;
    r8 reserved7[0x04];

    r32 gparen0;
    r32 gparen1;
    r8 reserved8[0x04];

    r32 gpafen0;
    r32 gpafen1;
    r8 reserved9[0x04];

    r32 gppupr0; // short for GPIO_PUP_PDN_CNTRL_REG0
    r32 gppupr1;
    r32 gppupr2;
    r32 gppupr3;
} gpio_reg;

#endif
