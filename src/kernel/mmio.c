#include "mmio.h"

inline void mmio_write(r32 *reg, u32 data)
{
    *reg = data;
}

inline u32 mmio_read(r32 reg)
{
    return reg;
}
