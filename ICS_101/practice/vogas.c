#include <stdio.h>

void main() {
  int num1, num2;

  printf("Please Enter two numbers: ");
  scanf("%d %d", &num1, &num2);

  // Multiplication
  int product = num1 * num2;
  printf("Multiplication of %d x %d = %d\n", num1, num2, product);

  // Division
  float division = num2 / num1;
  printf("Division of %d / %d = %f\n", num2, num1, division);

  // Reminder
  float reminder = num2 % num1;
  printf("Reminder of %d %% %d = %f\n", num2, num1, division);

  printf("Division: %.0f.%.0f", division, reminder);
}