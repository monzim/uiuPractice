#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int num_notes;
  printf("Enter the number of notes: ");
  scanf("%d", &num_notes);

  int *notes = malloc(num_notes * sizeof(int));
  printf("Enter the available notes: ");
  for (int i = 0; i < num_notes; i++) {
    scanf("%d", &notes[i]);
  }

  int amount;
  printf("Enter the amount of money: ");
  scanf("%d", &amount);

  for (int i = 0; i < num_notes; i++) {
    int num_notes = amount / notes[i];
    printf("%d notes of %d\n", num_notes, notes[i]);
    amount -= num_notes * notes[i];
  }

  free(notes);
  return 0;
}
