/*
 WAP that will take n integers into an array A and m positive integers into
array B. Now find the intersection (set operation) of array A and B

Input:8
7 8 1 5 2 6 4 3
6
1 3 6 0 9 2

Output: 1 2 6 3

Input: 3
1 2 3
2
4 5

Output: No intersection
 */

#include <stdio.h>

// function to find intersection of two arrays
void findIntersection(int arrA[], int n, int arrB[], int m) {
  printf("Intersection of Array A and Array B is: ");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arrA[i] == arrB[j]) {
        printf("%d ", arrA[i]);
        break;
      }
    }
  }
  printf("\n");
}

int main() {
  int n, m;
  printf("Enter the size of Array A: ");
  scanf("%d", &n);
  int arrA[n];
  printf("Enter %d integers into Array A: ", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arrA[i]);
  }
  printf("Enter the size of Array B: ");
  scanf("%d", &m);
  int arrB[m];
  printf("Enter %d positive integers into Array B: ", m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &arrB[i]);
  }
  findIntersection(arrA, n, arrB, m);
  return 0;
}
