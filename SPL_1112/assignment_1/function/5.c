#include <stdio.h>
#include <stdlib.h>

int whichIsGreater(int num1, int num2) {
  if (num1 > num2) {
    return 1;
  } else if (num1 < num2) {
    return -1;
  } else {
    return 0;
  }
}

int main(int argc, char *argv[]) {
  int value;
  scanf("%i", &value);

  int value2;
  scanf("%i", &value2);

  int result = whichIsGreater(value, value2);

  if (result == 1) {
    printf("%i G%i", value, value2);
  } else if (result == -1) {
    printf("%i L %i", value, value2);
  } else {
    printf("%i E %i", value, value2);
  }

  return EXIT_SUCCESS;
}