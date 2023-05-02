
/* Sample Input :
    Enter the Upper case Charecter : A
   Sample Output :
    The Lower case charecter is : a
*/
#include <stdio.h>

void main() {
  char charecter;
  int lowercase;

  printf("Enter the Upper case Charecter :");
  scanf("%c", &charecter);

  lowercase = charecter + 32;

  printf("The Lower case charecter is : %c", lowercase);
}
