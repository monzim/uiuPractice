#include <stdio.h>

int main(int argc, char *argv[]) {
  int notes[] = {100, 50, 20, 10, 5, 2, 1};

  int amount;
  printf("Enter the amount of money: ");
  scanf("%d", &amount);

  int indexOfNote = 0;
  while (amount > 0) {
    int num_notes = amount / notes[indexOfNote];
    printf("%d notes of %d\n", num_notes, notes[indexOfNote]);
    amount -= num_notes * notes[indexOfNote];
    indexOfNote++;
  }

   return 0;
}
