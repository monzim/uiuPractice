/*
Write a program that reads a number n. Now, take n inputs in an array named marks[10],
here n is less than 10. Now, find the maximum number and its position within the even values
of the array.
 Sample Input: Sample Output:
 6 Even value max = 24, found in index 4
 1 10 6 51 24 13
*/

#include <stdio.h>
int main() {
  int n;
  scanf("%d", &n);
  int marks[10];
  for (int i = 0; i < n; i++) {
    scanf("%d", &marks[i]);
  }
  int max = 0;
  int maxIndex = 0;
  for (int i = 0; i < n; i++) {
    if (marks[i] % 2 == 0 && marks[i] > max) {
      max = marks[i];
      maxIndex = i;
    }
  }
  printf("Even value max = %d, found in index %d", max, maxIndex);
  return 0;
}