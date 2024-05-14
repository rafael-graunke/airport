CC=gcc
CFLAGS=-g

CFILES=list.c airport.c history.c main.c
OBJECTS=list.o airport.o history.o main.o

BINARY=bin

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -g -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(BINARY) *.o
