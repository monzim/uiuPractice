#include "stdio.h"

int main() {

  int i = 0;
  scanf("%d", &i);

  for (int j = 1; j <= i; j++) {
    if (i == j) {
      printf("%d", j);

    } else {
      printf("%d, ", j);
    }
  }
}
