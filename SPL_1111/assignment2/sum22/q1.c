
#include <stdio.h>
void main() {
  int i, j, data[5][5] = {0};
  for (i = 0; i < 5; i++) {
    for (j = i + 1; j < 5; j++) scanf("%d", &data[i][j]);
  }
  for (i = 0; i < 5; i++) {
    for (j = i; j < 5; j++) printf("%d_", data[i][j]);
    printf("\n");
  }
}