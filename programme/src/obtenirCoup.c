#include "../include/obtenirCoup.h"
#include "../include/faireUnePartiePrive.h"
#include "../include/definitionTypes.h"
#include "../include/TADcoup.h" 
#include "../include/TADcoups.h"
#include "../include/TADplateau.h"

/* Partie Privee */

CPS_Coups obtenirCoupsPossibles(PLT_Plateau unPlateau, CLR_Couleur joueurRef) {
    CPS_Coups resultat;
    int i,j;
    CP_Coup coupTemp;

    resultat = CP_coups();
    for(i=1; i<=HAUTEUR_PLATEAU; i++){
        for(j=1; j <=LARGEUR_PLATEAU; j++){
            coupTemp = CP_coup(PN_pion(joueurRef),POS_position(j,i));
            if(coupLegal(unPlateau,coupTemp)){
                CPS_ajouterCoups(resultat,coupTemp);
            }
        }
    }
    return resultat;
}

int scoreDUnCoup(PLT_Plateau unPlateau, CLR_Couleur joueurRef, CLR_Couleur joueurCourant, CP_Coup unCoup, int profondeur, int alpha, int beta) {
    jouer(unPlateau,unCoup);
    if(plateauTotalementRempl(unPlateau) || plateauBloque(unPlateau) || (profondeur == 0)) {
        return evaluer(unPlateau,joueurRef);
    } else {
        if(!(plateauBloquePourUneCouleur(unPlateau,CLR_changerCouleur(joueurCourant)))) {
            joueurCourant = CLR_changerCouleur(joueurCourant);
        }

        return alphaBeta(unPlateau,joueurRef,joueurCourant,profondeur-1,apha,beta);
    }
}

int alphaBeta(PLT_Plateau unPlateau, CLR_Couleur joueurRef, CLR_Couleur joueurCourant, int profondeur, int alpha, int beta) {
    CPS_Coups coupsPossibles;
    int resultat, score, i;

    coupsPossibles = obtenirCoupsPossibles(unPlateau,joueurCourant);
    resultat = scoreDUnCoup(unPlateau,joueurRef,joueurCourant,CPS_iemeCoup(coupsPossibles,1),profondeur,alpha,beta);
    for(i=2; i<=CPS_nbCoups(coupsPossibles); i++) {
        score = scoreDUnCoup(unPlateau,joueurRef,joueurCourant,CPS_iemeCoup(coupsPossibles,i),profondeur,alpha,beta);
        if(joueurRef == joueurCourant) {
            resultat = max(resultat,score);
            if(resultat<=alpha) {
                return resultat;
            }
            beta = min(beta,resultat);
        } else {
            resultat = min(resultat,score);
            if(beta<=resultat) {
                return resultat;
            }
            alpha = max(alpha,resultat);
        }
    }
    return resultat;
}

/* Partie publique */