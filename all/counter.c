#include <stdio.h>

int main(int argc, char *argv[]) {
  int count = 1;
  for (size_t i = 0; i < 5; i++) {
    for (size_t j = 0; j < 5; j++) {
      printf("Mine : %d\n", count++);
    }
  }

  return 0;
}
