#include <stdio.h>

typedef unsigned long long ticks;

#define __RISCV_XLEN 64
#define CSR_MCYCLE 0xb00
#define CSR_MINSTRET 0xb02

#define STR(x) XSTR(x)
#define XSTR(x) #x
#define __STR(s) #s
#define STRINGIFY(s) __STR(s)

#define __RV_CSR_READ(csr)                                                     \
  ({                                                                           \
    register ticks __v;                                                        \
    __asm volatile("csrr %0, " STRINGIFY(csr) : "=r"(__v) : : "memory");       \
    __v;                                                                       \
  })

ticks _Time0, _Time1;
ticks inst0, inst1;

// Only for RISCV
#define ROI_BEGIN()                                                            \
  inst0 = __RV_CSR_READ(CSR_MINSTRET);                                         \
  _Time0 = __RV_CSR_READ(CSR_MCYCLE);

#define ROI_END()                                                              \
  _Time1 = __RV_CSR_READ(CSR_MCYCLE);                                          \
  inst1 = __RV_CSR_READ(CSR_MINSTRET);
