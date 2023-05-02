#include "stdio.h"
#include "stdlib.h"

int main(int argc, char *argv[]) {
  /*
   *write a program thit will print N with number like
   1       5
   1 2     5
   1   3   5
   1     4 5

   Solve this
     * */

  int n = 5;
  for (int i = 1; i <= n; i++) {
    if (i == 1 || i == n) {
      printf("1");
      for (int i = 2; i < n; i++) {
        printf(" ");
      }
      printf("%d", n);
    } else {
      printf("1");
      for (int j = 2; j < i; j++) {
        if (j == i) {
          printf("%d", j);
        } else {
          printf(" ");
        }
      }
      printf("%d", n);
    }
    printf("\n");
  }
  




return EXIT_SUCCESS;
}
