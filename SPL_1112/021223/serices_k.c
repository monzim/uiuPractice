#include <stdio.h>
#include <stdlib.h>


int main(void)
{
int n, i;
  int result = 0;

  scanf("%d", &n);
  printf("%d = ", n);

  for (i = 1; i <= n; i++) {

    int term;
    printf("%d ", i);
    if (i % 2 == 0) {
      term = -i;
      if (i != n)
        printf("- ");
    } else {
      term = i;
      if (i != n)
        printf("+ ");
    }
    result += term;
  }

  printf("= %d\n", result);


    return EXIT_SUCCESS;
}

