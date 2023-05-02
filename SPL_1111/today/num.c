#include <stdio.h>

void printval(int limit) {
  if (limit == 1) {
    printf("%d ", limit);
    return;
  }
  printval(limit - 1);
  printf("%d ", limit);
}

void printval2(int limit) {
  if (limit == 1) {
    printf("%d ", limit);
    return;
  }
  printf("%d ", limit);
  printval2(limit - 1);
}

int main(int argc, char const *argv[]) {
  printval(10);
  return 0;
}
