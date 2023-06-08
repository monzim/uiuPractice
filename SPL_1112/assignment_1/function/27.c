#include <stdio.h>
#include <stdlib.h>

void inputFromUser(int *num, int *base) {
  scanf("%d", num);

  do {
    printf("2 to 16: ");
    scanf("%d", base);
  } while (*base < 2 || *base > 16);
}

void converter(int num, int base) {
  int i = 0;

  while (num > 0) {
    int digit = num % base;

    if (digit < 10) {
      // TODO
    } else {
    }
  }
}

int main(int argc, char *argv[]) { return EXIT_SUCCESS; }
