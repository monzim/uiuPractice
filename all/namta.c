#include <stdio.h>

int main(int argc, char *argv[]) {
  int v = 5;
  scanf("%d", &v);

  for (int k = 1; k <= v; k++) {
    for (size_t i = 1; i <= 10; i++) {
      int cal = i * k;
      printf("%d x %d = %d\n", k, i, cal);
    }

    printf("\n\n");
  }

  return 0;
}
