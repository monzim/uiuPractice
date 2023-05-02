#include <stdio.h>

int main() {
  int num1 = 5;
  float num2;
  char chr = 'q';

  scanf("%f", &num2);
  num1 = (int)num2 % chr;

  printf("Result is = %d\n", num1);

  return 0;
}
