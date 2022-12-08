#include <stdio.h>
#include <stdlib.h>
#include "TADplateau.h"
#include "TADpion.h"
#include "TADposition.h"
#include "TADcoup.h"
#include "TADcoups.h"
#include "TADcouleur.h"
PLT_Plateau initialiserPlateau(void){
  PLT_Plateau plateau;
  PN_Pion pion;
  POS_Position position;
  plateau=PLT_plateau();  
  for (int i=3; i<=4; i++){
    for (int j=3; j<=4; j++){
      if (i==j){
        pion=PN_pion(CLR_noir());
        position=POS_position(i, j);
        /*PLT_poserPion(&plateau, position, pion);*/
      }
      /*else{
        pion=PN_pion(CLR_blanc());
        position=POS_position(i, j);
        PLT_poserPion(&plateau, position, pion);
      }*/
    }
  }
  return plateau;
}


void afficherPlateau( PLT_Plateau plateau ){
    system("cls");
    int score_black = 0, score_white = 0;
    printf("\033[0m\n        [OTHELLO]\n\n    1 2 3 4 5 6 7 8\n  ┌─────────────────┐\n");
    for( int i=0; i<=63; i++ ){
        if ( i%8 == 0 )  
          printf(" %c│ ", i/8+'A' );
        if (plateau.tabPlateau[i/8][i%8].estVide==1)
          printf("┼ ");        //vide
        else{
          switch ( plateau.tabPlateau[i/8][i%8].casePion.couleur ){
            case  NOIR:
                printf("○");        //NOIR
                score_black++; break;
            case BLANC:
                printf("●");        //BLANC
                score_white++; break;
            /*case  2:
            case -2:
                printf("\033[32m┼ \033[0m"); break;    //提示位置*/
          }
        }
        if( i%8 == 7 ) printf("│\n");
    }
    printf("  └─────────────────┘\n   NOIR:%2d | BLANC:%2d \n", score_black, score_white);
    printf("─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─\n");
}

int main(void){
  PLT_Plateau plateau;
  plateau=initialiserPlateau();
  /*afficherPlateau(plateau);*/
  return 0;
}