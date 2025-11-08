CC=gcc
CFLAGS=-c -Wall -g -I.
all: task3

task3: task3.o list.o get.o
	$(CC) task3.o list.o get.o -o task3

task3.o: task3.c
	$(CC) $(CFLAGS) task3.c list.c get.c

list.o: list.c
	$(CC) $(CFLAGS) list.c

get.o: get.c
	$(CC) $(CFLAGS) get.c

clean:
	rm -rf *.o task3
