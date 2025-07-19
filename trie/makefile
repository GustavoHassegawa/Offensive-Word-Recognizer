CC = gcc
CFLAGS = -Wall -g -lm

all: main

main: main.o trie.o
	$(CC) $(CFLAGS) main.o trie.o -o main

main.o: main.c trie.h
	$(CC) $(CFLAGS) -c main.c

trie.o: trie.c trie.h
	$(CC) $(CFLAGS) -c trie.c

clean:
	rm -f *.o main
