SRCDIR=src
LIBDIR=lib
BINDIR=bin
TESTDIR=$(SRCDIR)/tests
TESTBINDIR=tests
DOCDIR = doc
DOCU = documentation
INCLUDEDIR=include #-I /opt/homebrew/Cellar/cunit/2.1-3/include #c'est l'environement pour chen
#LIBTDIR=/opt/homebrew/Cellar/cunit/2.1-3/lib #même c'est pour chen
#CUNITDIR=/opt/homebrew/Cellar/cunit/2.1-3/include
CC = gcc
AR = ar
CFLAGS=-Wall -pedantic -g -std=gnu99
LDFLAGS=-lm 
EXEC=othello

all: $(BINDIR)/$(EXEC) $(TESTBINDIR) $(DOCDIR)/$(DOCU) 

prg: $(BINDIR)/$(EXEC) 

tests:  $(TESTDIR)/testTADpion.o $(TESTDIR)/testTADcoup.o $(TESTDIR)/testTADplateau.o $(TESTDIR)/testTADcoups.o $(TESTDIR)/testTADcouleur.o $(LIBDIR)/libTAD.a $(TESTDIR)/testFaireUnePartie.o $(TESTDIR)/testObtenirCoup.o $(LIBDIR)/libOBTFUP.a 
	$(CC) $(LDFLAGS) -o $(TESTBINDIR)/testTADpion $(TESTDIR)/testTADpion.o -lTAD -L$(LIBDIR)  -lcunit 
	$(CC) $(LDFLAGS) -o $(TESTBINDIR)/testTADcoup $(TESTDIR)/testTADcoup.o -lTAD -L$(LIBDIR)  -lcunit 
	$(CC) $(LDFLAGS) -o $(TESTBINDIR)/testTADplateau $(TESTDIR)/testTADplateau.o -lTAD -L$(LIBDIR)  -lcunit 
	$(CC) $(LDFLAGS) -o $(TESTBINDIR)/testTADcoups $(TESTDIR)/testTADcoups.o -lTAD -L$(LIBDIR)  -lcunit 
	$(CC) $(LDFLAGS) -o $(TESTBINDIR)/testTADcouleur $(TESTDIR)/testTADcouleur.o -lTAD -L$(LIBDIR)  -lcunit 
	$(CC) $(LDFLAGS) -o $(TESTBINDIR)/testFaireUnePartie $(TESTDIR)/testFaireUnePartie.o -lOBTFUP -lTAD -L$(LIBDIR)  -lcunit -lm 
	$(CC) $(LDFLAGS) -o $(TESTBINDIR)/testObtenirCoup $(TESTDIR)/testObtenirCoup.o -lOBTFUP -lTAD -L$(LIBDIR)  -lcunit -lm 


doc : $(DOCDIR)/$(DOCU)

$(DOCDIR)/$(DOCU) : $(DOCDIR)/Doxyfile $(SRCDIR)/TADpion.c $(SRCDIR)/TADcouleur.c $(SRCDIR)/TADcoup.c $(SRCDIR)/TADplateau.c $(SRCDIR)/TADcoups.c $(SRCDIR)/TADposition.c $(SRCDIR)/obtenirCoup.c $(SRCDIR)/faireUnePartie.c
	@doxygen $(DOCDIR)/Doxyfile

$(BINDIR)/$(EXEC) : $(SRCDIR)/main.o $(LIBDIR)/libTAD.a $(LIBDIR)/libOBTFUP.a  $(LIBDIR)/libINTER.a
	$(CC) $(LDFLAGS) -o $@ $< -lOBTFUP -lTAD -lINTER -Llib -lm 

$(LIBDIR)/libTAD.a : $(SRCDIR)/TADpion.o $(SRCDIR)/TADcouleur.o $(SRCDIR)/TADcoup.o $(SRCDIR)/TADplateau.o $(SRCDIR)/TADcoups.o $(SRCDIR)/TADposition.o 
	$(AR)  -r $@  $^

$(LIBDIR)/libOBTFUP.a : $(SRCDIR)/obtenirCoup.o $(SRCDIR)/faireUnePartie.o 
	$(AR)  -r $@  $^
	
$(LIBDIR)/libINTER.a : $(SRCDIR)/IMB.o $(SRCDIR)/IHM.o 
	$(AR)  -r $@  $^

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $^ $(CFLAGS) -I$(INCLUDEDIR)

$(TESTDIR)/%.o : $(TESTDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDEDIR)

clean :
	rm -rf $(BINDIR)/*
	rm -rf $(LIBDIR)/*
	rm -rf $(SRCDIR)/*.o
	rm -rf $(TESTDIR)/*.o
	rm -rf $(TESTBINDIR)/*
	rm -rf $(DOCDIR)/$(DOCU)

#make clean
#pour rm tout les truc
