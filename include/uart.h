#ifndef __UART_H_
#define __UART_H_

#include "base_address.h"
#include "gpio.h"

typedef struct
{
    r32 dr;
    r32 rsrecr;
    r8 reserved0[0x10];

    r32 fr;
    r8 reserved1[0x08];

    r32 ibrd;
    r32 fbrd;
    r32 lcrh;
    r32 cr;
    r32 ifls;
    r32 imsc;
    r32 ris;
    r32 mis;
    r32 icr;
    r32 dmacr;
    r8 reserved2[0x38];

    r32 itcr;
    r32 itip;
    r32 itop;
    r32 tdr;
} uart_reg;

#endif
