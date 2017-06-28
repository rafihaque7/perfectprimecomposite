CFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c99
CC = gcc $(CFLAGS)

.PHONY: all
	all: parfait

parfait:	parfait.o bv.o sieve.o
	$(CC) parfait.c -lm -o parfait

parfait.o:	parfait.c
	$(CC) -c parfait.c

bv.o	:	bv.c
	$(CC) -c bv.c

sieve.o:	sieve.c
	$(CC) -c sieve.c

.phony:clean
clean:
	rm parfait.o bv.o sieve.o parfait
