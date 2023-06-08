#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int num;
  printf("Enter a number : ");
  scanf("%d", &num);

  int binary[32];

  int i = 0;
  while (num > 0) {
    binary[i] = num % 2;
    num /= 2;
    i++;
  }

  for (int j = i - 1; j >= 0; j--) {
    printf("%d", binary[j]);
  }

  printf("\n");

  return EXIT_SUCCESS;
}
