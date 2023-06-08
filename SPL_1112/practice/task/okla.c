#include <stdio.h>
#include <string.h>

#define WIDTH 5   // width of each character
#define SPACER 2  // space between characters

int main() {
  char tape[100];  // input string
  printf("Enter a string: ");
  fgets(tape, sizeof(tape), stdin);  // read input string from user

  int length = strlen(tape);
  int total_width = WIDTH * length + SPACER * (length - 1);
  int y_center = 8 / 2;

  // loop through each character in the string
  for (int i = 0; i < length; i++) {
    // calculate x coordinate for the character
    int x = (total_width - (WIDTH + SPACER) * i - WIDTH);

    // loop through each row of the character
    for (int row = 0; row < 8; row++) {
      // loop through each column of the character
      for (int col = 0; col < WIDTH; col++) {
        // calculate the character index in the string
        int letter = i - length + 1 + col / WIDTH;
        // print an asterisk if the pixel is on, or a space if it's off
        if ((letter >= 0) && (letter < length) && (tape[letter] & (1 << (7 - row))) != 0) {
          printf("*");
        } else {
          printf(" ");
        }
      }
      printf("\n");  // move to next line after each row
    }
    printf("\n");  // add extra space between characters
  }

  return 0;
}
