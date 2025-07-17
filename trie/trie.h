#ifndef TRIE_H
#define TRIE_H
#include <stdbool.h>
#define ALPHABET 26

typedef struct trienode {
    struct trienode *children[ALPHABET];
    bool endOfWord;
} * TrieNode;

TrieNode createNode();

void insertWord(TrieNode root, const char* word);

bool searchWord(TrieNode root, const char* word);

void freeTrie(TrieNode root);

#endif