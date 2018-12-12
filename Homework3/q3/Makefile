#uses dependencies and variables for efficient compilation
CC=g++
CFLAGS=-c -Wall
target: first
first: main.o MaxHeap.o
	$(CC) main.o MaxHeap.o -o q3
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
MaxHeap.o: MaxHeap.cpp
	$(CC) $(CFLAGS) MaxHeap.cpp
clean:
	rm *o q3
