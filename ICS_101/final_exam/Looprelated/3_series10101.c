/*
Write a program (WAP) that will print following series upto Nth terms
1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, …….

*/

#include <stdio.h>

int main() {
  int n;

  printf("Enter the number of terms N: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    printf("%d ", i % 2);
  }

  return 0;
}
