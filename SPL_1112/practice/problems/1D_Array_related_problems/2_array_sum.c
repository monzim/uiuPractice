/*
 WAP that will take n integer numbers into an array, and then sum up all the integers in
that array.

Input: 5 1 2 3 4 5
Output: 15
 */

#include <stdio.h>

int main() {
  int n;
  printf("Enter the number of integers: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter %d integers:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  printf("Sum of integers in the array: %d\n", sum);

  return 0;
}
