#include <stdio.h>
#include "trie.h"

int main() {
    TrieNode root = createNode();

    insertWord(root, "casa");
    insertWord(root, "carro");
    insertWord(root, "cachorro");

    printf("%s\n", searchWord(root, "casa") ? "Encontrado" : "Não encontrado");
    printf("%s\n", searchWord(root, "cas") ? "Encontrado" : "Não encontrado");
    printf("%s\n", searchWord(root, "carro") ? "Encontrado" : "Não encontrado");

    freeTrie(root);
    return 0;
}