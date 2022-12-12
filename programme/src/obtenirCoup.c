/** \file
 * \brief Fichier contenant la fonction compteurCouleur()
 * \author S. Wojciechowski, V. Turnel
 * \version 1.0
 * \date 05/12/2022     
 */

#include "obtenirCoupSacha.h"
#include "faireUnePartie.h"
#include "faireUnePartiePrive.h"
#include "TADposition.h" 
#include "TADplateau.h"
#include "TADcoups.h" 
#include "TADcoup.h"
#include <stdlib.h>
#include <stdio.h>

/* Partie Privee */

#define MIN(i, j) (((i) < (j)) ? (i) : (j))
#define MAX(i, j) (((i) > (j)) ? (i) : (j))


void copierPlateau(PlT_Plateau plateau_src, PlT_Plateau *plateau_dst) {
  for (int i = 0; i < LARGEUR_PLATEAU; i++) {
    for (int j = 0; i < HAUTEUR_PLATEAU; j++) {
        *plateau_dst[j][i] = plateau_src[j][i];
    }
  }
}

/** 
 * \brief Fonction qui compte le nombre de pions d'une couleur donnée sur un plateau
 * \param plateau Plateau sur lequel le comptage s'effectue
 * \param couleur Couleur dont le comptage est effectué
 * \return Nombre de pions de la couleur donnée
 */
int compteurCouleur(PLT_Plateau plateau, CLR_Couleur couleur)
{
    int compteur,i,j;
    POS_Position pos ;
    compteur = 0 ;
    for (i=1;i<=8;i++) 
    {
        for (j=1;i<=8;j++) 
        {
            pos = POS_position(i,j);
            if (!PLT_estCaseVide(plateau,pos) && (PN_obtenirCouleurSuperieure(PLT_obtenirPion(plateau,pos)) == couleur))
            {
                compteur = compteur + 1 ;
            }
        }
    }
    return compteur ;
}

/**
 * \brief  Evaluer la situation d'une couleur sur un plateau de jeu
 * \param  plateau   Le plateau à évaluer
 * \param  joueur   La couleur du joueur à évaluer
 * \return L'évaluation du plateau pour le joueur spécifié
 * 
 * Cette fonction evalue la situation pour un joueur spécifié. Il prend en compte 
 * le score joueur, ainsi que celui de son adversaire. 
 */
int evaluer(PLT_Plateau plateau, CLR_Couleur joueur)
{
    return score(plateau,couleur)-score(plateau,CLR_changerCouleur(couleur)) ;
}

/**
 * \brief  Evaluer le score d'un plateau de jeu
 * \param  plateau   Le plateau à évaluer
 * \param  joueur   La couleur du joueur à évaluer
 * \return Le score du plateau pour le joueur spécifié
 * 
 * Cette fonction evalue le score d'un plateau de jeu pour un joueur 
 * spécifié. Il prend en compte le nombre de pions du joueur, ainsi que 
 * leur position par rapport à la grille de pondération. 
 */
int score(PLT_Plateau plateau, CLR_Couleur joueur)
{
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
    };
        for (i=1;i<=8;i++) 
        {
            for (j=1;i<=8;j++) 
            {
                tempPos = POS_position(i,j) ;
                if ((!PLT_estCaseVide(plateau,tempPos)) && (PN_obtenirCouleurSuperieure(PLT_obtenirPion(plateau,tempPos)) == joueur ))
                {
                    sommePonderation = sommePonderation + ponderation[i][j];
                }

            }
        }
    score = compteurCouleur(plateau,joueur) + sommePonderation ;
    return score ;
}


/**
 * \brief Fonction qui obtient les coups possibles pour un joueur
 * \param unPlateau Le plateau de jeu
 * \param joueurRef La couleur du joueur
 * \return Les coups possibles
 */
CPS_Coups obtenirCoupsPossibles(PLT_Plateau unPlateau, CLR_Couleur joueurRef) {
    CPS_Coups resultat;
    int i,j;
    CP_Coup coupTemp;

    resultat = CPS_coups();
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

/**
 * \brief Vérifie si le plateau est bloqué
 * Cette fonction prend en paramètre un plateau et vérifie si celui-ci
 * est totalement bloqué. Pour cela elle vérifie si les coups possibles des
 * couleurs noir et blanc sont égaux à 0.
 * \param plateau Plateau à vérifier
 * \return True si le plateau est bloqué, False sinon
 */
int  plateauBloque(PLT_Plateau plateau)
{
    CPS_Coups lesCoupsNoirs,lesCoupsBlancs;
    lesCoupsNoirs = obtenirCoupsPossibles(plateau,CLR_blanc());
    lesCoupsBlancs = obtenirCoupsPossibles(plateau,CLR_noir());
    if  (( lesCoupsNoirs.nbTotalCoups == 0 ) && ( lesCoupsBlancs.nbTotalCoups == 0 ))
    {
        return 1;
    } else {
        return 0  ;
    }
}

/**
 * \brief Vérifie si le plateau est bloqué pour une couleur
 * \param plateau Le plateau à vérifier
 * \param couleur La couleur à vérifier
 * \return 1 si le plateau est bloqué pour la couleur, 0 sinon
 */
int plateauBloquePourUneCouleur(PLT_Plateau plateau, CLR_Couleur couleur)
{
    CPS_Coups cps ;
    cps = obtenirCoupsPossibles(plateau,couleur);
    return ( cps.nbTotalCoups == 0 );
}


/**
 * \brief Fonction qui calcule le score d'un coup d'un joueur
 * \param unPlateau Plateau du jeu
 * \param joueurRef Joueur référence
 * \param joueurCourant Joueur courant
 * \param unCoup Coup du joueur courant
 * \param profondeur Profondeur de l'arbre de recherche
 * \param alpha Alpha-beta pruning
 * \param beta Alpha-beta pruning
 * \return Score d'un coup
 */
int scoreDUnCoup(PLT_Plateau unPlateau, CLR_Couleur joueurRef, CLR_Couleur joueurCourant, CP_Coup unCoup, int profondeur, int alpha, int beta) {
    PLT_Plateau copieUnPlateau;

    copierPlateau(unPlateau,copieUnPlateau)
    jouer(&copieUnPlateau,unCoup);
    if(plateauTotalementRempli(copieUnPlateau) || plateauBloque(copieUnPlateau) || (profondeur == 0)) {
        return evaluer(copieUnPlateau,joueurRef);
    } else {
        if(!(plateauBloquePourUneCouleur(copieUnPlateau,CLR_changerCouleur(joueurCourant)))) {
            joueurCourant = CLR_changerCouleur(joueurCourant);
        }

        return alphaBeta(copieUnPlateau,joueurRef,joueurCourant,profondeur-1,alpha,beta);
    }
}

/**
 * \brief Calcul du meilleur coup à jouer en utilisant l'algorithme Alpha-Beta.
 *
 * Cette fonction calcule le meilleur coup à jouer pour le joueur donné à l'aide de l'algorithme Alpha-Beta. 
 *
 * \param unPlateau Le plateau sur lequel le calcul est effectué.
 * \param joueurRef Le joueur pour lequel on calcule le meilleur coup.
 * \param joueurCourant Le joueur qui doit jouer le prochain coup.
 * \param profondeur La profondeur de recherche de l'algorithme.
 * \param alpha La valeur minimale que peut prendre le résultat.
 * \param beta La valeur maximale que peut prendre le résultat.
 *
 * \return Le score du meilleur coup à jouer pour le joueur donné.
 */
int alphaBeta(PLT_Plateau unPlateau, CLR_Couleur joueurRef, CLR_Couleur joueurCourant, int profondeur, int alpha, int beta) {
    CPS_Coups coupsPossibles;
    int resultat, score, i;

    coupsPossibles = obtenirCoupsPossibles(unPlateau,joueurCourant);
    resultat = scoreDUnCoup(unPlateau,joueurRef,joueurCourant,CPS_iemeCoup(coupsPossibles,1),profondeur,alpha,beta);
    for(i=2; i<=CPS_nbCoups(coupsPossibles); i++) {
        score = scoreDUnCoup(unPlateau,joueurRef,joueurCourant,CPS_iemeCoup(coupsPossibles,i),profondeur,alpha,beta);
        if(joueurRef == joueurCourant) {
            resultat = MAX(resultat,score);
            if(resultat<=alpha) {
                return resultat;
            }
            beta = MIN(beta,resultat);
        } else {
            resultat = MAX(resultat,score);
            if(beta<=resultat) {
                return resultat;
            }
            alpha = MAX(alpha,resultat);
        }
    }
    return resultat;
}

/* Partie publique */

/**
 * \brief Obtenir le meilleur coup possible pour un joueur donné
 * \param plateau Le plateau sur lequel le joueur joue
 * \param joueur Le joueur pour lequel on cherche le meilleur coup
 * \param profondeur La profondeur de recherche de l'algorithme
 * \return Le meilleur coup possible pour le joueur
 */
CP_Coup obtenirCoup(PLT_Plateau plateau, CLR_Couleur joueur, int profondeur)
{
    CP_Coup resultat ;
    CPS_Coups cps ;
    int score, meilleurScore, i ;

    cps = obtenirCoupsPossibles(plateau,joueur);
    resultat = CPS_iemeCoup(cps,1) ;
    meilleurScore = scoreDUnCoup(plateau,joueur,joueur,resultat,profondeur,INF_NEGATIF,INF_POSITIF) ;
    for (i=2; i<cps.nbTotalCoups;i++)
    {
        score = scoreDUnCoup(plateau,joueur,joueur,CPS_iemeCoup(cps,i),profondeur,INF_NEGATIF,INF_POSITIF) ;
        if ( score > meilleurScore ) 
        {
            resultat = CPS_iemeCoup(cps,i);
            meilleurScore = score ; 
        }
    }
    return resultat ;
}