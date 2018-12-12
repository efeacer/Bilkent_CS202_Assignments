#uses dependencies and variables for efficient compilation
CC=g++
CFLAGS=-c -Wall
target: first
first: main.o FlightNetwork.o
	$(CC) main.o FlightNetwork.o -o hw4
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
FlightNetwork.o: FlightNetwork.cpp
	$(CC) $(CFLAGS) FlightNetwork.cpp
clean:
	rm *o q3
