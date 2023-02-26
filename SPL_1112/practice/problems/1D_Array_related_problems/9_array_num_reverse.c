/*
 . WAP that will take n integers into an array A, and then copy all numbers in
reverse order from array A to another array B. Finally show all elements of both
array A and B.

Input: 8
7 8 1 3 2 6 4 3

Output:
Array A : 7 8 1 3 2 6 4 3
Array B : 3 4 6 2 3 1 8 7

 */

#include <stdio.h>

int main() {
  int n;
  printf("Enter the number of integers: ");
  scanf("%d", &n);

  int arrA[n], arrB[n];
  printf("Enter %d integers:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arrA[i]);
  }

  // Copy elements from array A to array B in reverse order
  for (int i = 0; i < n; i++) {
    arrB[i] = arrA[n - i - 1];
  }

  // Print the elements of array A
  printf("Elements of array A: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arrA[i]);
  }

  // Print the elements of array B
  printf("\nElements of array B: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arrB[i]);
  }
  printf("\n");

  return 0;
}
