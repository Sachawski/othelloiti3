#include <stdio.h>
#include <stdlib.h>
#include "faireUnePartie.h"
#include "obtenirCoupPrive.h"
#include "obtenirCoup.h"
#include <math.h>
#include <assert.h>
#include <unistd.h>
#include <time.h>


PLT_Plateau initialiserPlateau(void){
    PLT_Plateau plateau;
    plateau=PLT_plateau();
    PLT_poserPion(&plateau, POS_position(3, 3), PN_pion(CLR_blanc()));
    PLT_poserPion(&plateau, POS_position(3, 4), PN_pion(CLR_noir()));
    PLT_poserPion(&plateau, POS_position(4, 3), PN_pion(CLR_noir()));
    PLT_poserPion(&plateau, POS_position(4, 4), PN_pion(CLR_blanc()));
  return plateau;
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
            if (!(PLT_estCaseVide(plateau, positionTemp))&& 
            !(POS_obtenirY(position)==POS_obtenirY(positionTemp)&&
             POS_obtenirX(position)==
             POS_obtenirX(positionTemp))){
                if ((PN_obtenirCouleurSuperieure
                (PLT_obtenirPion(plateau, positionTemp)))!=
                 PN_obtenirCouleurSuperieure(CP_pion(coup))){
                    CPS_ajouterCoups(&coupsLegals, CP_coup
                    (PLT_obtenirPion(plateau, positionTemp), positionTemp));
                }
            }
            x+= 1;
        }
        y+= 1;
    }
    return coupsLegals;
}

CPS_Coups pionMemeCouleur(PLT_Plateau plateau, CP_Coup coup, CPS_Coups pionLegal) {
    CPS_Coups lesPionsMemeCouleur;
    int nb, i, x, y, directionX, directionY;
    int recherche;
    POS_Position pos;
    CP_Coup coupTemp;
    recherche= 0;
    lesPionsMemeCouleur= CPS_coups();
    nb= CPS_nbCoups(pionLegal);
    for (i= 1; i<= nb; i++){
        recherche= 0;
        coupTemp= CPS_iemeCoup(pionLegal, i);
        x= POS_obtenirX(CP_position(coupTemp));
        y= POS_obtenirY(CP_position(coupTemp));
        directionX= x- POS_obtenirX(CP_position(coup));
        directionY= y- POS_obtenirY(CP_position(coup));
        while (!recherche){
            x+= directionX;
            y+= directionY;
            if (x>= 0&& x<=7&& y>= 0&& y<=7){
                pos= POS_position(x, y);
                if (PLT_estCaseVide(plateau, pos))
                    break;
                if (PN_obtenirCouleurSuperieure(PLT_obtenirPion(plateau, pos))==
                 PN_obtenirCouleurSuperieure(CP_pion(coup)) ){
                    CPS_ajouterCoups(&lesPionsMemeCouleur, CP_coup(PLT_obtenirPion
                    (plateau, pos), pos));
                    break;
                }
            }
            else{
                break;
            }
        }
    }
    return lesPionsMemeCouleur;
}

int coupLegal(PLT_Plateau plateau, CP_Coup coup) {
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
    else {
        return 0;
    }
}


void etatPartie(PLT_Plateau plateau, CLR_Couleur *couleur, EtatPartie *etat){
    int scoreBlanc, scoreNoir;
    if (!plateauBloque(plateau)){
        *etat=partieEnCours;
    }
    if (plateauBloque(plateau) ){
        scoreBlanc= evaluerNb(plateau, BLANC);
        scoreNoir= evaluerNb(plateau, NOIR);
        if (scoreBlanc> scoreNoir){
            *etat=partieGagnee;
            *couleur=BLANC;
        } 
        else {
            if (scoreNoir> scoreBlanc){
                *etat=partieGagnee;
                *couleur=NOIR;
            } 
            else {
                *etat=partieEgal;
            }
        }
    }
}

int evaluerNb(PLT_Plateau plateau, CLR_Couleur couleur){
    int compteur,i,j;
    POS_Position pos ;
    compteur = 0 ;
    for (i=0;i<=7;i++) {
        for (j=0;j<=7;j++) {
            pos = POS_position(i,j);
            if (!PLT_estCaseVide(plateau,pos) &&
             (PN_obtenirCouleurSuperieure(PLT_obtenirPion(plateau,pos)) == couleur)){
                compteur = compteur + 1 ;
            }
        }
    }
    return compteur ;
}


void retournerPionsEmprisonnes(PLT_Plateau *plateau , CP_Coup coup ) {
    CP_Coup coupTemp;
    int x,y,directionX,directionY;
    POS_Position pos;
    int xCoup = POS_obtenirX(CP_position(coup));
    int yCoup = POS_obtenirY(CP_position(coup));
    CPS_Coups coupsEmprisonnants = pionMemeCouleur(*plateau , coup ,
     adversairesAdjacents(*plateau,coup));
    for(int i=1 ; i<=CPS_nbCoups(coupsEmprisonnants) ; i++){
        coupTemp = CPS_iemeCoup(coupsEmprisonnants, i);
        x = POS_obtenirX(CP_position(coupTemp));
        y = POS_obtenirY(CP_position(coupTemp));
        if(x-xCoup == 0) {
          directionX = 0;
          directionY = (yCoup-y)/abs(y-yCoup);
        }
        else if(y-yCoup == 0){
            directionX = (xCoup-x)/abs(x-xCoup);
            directionY = 0;
        }
        else{
          directionX = (xCoup-x)/abs(x-xCoup);
          directionY = (yCoup-y)/abs(y-yCoup);
        }
        x = x+directionX;
        y = y+directionY;
        while(x!=xCoup || y!=yCoup){
          pos = POS_position(x,y);
          PLT_retournerPion(plateau,pos);
          x = x+directionX;
          y = y+directionY;
        }
    }
}


void jouer(PLT_Plateau * plateau, CP_Coup coup){
    retournerPionsEmprisonnes(plateau,coup);
    PLT_poserPion(plateau, CP_position(coup), CP_pion(coup));
   
}

void faireUnePartie(CP_Coup (*obtenirCoupBlanc)(PLT_Plateau plateau,
 CLR_Couleur couleur, int profondeur), CP_Coup (*obtenirCoupNoir)
 (PLT_Plateau plateau, CLR_Couleur couleur, int profondeur), void (*sortie)
 (PLT_Plateau plateau, CP_Coup coup, int possibilite), EtatPartie *etat,
  CLR_Couleur *couleurGagnant){
    PLT_Plateau plateau;
    PN_Pion joueurCourant;
    CP_Coup prochainCoup;
    *etat = partieEnCours;
    time_t start,end;

    joueurCourant= PN_pion(BLANC);
    plateau= initialiserPlateau();

    do {
        //Initialisation chronomètre
        start=time(NULL);

        do {
            prochainCoup = coupEnFctJoueur(obtenirCoupBlanc, obtenirCoupNoir,
             PN_obtenirCouleurSuperieure(joueurCourant), plateau);
        } while (!(coupLegal(plateau,prochainCoup)));
        jouer(&plateau, prochainCoup);

        //Chronomètre
        end=time(NULL);
        if (difftime(start, end)<1)
            sleep(1);

        //Affichage
        sortie(plateau,prochainCoup,1);

        //Changement de joueur
        PN_retournerPion(&joueurCourant);
        if (plateauBloquePourUneCouleur(plateau,
        PN_obtenirCouleurSuperieure(joueurCourant))){
            PN_retournerPion(&joueurCourant);
            sortie(plateau,prochainCoup,0);
        }

        //Actualisation de l'état de la partie
        etatPartie(plateau, couleurGagnant, etat);
    } while (*etat==partieEnCours);
}


CP_Coup coupEnFctJoueur(CP_Coup (*obtenirCoupBlanc)(PLT_Plateau plateau, CLR_Couleur couleur,
 int profondeur), CP_Coup (*obtenirCoupNoir)(PLT_Plateau plateau, CLR_Couleur couleur,
  int profondeur), CLR_Couleur couleur, PLT_Plateau plateau){
    CP_Coup coup;
    if (couleur==NOIR) {
        coup = (*obtenirCoupNoir)(plateau, NOIR, PROFONDEUR);
    }
    else {
        coup = (*obtenirCoupBlanc)(plateau, BLANC, PROFONDEUR);
    }
    return coup;
}
