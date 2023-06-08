/*
 C program that will take n alphabets into an array, and then count number of
vowels in that array.

Input: 7 AKIOUEH
Output: 5
 */

#include <stdio.h>

int main() {
  int n, count = 0;
  printf("Enter the number of alphabets: ");
  scanf("%d", &n);

  char arr[n];
  printf("Enter %d alphabets:\n", n);
  for (int i = 0; i < n; i++) {
    scanf(" %c",
          &arr[i]); // Note the space before %c to consume whitespace characters
  }

  for (int i = 0; i < n; i++) {
    if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' ||
        arr[i] == 'u' || arr[i] == 'A' || arr[i] == 'E' || arr[i] == 'I' ||
        arr[i] == 'O' || arr[i] == 'U') {
      count++;
    }
  }

  printf("Number of vowels in the array: %d\n", count);

  return 0;
}
