#include "faireUnePartie.h"
#include "IHM.h"
#include <stdio.h>
#include <stdlib.h>

void afficherPlateau(PLT_Plateau plateau, CP_Coup coup,int possibilite){
    system("clear");
    printf("\n      [OTHELLO]\n\n     a  b  c  d  e  f  g  h\n  |-------------------------|\n");
    for( int i=0; i<=63; i++ ){
        if ( i%8 == 0 )
          printf(" %d| ", i/8+ 1 );
        if (plateau.tabPlateau[i/8][i%8].estVide==1)
          printf(" + ");        //vide
        else{
          switch ( plateau.tabPlateau[i/8][i%8].casePion.couleur ){
            case NOIR:
                printf(" ○ ");        //NOIR
                break;
            case BLANC:
                printf(" ● ");        //BLANC
                break;
          }
        }
        if( i%8 == 7 ) printf("|\n");
    }
    printf("  |-------------------------|\n");
    if (!(possibilite))
      printf("Vous ne pouvez pas jouer\n");


}

void afficherFinDePartie(CLR_Couleur couleurGagnante, EtatPartie etat){
  system("clear");
  char *gagnant;
  if(etat==partieGagnee){
    if(couleurGagnante == NOIR)
      gagnant = "NOIRS ";
    else
      gagnant = "BLANCS";

    printf("  |-------------------------|\n");
    printf("  |   Victoire des %s   |\n",gagnant);
    printf("  |-------------------------|\n");
  } else {
    printf("  |-------------------------|\n");
    printf("  |         Egalité         |\n");
    printf("  |-------------------------|\n");
  }
}

CP_Coup interactionJoueur(PLT_Plateau plateau, CLR_Couleur couleur, int profondeur){
  CP_Coup coupJoueur;
  PN_Pion pionJoueur;
  POS_Position coorTemp;

  char x;
  int y;

  pionJoueur = PN_pion(couleur);

  do {
    afficherPlateau(plateau,coupJoueur,1);
    printf("  Position :");
    scanf(" %c",&x);
    scanf(" %dn",&y);
    coorTemp = POS_position(x-97,y-1);
    coupJoueur = CP_coup(pionJoueur,coorTemp);
  } while (!('a' <= x && x <='h' && 1 <= y && y <= 8 ));

  return coupJoueur;
}