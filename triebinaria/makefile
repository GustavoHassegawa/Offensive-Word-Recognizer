CC = gcc
CFLAGS = -Wall -g -lm

all: main

main: main.o binaryTrie.o
	$(CC) $(CFLAGS) main.o binaryTrie.o -o main

main.o: main.c binaryTrie.h
	$(CC) $(CFLAGS) -c main.c

binaryTrie.o: binaryTrie.c binaryTrie.h
	$(CC) $(CFLAGS) -c binaryTrie.c

clean:
	rm -f *.o main
