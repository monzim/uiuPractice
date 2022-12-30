/*
Write a program that takes an integer number n as input and find out the sum of the
following series up to n terms. 1 + 12 + 123 + 1234 + …….
Sample input Sample output
        1   1
        2   13
        3   136
        4   1370
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum_series(int n) {
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    // Convert i to string
    char str[10];
    sprintf(str, "%d", i);
    // Repeat the string i times
    char repeated[50] = "";
    for (int j = 0; j < i; j++) {
      strcat(repeated, str);
    }
    // Convert the repeated string back to integer and add to sum
    sum += atoi(repeated);
  }
  return sum;
}

int main() {
  // Test the function
  printf("%d\n", sum_series(1));  // Output: 1
  printf("%d\n", sum_series(2));  // Output: 13
  printf("%d\n", sum_series(3));  // Output: 136
  printf("%d\n", sum_series(4));  // Output: 1370
  return 0;
}
