CC = gcc
CFLAGS = -Wall -g
LIBS = -lmicrohttpd
SRCDIR = src
BINDIR = bin

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(BINDIR)/%.o, $(SOURCES))

all: $(BINDIR)/main

$(BINDIR)/main: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(BINDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(BINDIR)/*.o $(BINDIR)/main
