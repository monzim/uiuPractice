#include <stdio.h>

void main() {
  // TODO: get a number and do the power of that number
  int input, power;

  int output = 1;

  // Get base number input from user
  printf("Enter a base number: ");
  scanf("%d", &input);

  // Get Power input
  printf("Enter power (must positive int): ");
  scanf("%d", &power);

  if (power < 0) {
    printf("Power must be positive integer");
    return;
  }

  // // With for loop
  // for (int i = 0; i < power; i++) {
  //   output *= input;
  // }

  // With while loop
  // PROBLEM: With while loop, It will make power 0 and to print the power in
  // ans we need copy the power value to another variable
  int inputPower = power;

  while (power > 0) {
    output *= input;
    power--;
  }

  printf("\n%d to the power of %d is %d", input, inputPower, output);
  printf("\n%d ^ %d = %d", input, inputPower, output);
}