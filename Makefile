CC=gcc
CFLAGS=-O0 -g -Wall -Wextra -ansi -pedantic-errors
OBJS=Hello2.o

TARGET=Hello2

# speces -> Tabs 8 -> $(CFLAGS)
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
clean:
	rm -f *.o Hello2
