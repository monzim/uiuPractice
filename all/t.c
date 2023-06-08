
#include <stdio.h>

int main(int argc, char *argv[]) {
  int notes;

  //   int notesHund = notes / 100;
  //   int notesFifty = (notes % 100) / 50;
  //   int notesTwenty = ((notes % 100) % 50) / 20;
  //   int notesTen = (((notes % 100) % 50) % 20) / 10;
  //   int notesFive = ((((notes % 100) % 50) % 20) % 10) / 5;
  //   int notesTwo = (((((notes % 100) % 50) % 20) % 10) % 5) / 2;
  //   int notesOne = ((((((notes % 100) % 50) % 20) % 10) % 5) % 2) / 1;

  int notesHund, notesFifty, notesTwenty, notesTen, notesFive, notesTwo, notesOne;
  printf("Enter the amount of money: ");

  scanf("%d", &notes);

  notesHund = notes % 100;
  notesFifty = notesHund % 50;
  notesTwenty = notesFifty % 20;
  notesTen = notesTwenty % 10;
  notesFive = notesTen % 5;
  notesTwo = notesFive % 2;
  notesOne = notesTwo % 1;

  printf("100: %d\n", notes / 100);
  printf("50: %d\n", notesHund / 50);
  printf("20: %d\n", notesFifty / 20);
  printf("10: %d\n", notesTwenty / 10);
  printf("5: %d\n", notesTen / 5);
  printf("2: %d\n", notesFive / 2);
  printf("1: %d\n", notesTwo / 1);

  return 0;
}
