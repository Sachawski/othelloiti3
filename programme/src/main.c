#include <obtenirCoup.h>
#include <faireUnePartie.h>
#include "IHM.h"
#include "IMB.h"
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  EtatPartie etat;
  CLR_Couleur gagnant;

  if (argc==1) {
    FILE *fichier = fopen("src/aide.txt", "r");

    if (fichier == NULL) {
      perror("Erreur lors de l'ouverture du fichier");
      return 0 ;
    }

    char ligne[1024];
    while (fgets(ligne, sizeof(ligne), fichier)) {
      printf("%s", ligne);
    }

    fclose(fichier);
  } else {
    if (strcmp(argv[1],"standard")==0) {
      if (strcmp(argv[2],"blanc")==0)
        faireUnePartie(interactionJoueur, obtenirCoup, afficherPlateau, &etat, &gagnant);
      if (strcmp(argv[2],"noir")==0)
        faireUnePartie(obtenirCoup, interactionJoueur, afficherPlateau, &etat, &gagnant);
      afficherFinDePartie(gagnant,etat);
    }

    if (strcmp(argv[1],"tournoi")==0) {
      if (strcmp(argv[2],"blanc")==0)
        faireUnePartie(obtenirCoup, interactionBroker, envoiBroker, &etat, &gagnant);
      if (strcmp(argv[2],"noir")==0)
        faireUnePartie(interactionBroker, obtenirCoup, envoiBroker, &etat, &gagnant);
      finDePartieBroker(gagnant,etat);
    }
  return 0;
  }
} 