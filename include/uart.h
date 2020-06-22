#ifndef __UART_H_
#define __UART_H_

#include "mmio.h"
#include "gpio.h"

#define UART0_BASE LMA2PHY(0x7E201000)
//UART1 is not PL011 UARTS
#define UART2_BASE LMA2PHY(0x7E201400)
#define UART3_BASE LMA2PHY(0x7E201600)
#define UART4_BASE LMA2PHY(0x7E201800)
#define UART5_BASE LMA2PHY(0x7E201A00)

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
} uart_t;



#endif
