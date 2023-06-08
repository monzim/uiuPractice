#include <stdio.h>

int main() {
  int num1 = 5;
  float num2;
  char chr = 'q';

  scanf("%f", &num2);
  num1 = (int)num2 % chr;  // Explicitly cast num2 to an int type before using the modulus operator

  printf("Result is = %d\n", num1);  // Print num1 as an integer instead of a float, and add a newline character

  return 0;
}
