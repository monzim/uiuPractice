#include <stdio.h>

#define ROW 7
#define COL 7

void mPrint() {
  for (int row = 0; row < ROW; row++) {
    for (int col = 0; col < COL; col++) {
      if (col == 0 || col == COL - 1 || row == col || row == COL - col - 1) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

void nPrint() {
  for (int row = 0; row < ROW; row++) {
    for (int col = 0; col < COL; col++) {
      if (col == 0 || col == COL - 1 || row == col) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

void oPrint() {
  for (int row = 0; row < ROW; row++) {
    for (int col = 0; col < COL; col++) {
      if (row == 0 || row == ROW - 1 || col == 0 || col == COL - 1) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}
void iPrint() {
  for (int row = 0; row < ROW; row++) {
    for (int col = 0; col < COL; col++) {
      if (row == 0 || row == ROW - 1 || col == COL / 2) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}
void zPrint() {
  for (int row = 0; row < ROW; row++) {
    for (int col = 0; col < COL; col++) {
      if (row == 0 || row == ROW - 1 || row + col == ROW - 1) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main(void) {
  mPrint();
  oPrint();
  nPrint();
  zPrint();
  iPrint();
  mPrint();
  return 0;
}