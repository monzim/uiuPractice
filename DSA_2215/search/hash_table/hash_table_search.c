#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct KeyValue {
  int key;
  int value;
};

struct HashTable {
  struct KeyValue *table[TABLE_SIZE];
};

struct HashTable *createHashTable() {
  struct HashTable *ht = malloc(sizeof(struct HashTable));
  for (int i = 0; i < TABLE_SIZE; i++) {
    ht->table[i] = NULL;
  }
  return ht;
}

void insert(struct HashTable *ht, int key, int value) {
  int index = key % TABLE_SIZE;
  struct KeyValue *kv = malloc(sizeof(struct KeyValue));
  kv->key = key;
  kv->value = value;
  ht->table[index] = kv;
}

int search(struct HashTable *ht, int key) {
  int index = key % TABLE_SIZE;
  struct KeyValue *kv = ht->table[index];
  if (kv != NULL && kv->key == key) {
    return kv->value;
  }
  return -1;
}

void useMe() {
  struct HashTable *ht = createHashTable();
  insert(ht, 1, 10);
  insert(ht, 2, 20);
  int targetKey = 2;
  int value = search(ht, targetKey);
  if (value != -1) {
    printf("Value for key %d is %d\n", targetKey, value);
  } else {
    printf("Key %d not found in the hash table\n", targetKey);
  }
  free(ht);
}

int main() {
  useMe();
  return 0;
}
