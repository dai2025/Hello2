CC=gcc
CFLAGS=-O0 -Wall
OBJS=Hello2.o

TARGET=Hello2

# speces -> Tabs 8
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
clean:
	rm -f *.o Hello2
