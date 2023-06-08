#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
  int key;
  int value;
} Hash;

Hash hash[MAX];

void init() {
  int i;

  for (i = 0; i < MAX; i++) {
    hash[i].key = -1;
    hash[i].value = 0;
  }
}

int hash_function(int key) { return key % MAX; }

void insert(int key) {
  int index = hash_function(key);

  if (hash[index].key == -1) {
    hash[index].key = key;
    hash[index].value = 1;
  } else {
    hash[index].value++;
  }
}

bool search(int key) {
  int index = hash_function(key);

  if (hash[index].key == -1) {
    return false;
  } else {
    return true;
  }
}

void print() {
  int i;

  for (i = 0; i < MAX; i++) {
    if (hash[i].key != -1) {
      printf("key: %d, value: %d \t", hash[i].key, hash[i].value);
    }
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = sizeof(array) / sizeof(array[0]);
  int i;

  init();

  for (i = 0; i < size; i++) {
    insert(array[i]);
  }

  print();

  search(1) ? printf("Found \t") : printf("Not Found \t");

  return EXIT_SUCCESS;
}
