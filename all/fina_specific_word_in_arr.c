#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// use tries to solve this problem

// 1. convert the word into a trie
// 2. convert the sentence into a trie
// 3. check how many times the word is present in the sentence

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
struct TrieNode {
  struct TrieNode *children[ALPHABET_SIZE];
  // isEndOfWord is true if the node represents
  // end of a word
  bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void) {
  struct TrieNode *pNode = NULL;

  pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));

  if (pNode) {
    int i;

    pNode->isEndOfWord = false;

    for (i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL;
  }

  return pNode;
}

int main() {
  // check if the word is present in the sentence

  char word[100];
  char sentence[1000];

  printf("Enter a word: ");
  scanf("%s", word);

  printf("Enter a sentence: ");
  scanf("%s", sentence);

  printf("Word: %s\n", word);
  printf("Sentence: %s\n", sentence);

  //   convet the word into

  return 0;
}