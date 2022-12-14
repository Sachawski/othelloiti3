#include <stdio.h>
#include <stdlib.h>
#include "faireUnePartie.h"
#include "obtenirCoupPrive.h"
#include <math.h>
PLT_Plateau initialiserPlateau(void){
    PLT_Plateau plateau;
    plateau=PLT_plateau();
    PLT_poserPion(&plateau, POS_position(3, 3), PN_pion(CLR_noir()));
    PLT_poserPion(&plateau, POS_position(3, 4), PN_pion(CLR_blanc()));
    PLT_poserPion(&plateau, POS_position(4, 3), PN_pion(CLR_blanc()));
    PLT_poserPion(&plateau, POS_position(4, 4), PN_pion(CLR_noir()));
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



CPS_Coups pionMemeCouleur(PLT_Plateau plateau, CP_Coup coup, CPS_Coups pionLegal){
    CPS_Coups lesPionsMemeCouleur;
    int nb, i, x, y, directionX, directionY;
    int recherche;
    POS_Position pos;
    CP_Coup coupTemp;
    recherche= 0;
    lesPionsMemeCouleur= CPS_coups();
    nb= CPS_nbCoups(pionLegal)- 1;
    for (i= 0; i<= nb; i++){
        recherche= 0;
        coupTemp= CPS_iemeCoup(pionLegal, i);
        x= POS_obtenirX(CP_position(coupTemp));
        y= POS_obtenirY(CP_position(coupTemp));
        directionX= x- POS_obtenirX(CP_position(coupTemp));
        directionY= y- POS_obtenirY(CP_position(coupTemp));
        while (!recherche){
            x+= directionX;
            y+= directionY;
            if (x>= 0&& x<=7&& y>= 0&& y<=7){
                pos= POS_position(x, y);
                if (PN_obtenirCouleurSuperieure(PLT_obtenirPion(plateau, pos))== PN_obtenirCouleurSuperieure(CP_pion(coup))){
                    CPS_ajouterCoups(&lesPionsMemeCouleur, CP_coup(PLT_obtenirPion(plateau, pos), pos));
                }
            }
        }
    }
    return lesPionsMemeCouleur;
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

int evaluerNb(PLT_Plateau plateau, CLR_Couleur couleur){
  return 0;
}

void etatPartie(PLT_Plateau plateau, CLR_Couleur *couleur, EtatPartie *egalite){
    EtatPartie e;
    CLR_Couleur c;
    if (!plateauBloque(plateau)){
        e=partieNulle;
        *egalite=e;
    }
    if (plateauBloque(plateau) ){
      e=partieGagnee;
      c=NOIR;
      *egalite=e;
      *couleur=c;
    }
}
void retournerPionsEmprisonnes(PLT_Plateau plateau , CP_Coup coup ) {
    CP_Coup coupTemp;
    int x,y,directionX,directionY;
    POS_Position pos;
    int xCoup = POS_obtenirX(CP_position(coup));
    int yCoup = POS_obtenirX(CP_position(coup));
    CPS_Coups coupsEmprisonnants = pionMemeCouleur(plateau , coup , adversairesAdjacents(plateau,coup));
    for(int i=0 ; i<CPS_nbCoups(coupsEmprisonnants) ; i++){
        coupTemp = CPS_iemeCoup(coupsEmprisonnants, i);
        x = POS_obtenirX(CP_position(coupTemp));
        y = POS_obtenirY(CP_position(coupTemp));
        if(x-xCoup == 0) {
          directionX = 0;
          directionY = (y-yCoup)/abs(y-yCoup);
        }
        else if(y-yCoup == 0){
            directionX = (x-xCoup)/abs(x-xCoup);
            directionY = 0;
        }
        else{
          directionX = (x-xCoup)/abs(x-xCoup);
          directionY = (y-yCoup)/abs(y-yCoup);
        }
        x = x+directionX;
        y = y+directionY;
        while(x!=xCoup && y!=yCoup){
          pos = POS_position(x,y);
          PLT_retournerPion(&plateau,pos);
          x = x+directionX;
          y = y+directionY;
        }

    }
}


