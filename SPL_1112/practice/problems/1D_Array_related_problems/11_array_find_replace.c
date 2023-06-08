/*
 WAP that will take n positive integers into an array A. Now find all the
integers that are divisible by 3 and replace them by -1 in array A. Finally show
all elements of array A.

Input:
8
7 8 1 3 2 6 4 3

Output:
7 8 1 -1 2 -1 4 -1
*/

#include <stdio.h>

int main() {
  int n;
  printf("Enter the number of positive integers: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter %d positive integers:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Find and replace all integers divisible by 3 with -1
  for (int i = 0; i < n; i++) {
    if (arr[i] % 3 == 0) {
      arr[i] = -1;
    }
  }

  // Print the elements of array A
  printf("Elements of array A: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
