
/*
b) Write a C program to display following ‘Y’ pattern.
Sample Input N = 3
Sample Output
*  *
 *
 *

Sample Input N = 5
Sample Output
 *   *
  * *
   *
   *
   *
*/

#include <stdio.h>
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j && i <= n / 2 || i + j == n - 1 && i <= n / 2 || j == n / 2 && i > n / 2) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}