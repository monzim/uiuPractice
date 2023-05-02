/*
 WAP that will first take n integers into an array A and then m integers into
array B. Now swap all elements between array A and B. Finally show all elements
of both array A and B

Input:
8
7 8 1 3 2 6 4 3
3
3 2 1

Output:
Array A : 3 2 1
Array B : 7 8 1 3 2 6 4 3
 */

#include <stdio.h>

int main() {
  int n, m;
  printf("Enter the number of integers for array A: ");
  scanf("%d", &n);

  int arrA[n];
  printf("Enter %d integers for array A:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arrA[i]);
  }

  printf("Enter the number of integers for array B: ");
  scanf("%d", &m);

  int arrB[m];
  printf("Enter %d integers for array B:\n", m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &arrB[i]);
  }

  // Swap elements between array A and B
  int minSize = n < m ? n : m; // Find the smaller array size
  for (int i = 0; i < minSize; i++) {
    int temp = arrA[i];
    arrA[i] = arrB[i];
    arrB[i] = temp;
  }

  // Print the elements of array A
  printf("Elements of array A: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arrA[i]);
  }

  // Print the elements of array B
  printf("\nElements of array B: ");
  for (int i = 0; i < m; i++) {
    printf("%d ", arrB[i]);
  }
  printf("\n");

  return 0;
}
