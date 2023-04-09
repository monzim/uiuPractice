#include <stdio.h>
#include <stdlib.h>

void checkEvenOrOdd(int num) {
   if (num % 2 == 0) {
    printf("even");
  } else {
    printf("odd");
  }
}

int main(int argc, char *argv[]) {
  int value;
  scanf("%i", &value);

  checkEvenOrOdd(value);

  return EXIT_SUCCESS;
}
