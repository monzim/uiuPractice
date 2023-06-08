// input amount from user and print minimum number of notes (Rs. 500, 100, 50,
// 20, 10, 5, 2, 1) required for the amount. How to the minimum number of notes
// required for the given amount in C programming. Program to find minimum
// number of notes required for the given denomination. Logic to find minimum
// number of denomination for a given amount in C program.

#include <stdio.h>

void main() {
  // get input from user suppose and store in a array
  float notes[8] = {500, 100, 50, 20, 10, 5, 2, 1};
  int length = sizeof(notes) / sizeof(notes[0]);

  float minimum_note = notes[0];

  for (size_t i = 0; i < length; i++)

  {
    if (minimum_note > notes[i]) {
      minimum_note = notes[i];
    }
  }

  printf("The minimum note is: %.02f", minimum_note);
}