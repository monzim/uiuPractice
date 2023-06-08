#include <stdio.h>

void checkEvenOdd(int n) {
  if (n % 2 != 0) {
    printf("%d is odd", n);
  } else {
    printf("%d is even", n);
  }
}

int main(int argc, char *argv[]) {
  int n;
  printf("Enter a integer: ");
  scanf("%d", &n);
  checkEvenOdd(n);

  return 0;
}
