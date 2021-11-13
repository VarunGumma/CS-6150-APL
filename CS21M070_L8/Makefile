# paths and code format are taken from lecture slides
SRCDIR = ./src
OBJDIR = ./obj
BINDIR = ./bin
INCDIR = ./include
CFLAGS = -g -c -I$(INCDIR)
CC = g++

all:	$(BINDIR)/solution

$(BINDIR)/solution:	$(OBJDIR)/HuffManTreeApplication.o $(OBJDIR)/HuffManTreeADT.o
	$(CC) -g -o $(BINDIR)/solution $(OBJDIR)/HuffManTreeApplication.o $(OBJDIR)/HuffManTreeADT.o

$(OBJDIR)/HuffManTreeApplication.o:	$(SRCDIR)/HuffManTreeApplication.cpp
	$(CC) $(CFLAGS) -o $(OBJDIR)/HuffManTreeApplication.o $(SRCDIR)/HuffManTreeApplication.cpp

$(OBJDIR)/HuffManTreeADT.o:	$(SRCDIR)/HuffManTreeADT.cpp
	$(CC) $(CFLAGS)	-o $(OBJDIR)/HuffManTreeADT.o $(SRCDIR)/HuffManTreeADT.cpp

clean:
	rm -fr $(BINDIR)/* $(OBJDIR)/*
