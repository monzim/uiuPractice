#include <stdio.h>

void main() {
  // for loop
  int num1, num2;

  for (size_t i = 1; i <= 100; i++) {
    num1 += i;
    if (i == 1 || i <= 100 && (i % 4 == 0)) {
      printf("%d, ", i);

      //   num2 = num2 + i + 2;
    }
  }
}
