
/* Sample Input :
    Enter the 3 digit number : 123
   Sample Output :
    The reverse of the number is : 321
*/
#include <stdio.h>

void main() {
  int num, n, reverse = 0;

  printf("Enter the 3 digit number :");
  scanf("%d", &num);

  n = num % 10;
  reverse = reverse * 10 + n;
  num = num / 10;

  n = num % 10;
  reverse = reverse * 10 + n;
  num = num / 10;

  n = num % 10;
  reverse = reverse * 10 + n;
  num = num / 10;

  printf("The reverse of the number is : %d", reverse);
}
