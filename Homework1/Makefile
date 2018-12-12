#uses dependencies and variables for efficient compilation



CC=g++

CFLAGS=-c -Wall



target: first



first: main.o sorting.o 
	
	$(CC) main.o sorting.o -o hw1



main.o: main.cpp
	
	$(CC) $(CFLAGS) main.cpp



sorting.o: sorting.cpp
	
	$(CC) $(CFLAGS) sorting.cpp



clean:
	rm *o hw1