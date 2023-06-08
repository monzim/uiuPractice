/*
$_____$_____$
_$___$$$___$_
__$_$$$$$_$__
___$$$$$$$___
__$$$$$$$$$__
_$$$$$$$$$$$_
$$$$$$$$$$$$$
__$$$$$$$$$__
___$$$$$$$___
___$$$$$$$___
__$__$$$__$__
_$____$____$_
$___________$

*/

#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  if (n % 2 == 0) {
    printf("need an odd integer.\n");
    return 0;
  }
  int i, j, k;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (i == (n + 1) / 2 && j == (n + 1) / 2) {
        printf("$");
      } else if (i == j || i + j == n + 1) {
        printf("$");
      } else if (i <= (n + 1) / 2 && j > (n + 1) / 2 - i && j < (n + 1) / 2 + i) {
        printf("$");
      } else if (i > (n + 1) / 2 && j > (n + 1) / 2 - (n - i) && j < (n + 1) / 2 + (n - i)) {
        printf("$");
      } else {
        printf("_");
      }
    }
    printf("\n");
  }
  return 0;
}
