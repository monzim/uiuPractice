#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int a = 36;
  int b = 67;
  int tmp = a - b;
  printf(" %d and %d is %d\n", a, b, tmp);

  a = 25;
  b = 84;

  int sum = a + b;

  printf("The sum of %d and %d is %d\n", a, b, sum);

  return 0;
}
