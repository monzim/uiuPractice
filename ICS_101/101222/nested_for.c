#include <stdio.h>

void main() {
   for (size_t i = 0; i <= 3; i++) {
    printf("|");
    for (size_t k = 0; k <= i; k++) {
      printf("* ");
      if (k = i) {
        printf("\\");
      }
      if (i == 3) {
        printf("_");
      }
    }

    printf("\n");
  }
}
