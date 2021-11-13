SRCDIR = ./src
OBJDIR = ./obj
BINDIR = ./bin
INCDIR = ./include
CFLAGS = -g -c -I$(INCDIR)
CC = gcc

all:	$(BINDIR)/solution

$(BINDIR)/solution:	$(OBJDIR)/SortingApplication.o $(OBJDIR)/SortingAlgos.o
	$(CC) -g -o $(BINDIR)/solution $(OBJDIR)/SortingApplication.o $(OBJDIR)/SortingAlgos.o

$(OBJDIR)/SortingApplication.o:	$(SRCDIR)/SortingApplication.c 
	$(CC) $(CFLAGS) -o $(OBJDIR)/SortingApplication.o $(SRCDIR)/SortingApplication.c

$(OBJDIR)/SortingAlgos.o:	$(SRCDIR)/SortingAlgos.c
	$(CC) $(CFLAGS)	-o $(OBJDIR)/SortingAlgos.o $(SRCDIR)/SortingAlgos.c

clean:
	rm -fr $(BINDIR)/* $(OBJDIR)/*
