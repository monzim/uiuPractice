#include <stdio.h>
#include <stdlib.h>

int power(int x, int y) {
  if (y == 0) return 1;
  return x * power(x, y - 1);
}

int main() {
  int x, y;
  printf("two positive num: ");
  scanf("%d %d", &x, &y);

  int result = power(x, y);
  printf("%d to the power %d is %d\n", x, y, result);
  return EXIT_SUCCESS;
}
