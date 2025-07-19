#ifndef BINARYTRIE_H
#define BINARYTRIE_H
#include <stdbool.h>

typedef struct binarytrienode {
    struct binarytrienode *left_son; //bit 0
    struct binarytrienode *right_son;//bit 1
    int depth;
    bool endOfWord;
} * BinaryTrieNode;

BinaryTrieNode createNode();

void insertWord(BinaryTrieNode root, const char * word);

bool searchWord(BinaryTrieNode root, const char * word, int * level);

void freeTrie(BinaryTrieNode root);

void updateDepth(BinaryTrieNode root, int level);

int functionAlphabet(char letter);

#endif