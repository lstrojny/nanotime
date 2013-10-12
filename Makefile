CC_OPTS=-o nanotime
CC = gcc
SRC = nanotime.c

linux:
	$(CC) -Wall $(CFLAGS) -lrt $(CC_OPTS) $(SRC)

mach:
	$(CC) $(CFLAGS) $(CC_OPTS) $(SRC)

clean:
	rm -f nanotime
