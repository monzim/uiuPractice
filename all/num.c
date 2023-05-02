#include "stdio.h"
#include "stdlib.h"

int main(int argc, char *argv[]) {
  int a = 0;
  scanf("%d", &a);

  for (int i = 1; i <= 10; i++) {
    int b = 0;
    for (int j = 1; j <= i; j++) {
      b += a;
    }
    printf("%d * %d = %d\n", a, i, b);
  }

  return EXIT_SUCCESS;
}
