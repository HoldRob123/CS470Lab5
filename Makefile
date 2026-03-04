CC = gcc
CFLAGS = -Wall -g

all: Holden_testFS

Holden_testFS: Holden_testFS.o Holden_libFS.o
	$(CC) $(CFLAGS) -o Holden_testFS Holden_testFS.o Holden_libFS.o

Holden_testFS.o: Holden_testFS.c Holden_libFS.h
	$(CC) $(CFLAGS) -c Holden_testFS.c

Holden_libFS.o: Holden_libFS.c Holden_libFS.h
	$(CC) $(CFLAGS) -c Holden_libFS.c

clean:
	rm -f *.o Holden_testFS
