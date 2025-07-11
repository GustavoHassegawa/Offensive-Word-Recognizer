#include "trie.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int functionAlphabet(char letter) {
    if (letter >= 'a' && letter <= 'z') 
        return letter - 'a';
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

bool searchWord(TrieNode root, const char* word) { 
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
