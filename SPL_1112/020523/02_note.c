#include <stdio.h>

int main(int argc, char *argv[]) {
  float amount;
  int fiveHun, hundred, fifty, twenty, ten, five, two, one;

  printf("Enter the amount: ");
  scanf("%f", &amount);

  fiveHun = amount / 500;
  amount = amount - fiveHun * 500;

  hundred = amount / 100;
  amount = amount - hundred * 100;

  fifty = amount / 50;
  amount = amount - fifty * 50;

  twenty = amount / 20;
  amount = amount - twenty * 20;

  ten = amount / 10;
  amount = amount - ten * 10;

  five = amount / 5;
  amount = amount - five * 5;

  two = amount / 2;
  amount = amount - two * 2;

  one = amount / 1;
  amount = amount - one * 1;

  printf("is: \n");
  printf("500: %d \n", fiveHun);
  printf("100: %d \n", hundred);
  printf("50: %d \n", fifty);
  printf("20: %d \n", twenty);
  printf("10: %d \n", ten);
  printf("5: %d \n", five);
  printf("2: %d \n", two);
  printf("1: %d \n", one);

  return 0;
}
