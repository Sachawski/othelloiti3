#include <obtenirCoup.h>
#include <faireUnePartie.h>
int main(int argc, char *argv[]){
    CLR_Couleur coulourGagnant;
    EtatPartie egalite;
    Mode mode;
    coulourGagnant=NOIR;
    menu(&mode);
    faireUnePartie(obtenirCoupEnFctDuJoueur, obtenirCoupEnFctDuJoueur, afficherPlateau, &egalite, coulourGagnant, mode);
  return 0;
}