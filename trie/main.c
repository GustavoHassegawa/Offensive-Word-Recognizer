#include <stdio.h>
#include <stdlib.h>
#include "trie.h"
#include <ctype.h>
#include <string.h>


void verificar_palavras(TrieNode raiz, const char *frase) {
    int i = 0, j = 0, nivel;
    int len = strlen(frase);
    char palavra[128];  

    while (i <= len) {
        if (functionAlphabet(frase[i]) >= 0 && frase[i] != '\0') {
            if (j < 127)
                palavra[j++] = tolower(frase[i]);  
        } else if (j > 0) {
            palavra[j] = '\0';
            if (searchWord(raiz, palavra, &nivel)) {
                printf("'%s' encontrada na trie. Profundidade: %d\n", palavra, nivel);
            }
            j = 0;
        }
        i++;
    }
}

void read_string_getchar(char **str) {
    int capacityString = 10, tamanho = 0;
    char c; 
    *str = malloc(capacityString * sizeof(char));

    while ((c = getchar()) != '\n' && c != EOF) {
        if (tamanho + 1 >= capacityString) {
            capacityString *= 2;
            *str = (char *)realloc(*str, capacityString * sizeof(char));
        }

        (*str)[tamanho++] = (char)c;
    }
    (*str)[tamanho] = '\0';
}

int main() {
    printf("\033[?1049h");
    printf("\033[H\033[J");

    TrieNode raiz = createNode();
    char * palavra;
    char * texto;

    printf("------INSIRA AS PALAVRAS NA LISTA NEGRA------\n");
    while(1) {
        read_string_getchar(&palavra);
        if (palavra[0] == '\0') {
            free(palavra);
            break;
        }
        insertWord(raiz, palavra);
        updateDepth(raiz, 0);
        free(palavra);
    }

    printf("\033[H\033[J");
    printf("------INSIRA O TEXTO A SER VERIFICADO------\n");
    
    while(1) {
        read_string_getchar(&texto);
        if (texto[0] == '\0') {
            free(texto);    
            break;
        }
        printf("\n");
        verificar_palavras(raiz, texto);
        free(texto);
    }
    freeTrie(raiz);
    printf("\033[?1049l");
    return 0;
}
