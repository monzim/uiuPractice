#include <stdio.h>
#include <stdlib.h>

int sum(int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int value;
    scanf("%i", &value);
    sum += value;
  }
  return sum;
}

int main(int argc, char *argv[]) {
  int value;
  scanf("%i", &value);

  int result = sum(value);
  printf("Sum In Function: %i", result);
  printf("Sum In Main: %i", result);

  return EXIT_SUCCESS;
}