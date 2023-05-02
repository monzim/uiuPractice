/*
Write a program that takes an integer n as input from the user and prints the following
pattern. Program for n, NOT 3 or 5

input: 3
output:
6 4 2
4 2
2

input: 5
output:
10 8 6 4 2
8 6 4 2
6 4 2
4 2
2
*/

#include <stdio.h>

int main() {
  int n;
  printf("Enter a positive integer: ");
  scanf("%d", &n);
  for (int i = n; i >= 1; i--) {
    for (int j = 2 * i; j >= 2; j -= 2) {
      printf("%d ", j);
    }
    printf("\n");
  }
  return 0;
}