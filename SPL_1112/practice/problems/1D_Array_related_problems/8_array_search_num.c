/*
 WAP that will take n integers into an array, and then search a number into that
array. If found then print its index. If not found then print “NOT FOUND”.

Input: 8
7 8 1 3 2 6 4 3
3

Output: FOUND at index position: 3, 7

 */

#include <stdio.h>

int main() {
  int n, x, index = -1;
  printf("Enter the number of integers: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter %d integers:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Enter the number to search: ");
  scanf("%d", &x);

  for (int i = 0; i < n; i++) {
    if (arr[i] == x) {
      index = i;
      break;
    }
  }

  if (index != -1) {
    printf("The number %d is found at index %d.\n", x, index);
  } else {
    printf("NOT FOUND.\n");
  }

  return 0;
}
