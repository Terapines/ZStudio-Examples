#include "xcusi.h"

#include <stdio.h>

int main() {
  int Num0 = 2;
  int Num1 = 5;
  int Res;

  _CUS_ADD(Res, Num0, Num1);
  printf("cus_add res: %d\n", Res);

  return 0;
}