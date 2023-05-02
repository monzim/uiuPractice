/*
Manually trace the following C code segment for num=3 and show the change of values of
all the variables in each step.
#include <stdio.h>
int main() {
 int num;
 int sum = 10, i =7, j = 2;
 scanf("%d", &num);
 switch(num) {
 case 1:
 case 2:
 sum += --j*2;
 i--;
 case 3:
 sum = ++i*j--;
 break;
 case 4:
 sum *= i++/j--;
i=i%j;
 default: break;
 }
 printf("%d %d %d",sum,i,j);
 return 0;
}

Manually trace the following C code segment for num=3 and show the change of values of
all the variables in each step.


*/

#include <stdio.h>
int main() {
  int num;
  int sum = 10, i = 7, j = 2;
  scanf("%d", &num);
  if (num == 1 || num == 2) {
    sum += --j * 2;
    i--;
  } else if (num == 3) {
    sum = ++i * j--;
  } else if (num == 4) {
    sum *= i++ / j--;
    i = i % j;
  }
  printf("%d %d %d", sum, i, j);
  return 0;
}

// #include <stdio.h>
// int main() {
//   int num;
//   int sum = 10, i = 7, j = 2;
//   scanf("%d", &num);
//   switch (num) {
//     case 1:
//     case 2:
//       sum += --j * 2;
//       i--;
//     case 3:
//       sum = ++i * j--;
//       break;
//     case 4:
//       sum *= i++ / j--;
//       i = i % j;
//     default:
//       break;
//   }
//   printf("%d %d %d", sum, i, j);
//   return 0;
// }
