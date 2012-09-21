CC=g++
CFLAGS=-Wall -O3

all: kmers

clean:
	rm *.o

.PHONY: all clean

kmers: kmers.cpp
	$(CC) $(CFLAGS) kmers.cpp -o kmers
