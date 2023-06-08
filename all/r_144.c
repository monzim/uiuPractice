

#include <stdio.h>

void main() {
  float principle, interest, time, simple_interest;

  printf("Enter the principle amount :");
  scanf("%f", &principle);

  printf("Enter the interest rate:");
  scanf("%f", &interest);

  printf("Enter the time period :");
  scanf("%f", &time);

  simple_interest = (principle * interest * time) / 100;

  printf(" The simple_interest is : %f", simple_interest);
}
