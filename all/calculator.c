
#include <stdio.h>

int main() {
  int f1, f2, index, lim;
  float val, sum, avg;
  scanf("%d", &f1);
  for (index = 1; index <= f1; index++) {
    scanf("%d", &f2);
    sum = 0;
    for (lim = 1; lim <= f2; lim++) {
      scanf("%f", &val);
      sum = sum + val;
    }
    avg = sum / f2;
    printf("Case %d: %.3f \n", index, avg);
  }
  return 0;
}