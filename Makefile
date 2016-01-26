# GNU Makefile for testing purposes
# Peter Forbes 1/22/2016

######## VARS ########

CC=g++
EXTRA_FLAGS = -lstdc++ -Wall -g

######## BUILD RULES ########

main : main.o
	$(CC) main.o -o main

main.o : main.cxx
	$(CC) -c main.cxx -o main.o $(EXTRA_FLAGS)

clean:
	rm *.o main
