#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}

int lcm(int a, int b) { return (a * b) / gcd(a, b); }

int main(int argc, char *argv[]) {
  int a, b;

  while (1) {
    printf("2 pos int [0 to exit]: ");
    scanf("%d %d", &a, &b);

    if (a == 0 || b == 0) {
      break;
    }

    printf("GCD: %d\n", gcd(a, b));
    printf("LCM: %d\n", lcm(a, b));
  }

  return EXIT_SUCCESS;
}
