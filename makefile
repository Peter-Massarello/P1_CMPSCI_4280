CC = gcc

CFLAGS  = -g -Wall -std=c++11 -lstdc++
 
all: P1

P0: token.hpp scanner.cpp scanner.hpp testScanner.hpp testScanner.cpp main.cpp
	$(CC) -o $@ $^ $(CFLAGS) 
 
clean:
	rm P1 
	rm -r *.dSYM