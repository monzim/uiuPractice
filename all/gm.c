#include <stdio.h>

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  printf("S(A, %d) = ", n);
  for (int i = n; i >= 1; i--) {
    if (i == n)
      printf("((sin(1)+%d) ", i);
    else if (i == 1)
      printf("sin(1-sin(2+sin(3-sin(4+...+sin(%d))))))", i);
    else
      printf("sin(1-sin(2+sin(3-sin(4+...+sin(%d))))) ", i);
  }
  printf("+ 1\n");

  return 0;
}
