#include <stdio.h>

void kPrint(int n) {
  if (n == 0) return;
  kPrint(n - 1);
  if (n % 3 == 0) printf("%d ", n);
}

int main(int argc, char *argv[]) {
  int k = 20;
  kPrint(k);

  return 0;
}
