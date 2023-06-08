#include <stdio.h>
#include <stdlib.h>

int main() {
  int list[] = {1, 2, 3, 3, 5, 1, 4, 22, 55, 33, 22, 33, 33, 2, 55};
  int length = sizeof(list) / sizeof(list[0]);
  int i, j, k;

  for (i = 0; i < length; i++) {
    int e = list[i];
    int found = 0;
    for (j = 0; j < i; j++) {
      if (list[j] == e) {
        found = 1;
        break;
      }
    }
    if (found) {
      continue;
    }
    int count = 0;
    int indices[length];
    for (k = 0; k < length; k++) {
      if (list[k] == e) {
        indices[count] = k;
        count++;
      }
    }
    if (count > 1) {
      printf("Element: %d | Frequency: %d | Index: [", e, count);
      for (k = 0; k < count; k++) {
        printf("%d", indices[k]);
        if (k < count - 1) {
          printf(", ");
        }
      }
      printf("]\n");
    }
  }

  return 0;
}
