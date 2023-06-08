#include <stdio.h>

int main() {
  int n = 3, i = 0, j, sum = 0;

  do {
    j = 0;
    do {
      if (i == j) {
        sum += i + j;
      } else if (i > j) {
        sum += i + n;
      } else {
        sum += n - j;
      }
      j++;
    } while (j <= i);

    i++;
  } while (i < n);

  return 0;
}
