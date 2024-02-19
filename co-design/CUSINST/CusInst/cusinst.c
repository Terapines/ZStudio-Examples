#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/_stdint.h>

#include "input1_q15.h"
#include "input2_q15.h"
#include "xcusacc.h"

#define TEST_M 10
#define TEST_K 10
#define TEST_N 10

typedef int16_t q15_t;
typedef int64_t q33_30_t;

__attribute__((noinline)) static int32_t __SSAT(int32_t aValue, uint32_t aBits)
{
  if (aBits >= 1U && aBits <= 32U)
  {
    int32_t max = (1 << (aBits - 1U)) - 1;
    int32_t min = -1 - max;

    if (aValue > max)
      return max;
    //    aValue = max;
    else if (aValue < min)
      return min;
    //    aValue = min;
  }

  return aValue;
}

__attribute__((noinline)) void tpt_mat_cmplx_mult_q15(q15_t *aOutMat, const q15_t *aInMatA,
                            const q15_t *aInMatB, uint16_t aM, uint16_t aK,
                            uint16_t aN)
{
  for (uint16_t row = 0; row < aM; ++row)
  {
    for (uint16_t col = 0; col < aN; ++col)
    {
      q33_30_t sum_r = 0;
      q33_30_t sum_i = 0;
      const q15_t *p_in1 = &aInMatA[2 * ((uint32_t)row * aK)];
      const q15_t *p_in2 = &aInMatB[2 * col];

      for (uint16_t i = 0; i < aK; ++i)
      {
        int32_t a = ((int32_t *)p_in1)[0];
        int32_t b = ((int32_t *)p_in2)[0];
        int32_t tmp;

        _ZSMDRS(tmp, a, b);
        sum_r += tmp;
        _ZKMXDA(tmp, a, b);
        sum_i += tmp;

        p_in1 += 2;
        p_in2 += 2 * aN;
      }

      *aOutMat++ = __SSAT(sum_r >> 15U, 16);
      *aOutMat++ = __SSAT(sum_i >> 15U, 16);
    }
  }
}

#ifdef DUMP
#define dump(data, n)           \
  for (int i = 0; i < (n); ++i) \
    printf("%x \n", (data)[i]);
#else
#define dump(data, n) do {} while (0)
#endif // DUMP

static q15_t output_q15[TEST_M * TEST_N * 2];

#define test_mat_cmplx_mult_q15(out, in1, in2, rows, k, cols) \
  tpt_mat_cmplx_mult_q15(out, in1, in2, rows, k, cols)

int main(void)
{
  test_mat_cmplx_mult_q15(output_q15, input1_q15, input2_q15, TEST_M, TEST_K,
                          TEST_N);
  dump(output_q15, 20);
  return 0;
}
