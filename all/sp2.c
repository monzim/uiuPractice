#include <stdio.h>

int main() {
  int a;
  a = 10;

  int b;
  b = 5;

  printf("Value of a before swapping %d\n", a);

  printf("Value of b before swapping %d\n", b);
  int c;

  c = a;

  a = b;

  b = c;

  printf("Value of a after swapping %d\n", a);

  printf("Value of b after swapping %d", b);

  return 0;
}
