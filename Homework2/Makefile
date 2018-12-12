#uses dependencies and variables for efficient compilation
CC=g++
CFLAGS=-c -Wall
target: first
first: main.o analysis.o PbBST.o  PbTreeNode.o
	$(CC) main.o analysis.o PbBST.o  PbTreeNode.o -o hw2
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
analysis.o: analysis.cpp
	$(CC) $(CFLAGS) analysis.cpp
PbBST.o: PbBST.cpp
	$(CC) $(CFLAGS) PbBST.cpp
PbTreeNode.o: PbTreeNode.cpp
	$(CC) $(CFLAGS) PbTreeNode.cpp
clean:
	rm *o hw2
