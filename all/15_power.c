/*
Write a program (WAP) that will find xy
(x to the power y) where x, y are positive integers.
    Sample input(x,y) Sample output
        5 2   => 25
        2 0    => 1
        6 1   => 6
        0 5   => 0
*/

#include <stdio.h>

int power(int x, int y) {
  if (y == 0) return 1;
  return x * power(x, y - 1);  // x^y = x * x^(y-1)
}

int main() {
  // Test
  printf("2^3 = %d\n", power(2, 3));  // Output: 8
  printf("3^4 = %d\n", power(3, 4));  // Output: 81
  printf("4^2 = %d\n", power(4, 2));  // Output: 16
  return 0;
}
