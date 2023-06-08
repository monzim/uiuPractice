#include <stdio.h>

int main(int argc, char *argv[]) {
  int count, perform;
  count = 6;

  long int arr[] = {382253568, 723152896, 37802240, 379425024, 404894720, 471526144};

  for (int i = 0; i < count; i++) {
    scanf("%d", &arr[i]);
  }

  while (1) {
    for (int i = 0; i < count; i++) {
      if (arr[i] % 2 != 0) {
        return 0;
      }
    }

    for (int i = 0; i < count; i++) {
      arr[i] = arr[i] / 2;
    }

    perform++;
  }

  printf("%d", perform);

  return 0;
}
