#include <stdio.h>
#include <stdlib.h>
#include "faireUnePartie.h"
#include <math.h>
PLT_Plateau initialiserPlateau(void){
    PLT_Plateau plateau;
    PN_Pion pion;
    POS_Position position;
    plateau=PLT_plateau();
    PLT_poserPion(&plateau, POS_position(3, 3), PN_pion(CLR_noir()));
    PLT_poserPion(&plateau, POS_position(3, 4), PN_pion(CLR_blanc()));
    PLT_poserPion(&plateau, POS_position(4, 3), PN_pion(CLR_blanc()));
    PLT_poserPion(&plateau, POS_position(4, 4), PN_pion(CLR_noir()));
    
  /*for (int i=3; i<=4; i++){
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
  }*/
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

void etatPartie(PLT_Plateau plateau, CLR_Couleur *couleur, EtatPartie *egalite){
    EtatPartie e;
    CLR_Couleur c;
    if (/*Conditions de départage des égalités*/1){
      e=Egalisation;
      *egalite=e;
    }
    if (/*Situation gagnante*/1){
      e=gagnant;
      c=NOIR;/*couleur gagnant*/
      *egalite=gagnant;
      couleur=c;/*couleur gagnant*/
    }
    if (/*Pas encore fini*/1){
      e=gagnant;
      *egalite=e;
    }
}

int plateauBloque(PLT_Plateau plateau){
  CP_Coup coup; unsigned short i; unsigned short j; POS_Position pos;
  for(i=1;LARGEUR_PLATEAU;i++){
    for(j=1;HAUTEUR_PLATEAU;j++){
      pos = POS_position(i,j);
      coup = CP_coup(PLT_obtenirPion(plateau,pos));
      if(cardinalite(prisAuPiege(plateau,coup)) != 0){
	return 0;
      }
    }
  }
  return 1;
}

int plateauBloque(PLT_Plateau plateau){
  POS_Position pos; unsigned short i; unsigned short j;
  for(i=1;LARGEUR_PLATEAU;i++){
    for(j=1;HAUTEUR_PLATEAU;j++){
      pos = POS_position(i,j);
      if(PLT_estCaseVide(plateau,pos)){
	return 0;
      }
    }
  }
  return 1;
}
