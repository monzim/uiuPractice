#include <stdio.h>
#include <string.h>

int count_distinct_characters(char username[]) {
  int count = 0, i, j;
  int length = strlen(username);

  for (i = 0; i < length; i++) {
    for (j = 0; j < i; j++) {
      if (username[i] == username[j]) {
        break;
      }
    }
    if (i == j) {
      count++;
    }
  }
  return count;
}

int main() {
  char username[101];
  scanf("%s", username);
  int distinct_characters = count_distinct_characters(username);
  if (distinct_characters % 2 == 0) {
    printf("CHAT WITH HER!\n");
  } else {
    printf("IGNORE HIM!\n");
  }
  return 0;
}
