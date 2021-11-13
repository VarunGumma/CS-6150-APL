# paths and code format are taken from lecture slides
SRCDIR = ./src
OBJDIR = ./obj
BINDIR = ./bin
INCDIR = ./include
CFLAGS = -g -c -I$(INCDIR)
CC = g++

all:	$(BINDIR)/solution

$(BINDIR)/solution:	$(OBJDIR)/Dijkstra.o $(OBJDIR)/GraphADT.o $(OBJDIR)/MinHeapADT.o
	$(CC) -g -o $(BINDIR)/solution $(OBJDIR)/Dijkstra.o $(OBJDIR)/GraphADT.o $(OBJDIR)/MinHeapADT.o

$(OBJDIR)/MinHeapADT.o:	$(SRCDIR)/MinHeapADT.cpp
	$(CC) $(CFLAGS) -o $(OBJDIR)/MinHeapADT.o $(SRCDIR)/MinHeapADT.cpp

$(OBJDIR)/GraphADT.o:	$(SRCDIR)/GraphADT.cpp
	$(CC) $(CFLAGS) -o $(OBJDIR)/GraphADT.o $(SRCDIR)/GraphADT.cpp

$(OBJDIR)/Dijkstra.o:	$(SRCDIR)/Dijkstra.cpp
	$(CC) $(CFLAGS) -o $(OBJDIR)/Dijkstra.o $(SRCDIR)/Dijkstra.cpp

clean:
	rm -fr $(BINDIR)/* $(OBJDIR)/*
