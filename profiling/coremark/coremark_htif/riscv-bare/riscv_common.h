#include <stdint.h>

#define CSR_MINSTRET 0xb02
#define CSR_MCYCLE 0xb00
#define CSR_MCYCLEH 0xb80
#define CSR_MINSTRETH 0xb82

#define STR(x)                  XSTR(x)
#define XSTR(x)                 #x
#define __STR(s)                #s
#define STRINGIFY(s)            __STR(s)
typedef unsigned long long ticks;

#define __RV_CSR_READ(csr)                                      \
    ({                                                          \
        register ticks __v;                                  \
        __asm volatile("csrr %0, " STRINGIFY(csr)               \
                     : "=r"(__v)                                \
                     :                                          \
                     : "memory");                               \
        __v;                                                    \
    })

static inline uint64_t __get_rv_instret(void)
{
#if __RISCV_XLEN == 32
    volatile uint32_t high0, low, high;
    uint64_t full;

    high0 = __RV_CSR_READ(CSR_MINSTRETH);
    low = __RV_CSR_READ(CSR_MINSTRET);
    high = __RV_CSR_READ(CSR_MINSTRETH);
    if (high0 != high) {
        low = __RV_CSR_READ(CSR_MINSTRET);
    }
    full = (((uint64_t)high) << 32) | low;
    return full;
#elif __RISCV_XLEN == 64
    return (uint64_t)__RV_CSR_READ(CSR_MINSTRET);
#else // TODO Need cover for XLEN=128 case in future
    return (uint64_t)__RV_CSR_READ(CSR_MINSTRET);
#endif
}

static inline uint64_t __get_rv_cycle(void)
{
#if __RISCV_XLEN == 32
    volatile uint32_t high0, low, high;
    uint64_t full;

    high0 = __RV_CSR_READ(CSR_MCYCLEH);
    low = __RV_CSR_READ(CSR_MCYCLE);
    high = __RV_CSR_READ(CSR_MCYCLEH);
    if (high0 != high) {
        low = __RV_CSR_READ(CSR_MCYCLE);
    }
    full = (((uint64_t)high) << 32) | low;
    return full;
#elif __RISCV_XLEN == 64
    return (ticks)__RV_CSR_READ(CSR_MCYCLE);
#else // TODO Need cover for XLEN=128 case in future
    return (uint64_t)__RV_CSR_READ(CSR_MCYCLE);
#endif
}
