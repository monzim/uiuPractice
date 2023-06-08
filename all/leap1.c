#include <stdio.h>

int main(int argc, char *argv[]) {
  /*
  A year is a leap year if it is divisible by 4 and
  not divisible by 100 or if it is divisible by 400.
  */

  int year;
  printf("Enter a year: ");
  scanf("%d", &year);

  _Bool isLeapYear = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
  printf("The year is %sa leap year.\n", isLeapYear ? "" : "not ");
  return 0;
}
