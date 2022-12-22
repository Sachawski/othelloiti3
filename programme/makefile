SRCDIR=src
LIBDIR=lib
BINDIR=bin
TESTDIR=$(SRCDIR)/tests
TESTBINDIR=tests
INCLUDEDIR=include #-I /opt/homebrew/Cellar/cunit/2.1-3/include #c'est l'environement pour chen
#LIBTDIR=/opt/homebrew/Cellar/cunit/2.1-3/lib #même c'est pour chen
#CUNITDIR=/opt/homebrew/Cellar/cunit/2.1-3/include
CC = gcc
AR = ar
CFLAGS=-Wall -pedantic -g -std=gnu99
LDFLAGS=-lm 
EXEC=othello

tests:  $(TESTDIR)/testTADpion.o $(TESTDIR)/testTADcoup.o $(TESTDIR)/testTADposition.o $(TESTDIR)/testTADplateau.o $(TESTDIR)/testTADcoups.o $(TESTDIR)/testsTADcouleur.o $(LIBDIR)/libTAD.a 
	$(CC) $(LDFLAGS) -o $(TESTBINDIR)/testTADpion $(TESTDIR)/testTADpion.o -lTAD -L$(LIBDIR)  -lcunit 
	$(CC) $(LDFLAGS) -o $(TESTBINDIR)/testTADcoup $(TESTDIR)/testTADcoup.o -lTAD -L$(LIBDIR)  -lcunit 
	$(CC) $(LDFLAGS) -o $(TESTBINDIR)/testTADplateau $(TESTDIR)/testTADplateau.o -lTAD -L$(LIBDIR)  -lcunit 
	$(CC) $(LDFLAGS) -o $(TESTBINDIR)/testTADcoups $(TESTDIR)/testTADcoups.o -lTAD -L$(LIBDIR)  -lcunit 
	$(CC) $(LDFLAGS) -o $(TESTBINDIR)/testTADcouleur $(TESTDIR)/testTADcouleur.o -lTAD -L$(LIBDIR)  -lcunit 
$(LIBDIR)/libTAD.a : $(SRCDIR)/TADpion.o $(SRCDIR)/TADcouleur.o $(SRCDIR)/TADcoup.o $(SRCDIR)/TADplateau.o $(SRCDIR)/TADcoups.o $(SRCDIR)/TADposition.o 
	$(AR)  -r $@  $^
$(LIBDIR)/libOBT.a : $(SRCDIR)/obtenirCoup.o
	$(AR)  -r $@  $^
$(LIBDIR)/libFUP.a : $(SRCDIR)/faireUnePartie.o
	$(AR)  -r $@  $^
  #ecrire les ficher.o tu va utilise
$(LIBDIR)/lib%.a : $(SRCDIR)/%.o
	$(AR) -r $@ $^

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDEDIR)

$(TESTDIR)/%.o : $(TESTDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDEDIR) 

clean :
	rm -rf $(BINDIR)/*
	rm -rf $(LIBDIR)/*
	rm -rf $(SRCDIR)/*.o
	rm -rf $(TESTDIR)/*.o
	rm -rf $(TESTBINDIR)/*
#make clean
#pour rm tout les truc