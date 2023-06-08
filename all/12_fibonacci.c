/* Question 12 have a mistake in the sample output. The correct output is:
    Sample input            Sample output
    1                       0
    2                       0, 1
    4                       0, 1, 1, 2
    7                       0, 1, 1, 2, 3, 5, 8

 the question was: Write a program (WAP) that will print Fibonacci series upto Nth terms.
1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, …….
    Sample input            Sample output
    1                       1
    2                       1, 1
    4                       1, 1, 2, 3
    7                       1, 1, 2, 3, 5, 8, 13
*/

#include <stdio.h>

int main() {
  int n, i;
  long long a = 0, b = 1, c;

  printf("Enter the number of terms: ");
  scanf("%d", &n);

  printf("Fibonacci series: ");
  for (i = 1; i <= n; i++) {
    printf("%lld, ", a);
    c = a + b;
    a = b;
    b = c;
  }
  printf("\b\b \n");  // comma removal

  return 0;
}
