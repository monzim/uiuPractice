
//  Probelem: 1
#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("Enter a number: ");
  int k;
  scanf("%d", &k);

  for (int i = k; i > 0; i--) {
    printf("%d ", i);
  }

  return 0;
}
