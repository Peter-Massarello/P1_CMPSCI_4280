CC = gcc

CFLAGS  = -g -Wall -std=c++11 -lstdc++
 
all: scanner

scanner: token.hpp scanner.hpp scanner.cpp main.cpp
	$(CC) -o $@ $^ $(CFLAGS) 
 
clean:
	rm scanner 
	rm -r *.dSYM