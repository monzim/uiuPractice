/*
WAP that will find the GCD (greatest common divisor) and LCM (least common multiple)
of two positive integers.
    Sample input Sample output
    5 7 GCD: 1
    LCM: 35
    12 12 GCD: 12
    LCM: 12
    12 32 GCD: 4
    LCM: 96
*/

#include <stdio.h>

int gcd(int a, int b) {
  // Euclidean algorithm
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int lcm(int a, int b) {
  return a * b / gcd(a, b);  // LCM = (a * b) / GCD(a, b)
}

int main() {
  // Test
  printf("GCD(12, 16) = %d\n", gcd(12, 16));  // Output: 4
  printf("GCD(14, 21) = %d\n", gcd(14, 21));  // Output: 7
  printf("LCM(12, 16) = %d\n", lcm(12, 16));  // Output: 48
  printf("LCM(14, 21) = %d\n", lcm(14, 21));  // Output: 42
  return 0;
}
