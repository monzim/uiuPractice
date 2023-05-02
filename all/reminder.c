#include <stdio.h>

int main(void) {
  int num1, num2, reminder;

  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);

  reminder = num1 % num2;

  printf("Reminder of %d and %d is %d", num1, num2, reminder);

  return 0;
}