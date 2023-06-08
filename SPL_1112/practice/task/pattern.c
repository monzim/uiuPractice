#include <stdio.h>

#define ROWS 7
#define COLS 7

void printCharPattern(char c) {
  int i, j;
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      if ((i == 0 && j > 0 && j < 5) || (i == 1 && (j == 1 || j == 4)) || (i == 2 && (j == 2 || j == 3)) ||
          ((i == 3 || i == 4) && j == 2) || (i == 5 && (j == 1 || j == 4)) || (i == 6 && j > 0 && j < 5)) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf(" ");
  }
  printf("\n");
}

int main() {
  char c;
  for (c = 'A'; c <= 'Z'; c++) {
    printCharPattern(c);
  }
  for (c = 'a'; c <= 'z'; c++) {
    printCharPattern(c);
  }
  return 0;
}
