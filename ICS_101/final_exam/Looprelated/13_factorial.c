/*
Write a program (WAP) that will print the factorial (N!) of a given number N. Please see
the sample input output.
    Sample input        Sample output
    1 1! =              1 = 1
    2 2! =              2 X 1 = 2
    3 3! =              3 X 2 X 1 = 6
    4 4! =              4 X 3 X 2 X 1 = 24
*/

#include <stdio.h>

long long factorial(int n) {
  if (n == 0) {
    return 1;
  }
  return n * factorial(n - 1);
}

int main() {
  int n;
  long long result;

  printf("Enter the number: ");
  scanf("%d", &n);

  result = factorial(n);
  printf("%d! = %lld\n", n, result);

  return 0;
}
