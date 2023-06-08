#include <stdio.h>

int main(int argc, char *argv[]) {
  int a, b, c;
  char str[100];
  scanf("%d %d %d", &a, &b, &c);
  scanf("%s", str);

  int sum = a + b + c;
  printf("%d %s", sum, str);

  return 0;
}
