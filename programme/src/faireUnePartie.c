#include <stdio.h>
#include <stdlib.h>
#include "faireUnePartie.h"
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
        PLT_poserPion(&plateau, position, pion);
      }
      else{
        pion=PN_pion(CLR_blanc());
        position=POS_position(i, j);
        PLT_poserPion(&plateau, position, pion);
      }
    }
  }
  return plateau;
}


void afficherPlateau(PLT_Plateau plateau){
    system("clear");
    int score_black = 0, score_white = 0;
    printf("\n      [OTHELLO]\n\n     a  b  c  d  e  f  g  h\n  ┌─────────────────────────┐\n");
    for( int i=0; i<=63; i++ ){
        if ( i%8 == 0 )
          printf(" %d│ ", i/8+ 1 );
        if (plateau.tabPlateau[i/8][i%8].estVide==1)
          printf(" ┼ ");        //vide
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
        if( i%8 == 7 ) printf("│\n");
    }
    printf("  └─────────────────────────┘\n  ");

}
