#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPalindrome(char str[]) {
  int left = 0, right = strlen(str) - 1;

  while (left < right) {
    if (str[left] != str[right]) {
      return false;
    }
    left++;
    right--;
  }

  return true;
}

int main(int argc, char *argv[]) {
  char str[100];
  scanf("%s", str);

  if (isPalindrome(str)) {
    printf("Yes");
  } else {
    printf("No");
  }
  return EXIT_SUCCESS;
}
