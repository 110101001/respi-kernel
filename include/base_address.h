#ifndef __BASE_ADDRESS_H_
#define __BASE_ADDRESS_H_

#define PERIPHERAL_BASE_PHY 0x47C000000
#define PERIPHERAL_BASE_LMA 0x7C000000

#define LMA2PHY(addr) (addr) - PERIPHERAL_BASE_LMA + PERIPHERAL_BASE_PHY

#define GPIO_BASE LMA2PHY(0x7E215000)
#define UART0_BASE LMA2PHY(0x7E201000)

typedef volatile unsigned int r32;
typedef volatile unsigned char r8;

#endif