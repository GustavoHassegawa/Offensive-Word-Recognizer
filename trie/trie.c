#include "trie.h"
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

TrieNode createNode() {
    TrieNode newNode = malloc(sizeof(struct trienode));
    
    newNode->endOfWord = false;

    for (int i = 0; i < ALPHABET; i++) {
        newNode->children[i] = NULL;
    }

    return newNode;
}

void insertWord(TrieNode root, const char* word) {
    TrieNode currentNode = root;
    char letter;
    int indexAlphabet;

    for (int i = 0; i < strlen(word); i++) {
        letter = tolower(word[i]);
        indexAlphabet = functionAlphabet(letter);

        if (indexAlphabet == -1) {
            break;
        }

        if (currentNode->children[indexAlphabet] == NULL) {
            currentNode->children[indexAlphabet] = createNode();
        }
        currentNode = currentNode->children[indexAlphabet];
    }
    currentNode->endOfWord = true;
}

bool searchWord(TrieNode root, const char* word, int * level) { 
    TrieNode currentNode = root;
    char letter;
    int indexAlphabet;

    for (int i = 0; i < strlen(word); i++) {
        letter = tolower(word[i]);
        indexAlphabet = functionAlphabet(letter);

        if (indexAlphabet != -1 && currentNode->children[indexAlphabet] == NULL) {
            return false;
        }
        currentNode = currentNode->children[indexAlphabet];
    }
    * level = currentNode->depth;
    return currentNode != NULL && currentNode->endOfWord;
}

void freeTrie(TrieNode root) {
    if (root != NULL) {
        for (int i = 0; i < ALPHABET; i++) {
            freeTrie(root->children[i]);
        }
        free(root);
    }
}

void updateDepth(TrieNode root, int level) {
    if (root == NULL) return;

    root->depth = level;
    for (int i = 0; i < ALPHABET; i++) {
        updateDepth(root->children[i], level + 1);
    }
}

int memoryUsed(TrieNode root) {
    if (root == NULL)
        return 0;

    int total = sizeof(struct trienode);

    for (int i = 0; i < ALPHABET; i++) {
        total += memoryUsed(root->children[i]);
    }

    return total;
}