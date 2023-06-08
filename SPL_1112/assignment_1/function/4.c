#include <stdio.h>
#include <stdlib.h>

void posNeg(int num) {
  if (num > 0) {
    printf("positive");
  } else if (num < 0) {
    printf("negative");
  } else {
    printf("zero");
  }
}

int main(int argc, char *argv[]) {
  int value;
  scanf("%i", &value);

  posNeg(value);

  return EXIT_SUCCESS;
}