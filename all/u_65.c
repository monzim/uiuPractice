#include <stdio.h>
#include <string.h>

int findLastIndexOfA(char *S) {
  for (int i = strlen(S) - 1; i >= 0; i--) {
    if (S[i] == 'a') {
      return i + 1;
    }
  }
  return -1;
}

int main() {
  char S[100];
  scanf("%s", S);
  printf("%d\n", findLastIndexOfA(S));
  return 0;
}
