#ifndef BINARYTRIE_H
#define BINARYTRIE_H
#include <stdbool.h>

typedef struct binarytrienode {
    struct binarytrienode *left_son; //bit 0
    struct binarytrienode *right_son;//bit 1
    bool endOfWord;
} * BinaryTrieNode;

BinaryTrieNode createNode();

void insertWord(BinaryTrieNode root, const char * word);

bool searchWord(BinaryTrieNode root, const char * word);

void freeTrie(BinaryTrieNode root);

#endif