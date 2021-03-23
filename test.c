#include <assert.h>
#include <math.h>
#include <stdio.h>
#include "functions.h"

#undef main
int main() {
  assert(fabs(CountRightRec(2, 30 * 3.14 / 180) - 0.475557) < 0.000001);
  assert(fabs(CountRightIter(3, 60 * 3.14 / 180) - 0.748198) < 0.000001);
  printf("Scooooooooooby-Doooooooby-Doooooo");
  return 0;
}
