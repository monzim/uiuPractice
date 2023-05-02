#include <stdio.h>
int main() {
  int a, b;

  a = 10;
  b = 5;

  printf("Value of a before swapping= %d\n", a);
  printf("Value of b before swapping= %d\n", b);

  a = a + b;

  b = a - b;

  a = a - b;

  printf("Value of a after swapping= %d\n", a);
  printf("Value of b after swapping=  %d\n", b);

  return 0;
}
