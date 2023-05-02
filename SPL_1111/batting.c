#include <stdio.h>

#define MAX_SIZE 100000 // maximum size of array

int main() {
  int runs[MAX_SIZE], n = 0; // initialize the array and counter

  char choice;
  do {
    printf("\nEnter 'a' to add a batting score, 'b' to display all scores, 'c' "
           "to count scores above average, or 'q' to quit: ");
    scanf(" %c", &choice);

    switch (choice) {
    case 'a': // add a batting score
      if (n >= MAX_SIZE) {
        printf("Array is full.\n");
      } else {
        int score;
        printf("Enter batting score: ");
        scanf("%d", &score);
        runs[n++] = score;
      }
      break;

    case 'b': // display all batting scores
      if (n == 0) {
        printf("No batting scores found. Please populate your batting scores "
               "first.\n");
      } else {
        printf("Batting scores:\n");
        for (int i = 0; i < n; i++) {
          printf("%d ", runs[i]);
        }
        printf("\n");
      }
      break;

    case 'c': // count scores above average
      if (n == 0) {
        printf("No batting scores found. Please populate your batting scores "
               "first.\n");
      } else {
        int total = 0;
        for (int i = 0; i < n; i++) {
          total += runs[i];
        }
        double average = (double)total / n;
        int count = 0;
        for (int i = 0; i < n; i++) {
          if (runs[i] > average) {
            count++;
          }
        }
        printf("Number of batsmen who scored above average: %f\n", average);
      }
      break;

    case 'q': // quit
      printf("Exiting...\n");
      break;

    default: // invalid choice
      printf("Invalid choice. Please try again.\n");
      break;
    }

  } while (choice != 'q');

  return 0;
}
