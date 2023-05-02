#include <stdio.h>

int valid(int n) {
  printf("Checking %d\n", n);
  if (n > 0 && n < 180) {
    return 1;
  } else {
    return 0;
  }
}

int main(int argc, char *argv[]) {
  int a, b, c;

  printf("Enter a b c: ");
  scanf("%d %d %d", &a, &b, &c);

  if ((valid(a) && valid(b) && valid(c)) && (a + b + c) == 180) {
    printf("Yes");

  } else {
    printf("No");
  }

  // if (a > 0 && a < 180) {
  //   printf("Checking %d\n", a);

  //   if (b > 0 && b < 180) {
  //     printf("Checking %d\n", b);

  //     if (c > 0 && c < 180) {
  //       printf("Checking %d\n", c);
  //     } else {
  //       printf("No");
  //     }
  //   } else {
  //     printf("No");
  //   }

  // } else {
  //   printf("No");
  // }

  return 0;
}
