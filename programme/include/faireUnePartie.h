/**
2 * \file faireUneParite.h
3 * \brief Implantation du faireUneParite
4 * \author C. Yang
5 * \version 1.0
6 * \date 06/12/2022
7 *
8 */
#ifndef __FAIREUNEPARITE__
#define __FAIREUNEPARITE__

#include <stdio.h>
#include "TADcouleur.h"
#include "TADcoup.h"
#include "TADcoups.h"
#include "TADpion.h"
#include "TADplateau.h"
#include "TADposition.h"

#define PROFONDEUR 3

/**
 * \typedef EtatPartie
 * \brief il y a deux conditions: Egalisation et Agagnant
 */
typedef enum{partieGagnee, partieEnCours, partieEgal} EtatPartie;


/**
* \fn faireUnePartie(obtenirCoupEnFctDuJoueur (*obtenirCoupBlanc)(PLT_Plateau plateau),
 obtenirCoupEnFctDuJoueur (*obtenirCoupBlanc)(PLT_Plateau plateau), affichagePlateau (*afficher)
 (PLT_Plateau), EtatPartie (*etatPartie)(PLT_Plateau plateau), CLR_Couleur couleur)
 
* \brief Procédure permettant de faire une partie du jeu d'Othello
* \param obtenirCoupEnFctDuJoueur
* \param obtenirCoupEnFctDuJoueur
* \param affichagePlateau
* \param EtatPartie
* \param CLR_Couleur
*/
void faireUnePartie(CP_Coup (*obtenirCoupBlanc)(PLT_Plateau plateau, CLR_Couleur couleur, int
 profondeur), CP_Coup (*obtenirCoupNoir)(PLT_Plateau plateau, CLR_Couleur couleur, int profondeur),
  void (*sortie)(PLT_Plateau plateau,CP_Coup coup, int possibilite), EtatPartie *etat, CLR_Couleur
   *couleurGagnant);


/**
* \fn int coupLegal(PLT_Plateau plateau, CP_Coup coup)
* \brief Cette fonction détermine si un Coup est légal ou non
* \param PLT_Plateau
* \param CP_Coup
* \return bool
*/
int coupLegal(PLT_Plateau plateau, CP_Coup coup);


/**
* \fn CPS_Coups adversairesAdjacents(PLT_Plateau plateau, CP_Coup coup)
* \brief Trouve les pions (les stocke dans une liste de Coups) dans le carré autour du pion (Coup)
 joué. Adapte le carré lorsque le pion est  aux bords du plateau.
* \param PLT_Plateau
* \param CP_Coup
* \return CPS_Coups
*/
CPS_Coups adversairesAdjacents(PLT_Plateau plateau, CP_Coup coup);



/**
* \fn CPS_Coups pionMemeCouleur(PLT_Plateau plateau, CP_Coup coup, CPS_Coups coups)
* \brief Parcourt les directions horizontale, verticale et diagonale
 au pion (Coup) joué et renvoie le premier pion de la même couleur dans chaque
  direction (en les stockant dans la liste de Coups).
* \param PLT_Plateau
* \param CP_Coup
* \param CPS_Coups
* \return CPS_Coups
*/
CPS_Coups pionMemeCouleur(PLT_Plateau plateau, CP_Coup coup, CPS_Coups coups);


/**
* \fn jouer(PLT_Plateau *plateau, CP_Coup)
* \brief Joue un coup sur le plateau.
* \param PLT_Plateau
* \param CP_Coup
*/
void jouer(PLT_Plateau *plateau, CP_Coup);


/**
* \fn retournerPionsEmprisonnes(PLT_Plateau *plateau, CP_Coup coup)
* \brief Retourne les pions d'une couleur emprisonnés par deux autres pions de la couleur adverse.
* \param PLT_Plateau
* \param CP_Coup
*/
void retournerPionsEmprisonnes(PLT_Plateau *plateau, CP_Coup coup);


/**
* \fn etatPartie(PLT_Plateau plateau, CLR_Couleur *couleur, EtatPartie *egalite)
* \brief Permet de définir l'état de la partie (EtatPartie) et la
 couleur gagnante si il y en a une.
* \param PLT_Plateau
* \param CLR_Couleur
* \param EtatPartie
*/
void etatPartie(PLT_Plateau plateau, CLR_Couleur *couleur, EtatPartie *etat);

/**
* \fn PLT_Plateau initialiserPlateau(void)
* \brief initialise un plateau d'Othello avec les 4 pions du début au centre du plateau.
* \return PLT_Plateau
*/
PLT_Plateau initialiserPlateau(void);


/**
* \fn int evaluerNb(PLT_Plateau plateau, CLR_Couleur couleur)
* \brief Compte le nombre de pions pour une couleur (un joueur)
* \param PLT_Plateau
* \param CLR_Couleur
* \return int
*/

int evaluerNb(PLT_Plateau plateau, CLR_Couleur couleur);

/**
* \fn CP_Coup coupEnFctJoueur(CP_Coup (*obtenirCoupBlanc)(PLT_Plateau plateau,
 Joueur joueur, CLR_Couleur couleur), CP_Coup (*obtenirCoupNoir)(PLT_Plateau plateau,
  Joueur joueur, CLR_Couleur couleur), CLR_Couleur couleur, PLT_Plateau plateau,
   Joueur joueur1, Joueur joueur2)
* \brief Retourne le coup de "obtenirCoupEnFctDuJoueur" en fonction de la couleur donnée en entrée.
* \param obtenirCoupEnFctDuJoueur
* \param obtenirCoupEnFctDuJoueur
* \param CLR_Couleur
* \param PLT_Plateau
* \param Joueur
* \param Joueur
* \return CP_Coup
*/

CP_Coup coupEnFctJoueur(CP_Coup (*obtenirCoupBlanc)(PLT_Plateau plateau, CLR_Couleur couleur, int
 profondeur), CP_Coup (*obtenirCoupNoir)(PLT_Plateau plateau,
  CLR_Couleur couleur, int profondeur), CLR_Couleur couleur, PLT_Plateau plateau);
#endif

