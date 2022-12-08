#include <stdio.h>

void main() {
  //   int x = 10;
  //   int y = 20;

  //   printf("The larger number is %s\n", (x > y) ? "x" : "y");

  int x = 10;
  int y = 20;

  char output[100];
  //   The sprintf function writes the formatted string to the character array str, and then the printf function prints
  //   the contents of str to the screen.
  sprintf(output, "The larger number is %s\n", (x > y) ? "x" : "y");
  printf("%s", output);

  for (int i = 0; i < 100; i++) {
    char output[100];
    sprintf(output, (i != 99) ? "%i, " : "%i", i);
    printf("%i, ", i);
  }
}