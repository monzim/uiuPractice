#include <math.h>
#include <stdio.h>

void main(void) {
  float num1, num2;
  char operator;

  printf("Enter two numbers: ");
  scanf("%f %f", &num1, &num2);

  printf("Enter an operator (+, -, *, /, ^, sqrt): ");
  scanf(" %c", &operator);

   if (operator== '+') {
    printf("%f + %f = %f", num1, num2, num1 + num2);
  } else if (operator== '-') {
    printf("%f - %f = %f", num1, num2, num1 - num2);
  } else if (operator== '*') {
    printf("%f * %f = %f", num1, num2, num1 * num2);
  } else if (operator== '/') {
    printf("%f / %f = %f", num1, num2, num1 / num2);
  } else if (operator== '^') {
    printf("%f ^ %f = %f", num1, num2, pow(num1, num2));
  } else if (operator== 's') {
    printf("sqrt(%f) = %f", num1, sqrt(num1));
  } else {
    printf("Error! operator is not correct");
  }
}