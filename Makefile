CC=gcc --std=c99 -g

all: test

test: test.c list.o
	$(CC) test.c list.o -o test

list.o: list.c list.h
	$(CC) -c list.c

clean:
	rm -f *.o test
