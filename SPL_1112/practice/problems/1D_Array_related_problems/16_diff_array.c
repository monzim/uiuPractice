/*
 WAP that will take n integers into an array A and m positive integers into
array B. Now find the difference (set operation) of array A and B or (A-B).

Input:8
7 8 1 5 2 6 4 3
6
1 3 6 0 9 2

Output: 7 8 5 4
 */

#include <stdio.h>

void difference(int arrA[], int n, int arrB[], int m) {
  int diff[n];   // Array to store the difference
  int count = 0; // Count of elements in diff array

  // Traverse array A and check if each element is present in array B
  for (int i = 0; i < n; i++) {
    int present = 0;
    for (int j = 0; j < m; j++) {
      if (arrA[i] == arrB[j]) {
        present = 1;
        break;
      }
    }
    // If element is not present in array B, add it to diff array
    if (!present) {
      diff[count] = arrA[i];
      count++;
    }
  }

  // Print the elements of diff array
  printf("Difference of A and B: ");
  for (int i = 0; i < count; i++) {
    printf("%d ", diff[i]);
  }
  printf("\n");
}

int main() {
  int n, m;
  printf("Enter the number of elements in array A: ");
  scanf("%d", &n);

  int arrA[n];
  printf("Enter the elements of array A: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arrA[i]);
  }

  printf("Enter the number of elements in array B: ");
  scanf("%d", &m);

  int arrB[m];
  printf("Enter the elements of array B: ");
  for (int i = 0; i < m; i++) {
    scanf("%d", &arrB[i]);
  }

  difference(arrA, n, arrB, m);

  return 0;
}
