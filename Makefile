CC=gcc
CFLAGS=

CFILES=list.c airport.c main.c
OBJECTS=list.o airport.o main.o

BINARY=bin

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(BINARY) *.o
