/* No Need
Write a program (WAP) that will run and show keyboard inputs until the user types an ’A’
at the keyboard.

*/

#include <stdio.h>

int main() {
  char c;

  do {
    c = getchar();     // read a character from the keyboard
    putchar(c);        // print the character
  } while (c != 'A');  // repeat until the character is 'A'

  return 0;
}
