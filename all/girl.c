#include <stdio.h>
#include <string.h>

int disChar(char name[]) {
  int i, j, count = 0;
  int leng = strlen(name);

  for (i = 0; i < leng; i++) {
    for (j = 0; j < i; j++) {
      if (name[i] == name[j]) {
        break;
      }
    }
    if (i == j) {
      count++;
    }
  }
  return count;
}

void printResult(int count) {
  if (count % 2 == 0) {
    printf("CHAT WITH HER!\n");
  } else {
    printf("IGNORE HIM!\n");
  }
}

int main(int argc, char *argv[]) {
  char name[101];
  scanf("%s", name);
  int inputVal = disChar(name);
  printResult(inputVal);

  return 0;
}
