CC = gcc

CFLAGS  = -g -Wall -std=c++11 -lstdc++
 
all: scanner

scanner: main.cpp scanner.cpp scanner.hpp token.hpp
	$(CC) -o $@ $^ $(CFLAGS) 
 
clean:
	rm P1 
	rm -r *.dSYM