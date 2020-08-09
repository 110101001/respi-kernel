#ifndef __MMIO_H_
#define __MMIO_H_

#include "types.h"

#define PERIPHERAL_BASE_PHY 0x47C000000
#define PERIPHERAL_BASE_LMA 0x7C000000

#define LMA2PHY(addr)  (void *)((addr) - PERIPHERAL_BASE_LMA + PERIPHERAL_BASE_PHY)

#define REG_EMPTYBIT(reg, bit, len) (reg) &= ~(((1 << len) - 1) << (bit))
#define REG_SETBIT(reg, bit, data) (reg) |= data << (bit)

void mmio_write(r32 *reg, u32 data);
u32 mmio_read(r32 *addr);

#endif