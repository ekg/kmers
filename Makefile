CC=g++
CFLAGS=-Wall -O3

all: kmers

clean:
	rm kmers

.PHONY: all clean

kmers: kmers.cpp
	$(CC) $(CFLAGS) kmers.cpp -o kmers
