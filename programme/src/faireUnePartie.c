#include <stdio.h>
#include <stdlib.h>
#include "faireUnePartie.h"
#include "obtenirCoupPrive.h"
#include <math.h>
#include <assert.h>
#include "TADplateau.h"
#include "TADpion.h"
#include "TADposition.h"
#include "TADcouleur.h"
#include "TADcoup.h"
#include "obtenirCoup.h"
#include "TADcoups.h"

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
    for( int i=0; i<=LARGEUR_PLATEAU*HAUTEUR_PLATEAU-1; i++ ){
        if ( i%LARGEUR_PLATEAU == 0 )
          printf(" %d│ ", i/LARGEUR_PLATEAU+ 1 );
        if (plateau.tabPlateau[i/LARGEUR_PLATEAU][i%LARGEUR_PLATEAU].estVide==1)
          printf(" ┼ ");        //vide
        else{
          switch ( plateau.tabPlateau[i/LARGEUR_PLATEAU][i%LARGEUR_PLATEAU].casePion.couleur ){
            case NOIR:
                printf(" ○ ");        //NOIR
                break;
            case BLANC:
                printf(" ● ");        //BLANC
                break;
          }
        }
        if( i%LARGEUR_PLATEAU == 7 ) printf("│\n");
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
            if (x>= 0&& x<=LARGEUR_PLATEAU-1&& y>= 0&& y<=HAUTEUR_PLATEAU-1){
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
    int scoreBlanc, scoreNoir;
    scoreBlanc=0;
    scoreNoir=0;
    for (int i=0; i<=LARGEUR_PLATEAU-1; i++){
        for (int j=0; j<=HAUTEUR_PLATEAU-1; j++){
            if (plateau.tabPlateau[i][j].estVide==0){
                switch(PN_obtenirCouleurSuperieure(plateau.tabPlateau[i][j].casePion)){
                    case BLANC: scoreBlanc+=1;
                    case NOIR: scoreNoir+=1;
                }
            }
        }
    }
    if (couleur==BLANC)
        return scoreBlanc;
    else
        return scoreNoir;
}

void etatPartie(PLT_Plateau plateau, CLR_Couleur *couleur, EtatPartie *egalite){
    EtatPartie e;
    CLR_Couleur c;
    int scoreBlanc, scoreNoir;
    if (!plateauBloque(plateau)){
        e=partieNulle;
        *egalite=e;
    }
    if (plateauBloque(plateau) ){
        scoreBlanc= evaluer(plateau, BLANC);
        scoreNoir= evaluer(plateau, NOIR);
        if (scoreBlanc> scoreNoir){
            e= partieGagnee;
            c= BLANC;
            *egalite=e;
            *couleur=c;
        }
        if (scoreNoir> scoreBlanc){
            e= partieGagnee;
            c= NOIR;
            *egalite=e;
            *couleur=c;
        }
        if (scoreNoir== scoreBlanc){
            e= partieEegale;
            *egalite=e;
        }
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

void jouer(PLT_Plateau * plateau, CP_Coup coup){
    assert(coupLegal);
    retournerPionsEmprisonnes(*plateau,coup);
}

void menu(Mode *mode){
    char c;
    int i;
    printf("\n            [OTHELLO]\n\n   ");
    printf("          NEW GAME\n");
    printf("            (press n)\n");
    do{
        scanf("%c",&c);
    }while(c=='n');
    system("clear");
    printf("\n        IA vs IA\n");
    printf("\n        press 1\n");
    printf("\n        IA vs Humain\n");
    printf("\n        press 2\n");
    printf("\n        Humain vs Humain\n");
    printf("\n        press 3\n");
    do{
        scanf("%d",&i);
    }while(i=='1' || i=='2' ||i=='3');
    switch(i){
        case 1: *mode=IAvsIA;
        case 2: *mode=IAvsHumain;
        case 3: *mode=HumainvsHumain;
    }
}
void faireUnePartie(CP_Coup (*obtenirCoupBlanc)(PLT_Plateau plateau), CP_Coup (*obtenirCoupNoir)(PLT_Plateau plateau), void (*afficher)(PLT_Plateau plateau), EtatPartie *egalite, CLR_Couleur couleur){
    PLT_Plateau plateau;
    PN_Pion joueurCourant;
    CP_Coup coup;
    CLR_Couleur couleurGagnant;
    EtatPartie e;
    e=partieNulle;
    couleurGagnant=NOIR;
    joueurCourant= PN_pion(NOIR);
    plateau= initialiserPlateau();
    afficherPlateau(plateau);
    while (e==partieNulle){
        if (PN_obtenirCouleurSuperieure(joueurCourant)==NOIR){
            coup=(*obtenirCoupNoir)(plateau);
        }
        else
            coup=(*obtenirCoupBlanc)(plateau);
        jouer(&plateau, coup);
        afficherPlateau(plateau);
        PN_retournerPion(&joueurCourant);
        etatPartie(plateau, &couleurGagnant, &e);
    }
}
