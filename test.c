#include <assert.h>
#include <math.h>
#include <stdio.h>
#include "functions.h"

#undef main
int main() {
  printf("\n\n %f \n\n", fabs(CostOfTheDistillation(10) - 15.55));
  assert(fabs(CostOfTheDistillation(10) - 15.55) < 0.01);
  
  printf("\n\n %f \n\n", fabs(CostOfTheCustoms(2, 3300) - 3.73));
  assert(fabs(CostOfTheCustoms(2, 3300) - 3.73) < 0.01);
  
  printf("\n\n %f \n\n", fabs(TotalCostInByn(10000, 10, 2, 3300) - 31119.28));
  assert(fabs(TotalCostInByn(10000, 10, 2, 3300) - 31119.28) < 0.01);
  return 0;
}
