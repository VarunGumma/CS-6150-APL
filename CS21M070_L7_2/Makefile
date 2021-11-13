SRCDIR = ./src
OBJDIR = ./obj
BINDIR = ./bin
INCDIR = ./include
CFLAGS = -g -c -I$(INCDIR)
CC = g++

all:	$(BINDIR)/solution

$(BINDIR)/solution:	$(OBJDIR)/ListApplication.o $(OBJDIR)/ListADT.o
	$(CC) -g -o $(BINDIR)/solution $(OBJDIR)/ListApplication.o $(OBJDIR)/ListADT.o

$(OBJDIR)/ListApplication.o:	$(SRCDIR)/ListApplication.cpp
	$(CC) $(CFLAGS) -o $(OBJDIR)/ListApplication.o $(SRCDIR)/ListApplication.cpp

$(OBJDIR)/ListADT.o:	$(SRCDIR)/ListADT.cpp
	$(CC) $(CFLAGS)	-o $(OBJDIR)/ListADT.o $(SRCDIR)/ListADT.cpp

clean:
	rm -fr $(BINDIR)/* $(OBJDIR)/*
