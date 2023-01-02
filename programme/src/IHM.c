/**
2 * \file IHM.c
3 * \brief Fichier contenant les fonctions de l'IHM
4 * \author V. Turnel, S. Wojciechowski
5 * \version 1.0
6 * \date 04/12/2022
7 *
8 */

#include "faireUnePartie.h"
#include "IHM.h"
#include <stdio.h>
#include <stdlib.h>

/**
* \fn afficherPlateau(PLT_Plateau plateau, CP_Coup coup, int possibilite)
* \brief Affiche le plateau actuel dans le terminal.
* \param plateau Représente le plateau de jeu.
* \param coup Inutile de cette procédure.
* \param possibilite Indique si le joueur à la possibilité de jouer.
*/
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


/**
* \fn afficherFinDePartie(CLR_Couleur couleurGagnante, EtatPartie etat)
* \brief Affiche L'état de fin de partie dans le terminal.
* \param couleurGagnante La couleur gagnate en cas de victoire.
* \param etat Etat du plateau de la partie en fin de jeu : Victoire | Egalite.
*/
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


/**
* \fn interractionJoueur(PLT_Plateau plateau, CLR_Couleur couleur, int profondeur)
* \brief Permet d'obtenir un coup de la part d'un Humain
* \param plateau Représente le plateau de jeu.
* \param couleur Couleur du joueur humain.
* \param profondeur Inutile dans cette fonction.
*/
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