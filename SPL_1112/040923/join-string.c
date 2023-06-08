#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char *str1 = "Hello";
  char *str2 = "World";

  char *str3 = malloc(strlen(str1) + strlen(str2) + 1);

  strcpy(str3, str1);
  strcat(str3, str2);

  puts(str3);

  int i = 0;
  while (str3[i] != '\0') {
    i++;
  }

  printf("The number of characters in str3 is %d \n", i);

  char *str4 = malloc(strlen(str3) + 1);
  int j = 0;
  while (str3[j] != '\0') {
    str4[j] = str3[strlen(str3) - j - 1];
    j++;
  }

  puts(str4);

  // sub string of str3
  char *str5 = malloc(strlen(str3) + 1);
  int k = 0;
  while (str3[k] != '\0') {
    str5[k] = str3[k + 2];
    k++;
  }

  puts(str5);
  return 0;
}
