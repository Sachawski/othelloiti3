
#include "obtenirCoup.h"
#include "obtenirCoupPrive.h"
#include "faireUnePartie.h"
#include "TADposition.h" 
#include "TADplateau.h"
#include "TADcoups.h" 
#include "TADcoup.h"
#include <stdlib.h>
#include <stdio.h>

/* Partie Privee */

#define MIN(i, j) (((i) < (j)) ? (i) : (j))
#define MAX(i, j) (((i) > (j)) ? (i) : (j))

void copierPlateau(PLT_Plateau plateau_src, PLT_Plateau *plateau_dst) {
  for (int i = 0; i < LARGEUR_PLATEAU; i++) {
    for (int j = 0; j < HAUTEUR_PLATEAU; j++) {
        plateau_dst->tabPlateau[j][i] = plateau_src.tabPlateau[j][i] ;
    }
  }
}

int compteurCouleur(PLT_Plateau plateau, CLR_Couleur couleur) {
    int compteur,i,j ;
    POS_Position pos ;
    compteur = 0 ;
    for (i = 0; i <= 7; i++) {
        for (j = 0; j <= 7; j++) {
            pos = POS_position(i,j) ;
            if (!PLT_estCaseVide(plateau,pos) && (PN_obtenirCouleurSuperieure(PLT_obtenirPion(plateau,pos)) == couleur)) {
                compteur = compteur + 1 ;
            }
        }
    }
    return compteur ;
}

int evaluer(PLT_Plateau plateau, CLR_Couleur joueur) {
    return score(plateau,joueur)-score(plateau,CLR_changerCouleur(joueur)) ;
}

int score(PLT_Plateau plateau, CLR_Couleur joueur) {
    int score, sommePonderation, i,j ;
    POS_Position tempPos ;
    int ponderation[LARGEUR_PLATEAU][HAUTEUR_PLATEAU] = {
        {100, -20, 10, 5, 5, 10, -20, 100},
        {-20, -50, -2, -2, -2, -2, -50, -20},
        {10, -2, -1, -1, -1, -1, -2, 10},
        {5, -2, -1, -1, -1, -1, -2, 5},
        {5, -2, -1, -1, -1, -1, -2, 5},
        {10, -2, -1, -1, -1, -1, -2, 10},
        {-20, -50, -2, -2, -2, -2, -50, -20},
        {100, -20, 10, 5, 5, 10, -20, 100}
    } ;
    for (i=0;i<8;i++) {
        for (j=0;j<8;j++) {
            tempPos = POS_position(i,j) ;
            if ((!PLT_estCaseVide(plateau,tempPos)) && (PN_obtenirCouleurSuperieure(PLT_obtenirPion(plateau,tempPos)) == joueur )) {
                sommePonderation = sommePonderation + ponderation[j][i] ;
            }

        }
    }
    score = compteurCouleur(plateau,joueur) + sommePonderation ;
    return score ;
}

CPS_Coups obtenirCoupsPossibles(PLT_Plateau unPlateau, CLR_Couleur joueurRef) {
    CPS_Coups resultat ;
    int i,j ;
    CP_Coup coupTemp ;
    resultat = CPS_coups() ;
    for(i = 0; i<HAUTEUR_PLATEAU; i++) {
        for(j = 0; j < LARGEUR_PLATEAU; j++) {
            coupTemp = CP_coup(PN_pion(joueurRef),POS_position(j,i)) ;
            if(coupLegal(unPlateau,coupTemp)) {
                CPS_ajouterCoups(&resultat,coupTemp) ;
            }
        }
    }
    return resultat ;
}

int  plateauBloque(PLT_Plateau plateau) {
    return plateauBloquePourUneCouleur(plateau,NOIR) || plateauBloquePourUneCouleur(plateau,BLANC) ;
}

int plateauBloquePourUneCouleur(PLT_Plateau plateau, CLR_Couleur couleur) {
    CPS_Coups cps ;
    cps = obtenirCoupsPossibles(plateau,couleur) ;
    return (cps.nbTotalCoups == 0) ;
}

int scoreDUnCoup(PLT_Plateau unPlateau, CLR_Couleur joueurRef, CLR_Couleur joueurCourant, CP_Coup unCoup, int profondeur, int alpha, int beta) {
    PLT_Plateau copieUnPlateau ;
    copierPlateau(unPlateau,&copieUnPlateau) ;
    jouer(&copieUnPlateau,unCoup) ;
    if(plateauBloque(copieUnPlateau) || (profondeur == 0)) {
        return evaluer(copieUnPlateau,joueurRef) ;
    }
    else {
        if(!(plateauBloquePourUneCouleur(copieUnPlateau,CLR_changerCouleur(joueurCourant)))) {
            joueurCourant = CLR_changerCouleur(joueurCourant) ;
        }
        return alphaBeta(copieUnPlateau,joueurRef,joueurCourant,profondeur-1,alpha,beta) ;
    }
}

int alphaBeta(PLT_Plateau unPlateau, CLR_Couleur joueurRef, CLR_Couleur joueurCourant, int profondeur, int alpha, int beta) {
    CPS_Coups coupsPossibles ;
    int resultat, score, i ;

    coupsPossibles = obtenirCoupsPossibles(unPlateau,joueurCourant) ;
    resultat = scoreDUnCoup(unPlateau,joueurRef,joueurCourant,CPS_iemeCoup(coupsPossibles,1),profondeur,alpha,beta) ;
    for(i = 2; i <= CPS_nbCoups(coupsPossibles); i++) {
        score = scoreDUnCoup(unPlateau,joueurRef,joueurCourant,CPS_iemeCoup(coupsPossibles,i),profondeur,alpha,beta) ;
        if(joueurRef == joueurCourant) {
            resultat = MAX(resultat,score) ;
            if(resultat <= alpha) {
                return resultat ;
            }
            beta = MIN(beta,resultat) ;
        } else {
            resultat = MIN(resultat,score) ;
            if(beta <= resultat) {
                return resultat ;
            }
            alpha = MAX(alpha,resultat) ;
        }
    }
    return resultat;
}

/* Partie publique */

CP_Coup obtenirCoup(PLT_Plateau plateau, CLR_Couleur joueur, int profondeur)
{
    CP_Coup resultat ;
    CPS_Coups cps ;
    int score, meilleurScore, i ;
    
    cps = obtenirCoupsPossibles(plateau,joueur) ;
    resultat = CPS_iemeCoup(cps,1) ;
    meilleurScore = scoreDUnCoup(plateau,joueur,joueur,resultat,profondeur,INF_NEGATIF,INF_POSITIF) ;
    for (i = 2; i < cps.nbTotalCoups; i++) {
        score = scoreDUnCoup(plateau,joueur,joueur,CPS_iemeCoup(cps,i),profondeur,INF_NEGATIF,INF_POSITIF) ;
        if ( score > meilleurScore )  {
            resultat = CPS_iemeCoup(cps,i) ;
            meilleurScore = score ;
        }
    }
    return resultat ;
}