#include <stdio.h>
#include <stdlib.h>
#include "faireUnePartie.h"
#include <math.h>
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

int coupLegal(PLT_Plateau plateau, CP_Coup coup){
    POS_Position position;
    CPS_Coups pionLegals;
    position= CP_position(coup);
    pionLegals= CPS_coups();
    if (PLT_estCaseVide(plateau, position)){
        if (CPS_nbCoups(adversairesAdjacents(plateau, coup))!=0){
            pionLegals= adversairesAdjacents(plateau, coup);
        
            if (CPS_nbCoups(pionMemeCouleur(plateau, coup, pionLegals))!=0){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
        
    }
    else
        return 0;
}

CPS_Coups adversairesAdjacents(PLT_Plateau plateau, CP_Coup coup){
    int recherche, minx, miny, maxx, maxy, x, y;
    POS_Position position, positionTemp;
    CPS_Coups coupsLegals;
    recherche= 1;
    coupsLegals= CPS_coups();
    position=CP_position(coup);
    minx= fmax(0, POS_obtenirX(position)- 1);
    miny= fmax(0, POS_obtenirY(position)- 1);
    maxx= fmin(7, POS_obtenirX(position)+ 1);
    maxy= fmin(7, POS_obtenirY(position)+ 1);
    y=miny;
    while ((y<= maxy)&& recherche== 1) {
        x=minx;
        while ((x<= maxx)&& recherche== 1){
            positionTemp= POS_position(x, y);
            if (!(PLT_estCaseVide(plateau, positionTemp)&& POS_obtenirY(position)!=POS_obtenirY(positionTemp)&& POS_obtenirX(position)!= POS_obtenirX(positionTemp))){
                if ((PN_obtenirCouleurSuperieure(PLT_obtenirPion(plateau, positionTemp)))!= PN_obtenirCouleurSuperieure(CP_pion(coup))){
                    CPS_ajouterCoups(&coupsLegals, CP_coup(PLT_obtenirPion(plateau, positionTemp), positionTemp));
                }
            }
            x+= 1;
        }
        y+= 1;
    }
    return coupsLegals;
}
