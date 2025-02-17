#include <stdio.h>
#include <stdlib.h>
#include "coremark.h"

#include "riscv_common.h"

#ifndef SystemCoreClock
#define SystemCoreClock 1024000
#endif // SystemCoreClock

#if VALIDATION_RUN
volatile ee_s32 seed1_volatile = 0x3415;
volatile ee_s32 seed2_volatile = 0x3415;
volatile ee_s32 seed3_volatile = 0x66;
#endif

#if PERFORMANCE_RUN
volatile ee_s32 seed1_volatile = 0x0;
volatile ee_s32 seed2_volatile = 0x0;
volatile ee_s32 seed3_volatile = 0x66;
#endif

#if PROFILE_RUN
volatile ee_s32 seed1_volatile = 0x8;
volatile ee_s32 seed2_volatile = 0x8;
volatile ee_s32 seed3_volatile = 0x8;
#endif

volatile ee_s32 seed4_volatile = ITERATIONS;
volatile ee_s32 seed5_volatile = 0;

static CORE_TICKS t0, t1;
static CORE_TICKS i0, i1;

void start_time(void)
{
    t0 = __get_rv_cycle();
}

void stop_time(void)
{
    t1 = __get_rv_cycle();
}

CORE_TICKS get_time(void)
{
    return t1 - t0;
}

void start_instret(void)
{
    i0 = __get_rv_instret();
}

void stop_instret(void)
{
    i1 = __get_rv_instret();
}

CORE_TICKS get_instret(void)
{
    return i1 - i0;
}

secs_ret time_in_secs(CORE_TICKS ticks)
{
    // scale timer down to avoid uint64_t -> double conversion in RV32
    int scale = 256;
    uint64_t delta = ticks / scale;
    uint64_t freq = SystemCoreClock / scale;
    return delta / (double)freq;
}
