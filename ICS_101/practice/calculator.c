#include <stdio.h>

void main() {
  int num1, num2;
  char operator;

  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);

  printf("Enter an operator (+, -, *, /): ");
  scanf(" %c", &operator);

  // Do this with if-else
  if (operator== '+') {
    printf("%d + %d = %d", num1, num2, num1 + num2);
  } else if (operator== '-') {
    printf("%d - %d = %d", num1, num2, num1 - num2);
  } else if (operator== '*') {
    printf("%d * %d = %d", num1, num2, num1 * num2);
  } else if (operator== '/') {
    printf("%d / %d = %d", num1, num2, num1 / num2);
  } else {
    printf("Error! operator is not correct");
  }
}