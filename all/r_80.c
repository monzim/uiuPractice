

#include <stdio.h>
void main() {
  int num1;
  float num2, result;

  printf("Enter the first number:");
  scanf("%d", &num1);

  printf("Enter the second number:");
  scanf("%f", &num2);

  result = num1 + num2;

  printf("The sum is %f ", result);
}
