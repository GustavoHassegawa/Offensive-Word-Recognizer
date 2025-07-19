#include "binaryTrie.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int functionAlphabet(char letter) {
    if (letter >= 'a' && letter <= 'z') 
        return letter - 'a';
    else if (letter >= 'A' && letter <= 'Z')
        return letter - 'A';
    else
        return -1;
}

BinaryTrieNode createNode() {
    BinaryTrieNode newNode = malloc(sizeof(struct binarytrienode));
    
    newNode->endOfWord = false;
    newNode->left_son = NULL;
    newNode->right_son = NULL;
    newNode->depth = 0;

    return newNode;
}

void insertWord(BinaryTrieNode root, const char *word) {
    BinaryTrieNode currentNode = root;

    for (int i = 0; word[i] != '\0'; i++) {
        char ch = word[i];

        for (int bit = 7; bit >= 0; bit--) {
            int charBit = (ch >> bit) & 1;

            if (charBit == 0) {
                if (currentNode->left_son==  NULL)
                    currentNode->left_son = createNode();
                currentNode = currentNode->left_son;
            } else {
                if (currentNode->right_son == NULL)
                    currentNode->right_son = createNode();
                currentNode = currentNode->right_son;
            }
        }
    }

    currentNode->endOfWord = true;
}

bool searchWord(BinaryTrieNode root, const char *word, int * level) {
    BinaryTrieNode currentNode = root;

    for (int i = 0; word[i] != '\0'; i++) {
        unsigned char ch = word[i];

        for (int bit = 7; bit >= 0; bit--) {
            int charBit = (ch >> bit) & 1;

            if (charBit == 0) {
                if (!currentNode->left_son)
                    return false;
                currentNode = currentNode->left_son;
            } else {
                if (!currentNode->right_son)
                    return false;
                currentNode = currentNode->right_son;
            }
        }
    }
    * level = currentNode->depth;
    return currentNode->endOfWord;
}

void freeTrie(BinaryTrieNode root) {
    if (root != NULL) {
        freeTrie(root->left_son);
        freeTrie(root->right_son);
        free(root);
    }
}

void updateDepth(BinaryTrieNode root, int level) {
    if (root == NULL) return;

    root->depth = level;

    updateDepth(root->left_son, level + 1);
    updateDepth(root->right_son, level + 1);
}