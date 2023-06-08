/*
 WAP that will take n integers into an array A and m positive integers into
array B. Now find the union (set operation) of array A and B.

Input: 8
7 8 1 5 2 6 4 3
6
1 3 6 0 9 2

Output: 7 8 1 5 2 6 4 3 0 9
 */

#include <stdio.h>

void unionArrays(int arrA[], int arrB[], int n, int m) {
  int i, j, k;
  int arrUnion[n + m];

  // Copy elements of array A to arrUnion
  for (i = 0; i < n; i++) {
    arrUnion[i] = arrA[i];
  }

  // Copy elements of array B to arrUnion (if not already present)
  for (i = 0, k = n; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (arrB[i] == arrA[j]) {
        break;
      }
    }
    if (j == n) {
      arrUnion[k++] = arrB[i];
    }
  }

  // Print the union array
  printf("The union of arrays A and B is: ");
  for (i = 0; i < k; i++) {
    printf("%d ", arrUnion[i]);
  }
}

int main() {
  int n, m, i;
  printf("Enter the size of array A: ");
  scanf("%d", &n);
  int arrA[n];
  printf("Enter the elements of array A: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &arrA[i]);
  }
  printf("Enter the size of array B: ");
  scanf("%d", &m);
  int arrB[m];
  printf("Enter the elements of array B: ");
  for (i = 0; i < m; i++) {
    scanf("%d", &arrB[i]);
  }
  unionArrays(arrA, arrB, n, m);
  return 0;
}
