SRCDIR=src
LIBDIR=lib
BINDIR=bin
TESTDIR=$(SRCDIR)/tests
TESTBINDIR=tests
INCLUDEDIR=include #-I /opt/homebrew/Cellar/cunit/2.1-3/include #c'est l'environement pour chen
#LIBTDIR=/opt/homebrew/Cellar/cunit/2.1-3/lib #même c'est pour chen
CC = gcc
AR = ar
CFLAGS=-Wall -pedantic -g -std=gnu99
#LDFLAGS=-lm c'est pour faireUnePartie
EXEC=othello

tests:  $(TESTDIR)/testTADpion.o $(LIBDIR)/libTAD.a #ici si je veux test "testTADcoup.c" il faut ecrire $(TESTDIR)/testTADcoup.o au lieu de $(TESTDIR)/testTADpion.o
	$(CC) $(LDFLAGS) -o $(TESTBINDIR)/testTAD $(TESTDIR)/testTADpion.o -lTAD -L$(LIBDIR) -L$(LIBTDIR) -lcunit 
  # si je veux test "testTADcoup.c" il faut ecrire $(TESTDIR)/testTADcoup.o au lieu de $(TESTDIR)/testTADpion.o
$(LIBDIR)/libTAD.a : $(SRCDIR)/TADpion.o $(SRCDIR)/TADcouleur.o $(SRCDIR)/TADcoup.o $(SRCDIR)/TADplateau.o #$(SRCDIR)/faireUnePartie.o $(SRCDIR)/obtenirCoup.o
	$(AR)  -r $@  $^
  #ecrire les ficher.o tu va utilise
$(LIBDIR)/lib%.a : $(SRCDIR)/%.o
	$(AR) -r $@ $^

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDEDIR)

$(TESTDIR)/%.o : $(TESTDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDEDIR) -I$(CUNITDIR)

clean :
	rm -rf $(BINDIR)/*
	rm -rf $(LIBDIR)/*
	rm -rf $(SRCDIR)/*.o
	rm -rf $(TESTDIR)/*.o
	rm -rf $(TESTBINDIR)/*
#make clean
#pour rm tout les truc