#include <stdio.h>

void main() {
  for (size_t i = 1; i < 100; i = i + i) {
    printf("%d, ", i);
  }
}
