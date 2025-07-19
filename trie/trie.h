#ifndef TRIE_H
#define TRIE_H
#include <stdbool.h>
#define ALPHABET 26

typedef struct trienode {
    struct trienode *children[ALPHABET];
    bool endOfWord;
    int depth;
} * TrieNode;

int functionAlphabet(char letter);

TrieNode createNode();

void insertWord(TrieNode root, const char* word);

bool searchWord(TrieNode root, const char* word, int * level);

void freeTrie(TrieNode root);

void updateDepth(TrieNode root, int level);

#endif