
/* Sample Input :
    Enter the number : 5
   Sample Output :
    The number is odd number
*/
#include <stdio.h>

void main() {
  int num;

  printf("Enter the number :");
  scanf("%d", &num);

  ((num % 2) == 0) ? (printf("The number is even number.")) : (printf("The number is odd number"));
}
