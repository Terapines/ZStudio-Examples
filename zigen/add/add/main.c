#include "xsingularadd.h"

#include <stdio.h>

int main() {
  int Num0 = 2;
  int Num1 = 5;
  int Res;

  _SINGULAR_ADD(Res, Num0, Num1);
  printf("singular_add res: %d\n", Res);

  return 0;
}