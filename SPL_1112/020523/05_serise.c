#include "stdio.h"

int main() {
  int in = 0;
  scanf("%d", &in);

  int a = 1;
  for (int i = 1; i <= in; i++) {
    printf("%d", a);

    if (i < in) {
      printf(", ");
    }

    if (a == 1) {
      a = 0;
    } else {
      a = 1;
    };
  }
  return 0;
}
