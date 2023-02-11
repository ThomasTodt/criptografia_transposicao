CC = gcc
# CFLAGS = -Wall -Wextra -std=c11

all: cript decript

cript: cript.o utils.o
	$(CC) $(CFLAGS) -o $@ $^

decript: decript.o utils.o
	$(CC) $(CFLAGS) -o $@ $^

cript.o: cript.c utils.h
	$(CC) $(CFLAGS) -c $<

decript.o: decript.c utils.h
	$(CC) $(CFLAGS) -c $<

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o

purge: clean
	rm -f cript decript