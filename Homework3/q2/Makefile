#uses dependencies and variables for efficient compilation
CC=g++
CFLAGS=-c -Wall
target: first
first: main.o analysis.o AVLTree.o
	$(CC) main.o analysis.o AVLTree.o -o q2
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
analysis.o: analysis.cpp
	$(CC) $(CFLAGS) analysis.cpp
AVLTree.o: AVLTree.cpp
	$(CC) $(CFLAGS) AVLTree.cpp
clean:
	rm *o q2
