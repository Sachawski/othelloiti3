/**
2 * \file obtenirCoup.h
3 * \brief Implantation des fonctions privées de obtenirCoup
4 * \author V. Turnel
5 * \version 1.0
6 * \date 12/12/2022
7 *
8 */

#ifndef __OBTENIR_COUP_PRIVE__
#define __OBTENIR_COUP_PRIVE__

#include "TADposition.h" 
#include "TADplateau.h"
#include "TADcoups.h" 
#include "TADcoup.h"

/**
* \fn void copierPlateau(PlT_Plateau plateau_src, PlT_Plateau *plateau_dst)
* \brief Permet la copie d'un plateau
* \param plateau_src représente le plateau de jeu source
* \param plateau_dst représente le plateau destination, la copie du plateau source
*/
void copierPlateau(PLT_Plateau plateau_src, PLT_Plateau *plateau_dst);

/**
* \fn int compteurCouleur(PLT_Plateau plateau, CLR_Couleur couleur)
* \brief Compte le nombre de pion d'une couleur, donnée en paramètre, sur le plateau
* \param plateau représente le plateau de jeu
* \param couleur représente la couleur des pions qui doivent être compté
* \return int
*/
int compteurCouleur(PLT_Plateau plateau, CLR_Couleur couleur);

/**
* \fn int compteurCouleur(PLT_Plateau plateau, CLR_Couleur couleur)
* \brief Compte le nombre de pion d'une couleur, donnée en paramètre, sur le plateau
* \param plateau représente le plateau de jeu
* \param couleur représente la couleur des pions qui doivent être compté
* \return int
*/
int evaluer(PLT_Plateau plateau, CLR_Couleur joueur);

int score(PLT_Plateau plateau, CLR_Couleur joueur);

CPS_Coups obtenirCoupsPossibles(PLT_Plateau unPlateau, CLR_Couleur joueurRef);

int  plateauBloque(PLT_Plateau plateau);

int plateauBloquePourUneCouleur(PLT_Plateau plateau, CLR_Couleur couleur);

int alphaBeta(PLT_Plateau unPlateau, CLR_Couleur joueurRef, CLR_Couleur joueurCourant, int profondeur, int alpha, int beta);

int scoreDUnCoup(PLT_Plateau unPlateau, CLR_Couleur joueurRef, CLR_Couleur joueurCourant, CP_Coup unCoup, int profondeur, int alpha, int beta);

#endif