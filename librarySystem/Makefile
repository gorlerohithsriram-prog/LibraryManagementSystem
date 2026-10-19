CC = gcc
CFLAGS = -Wall -Wextra -g

library: main.o library.o
	$(CC) $(CFLAGS) -o library main.o library.o

main.o: main.c library.h
	$(CC) $(CFLAGS) -c main.c

library.o: library.c library.h
	$(CC) $(CFLAGS) -c library.c

clean:
	rm -f *.o library library.exe library.dat

.PHONY: clean
