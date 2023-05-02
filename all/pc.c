#include <stdio.h>

int main(int argc, char *argv[]) {
  int a;
  scanf("%d", &a);

  int count = 0;

  for (int i = 0; i < 3; i++) {
    if (a % 10 == 1) {
      count++;
    }
    a = a / 10;
  }

  printf("%d", count);

  return 0;
}
