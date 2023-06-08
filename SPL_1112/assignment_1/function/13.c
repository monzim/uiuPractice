#include <stdio.h>
#include <string.h>

void change(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);

  change(&a, &b);
  printf("value in fun: %d %d", a, b);
  printf("mzin: %d %d", a, b);

  return 0;
}
