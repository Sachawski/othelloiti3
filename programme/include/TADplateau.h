/**
 * \file TADplateau.h
 * \brief Implementation du TAD Plateau
 * \author S. Wojciechowski
 * \version 1.0
 * \date 04/12/2022
*/

#ifndef  __TADPLATEAU__
#define __TADPLATEAU__

#define HAUTEUR_PLATEAU 8
#define LARGEUR_PLATEAU 8
#define INF_NEGATIF -1024
#define INF_POSITIF 1024
#include "TADposition.h"
#include "TADpion.h"

/**
 * \struct C_Case
 * \brief Modélise une case du plateau de jeu
 * C_Case est un type qui définit une case de jeu, utilisée dans PLT_Plateau
*/
typedef struct {
    int estVide ; /**< Booleen qui indique si la case est vide*/
    PN_Pion casePion ; /**< Pion qui serait présent sur la case*/
} C_Case ;

/**
 * \struct PLT_Plateau
 * \brief Modélise un plateau de jeu
 * PLT_Plateau modélise un plateau de jeu par un tableau de C_Case,
  de taille LARGEUR_PLATEAU x HAUTEUR_PLATEAU
 */
typedef struct {
    C_Case tabPlateau[LARGEUR_PLATEAU][HAUTEUR_PLATEAU] ; 
    /**< Tableau de C_Case représentant le plateau */
} PLT_Plateau ;

/**
* \fn PLT_Plateau PLT_plateau()
* \brief Fonction qui crée un plateau vide de largeur LARGEUR_PLATEAU et hauteur HAUTEUR_PLATEAU
* \return PLT_Plateau (Plateau vide)
*/
PLT_Plateau PLT_plateau();

/**
* \fn void PLT_poserPion(PLT_Plateau* plateau, POS_Position pos, PN_Pion pion)
* \brief Procédure qui pose un pion sur le plateau à partir d'un pion et d'une position
* \param plateau Plateau sur lequel on veut poser le pion
* \param pos Position du coup
* \param pion Pion à poser
* \return void
*/
void PLT_poserPion(PLT_Plateau* plateau, POS_Position pos, PN_Pion pion);

/**
* \fn PN_Pion PLT_obtenirPion(PLT_Plateau plateau, POS_Position pos)
* \brief Fonction qui permet d'obtenir le pion placée à une position
* \param plateau Plateau de jeu
* \param pos Position du pion voulu
* \return PN_Pion (Pion présent à la position donnée)
*/
PN_Pion PLT_obtenirPion(PLT_Plateau plateau, POS_Position pos);

/**
* \fn int PLT_estCaseVide(PLT_Plateau plateau , POS_Position pos);
* \brief Fonction qui permet de savoir si une case
 est vide en retournant un booleen (ici un entier)
* \param plateau Plateau de jeu
* \param position Position de la case voulu
* \return bool (1 si la case est vide, 0 sinon)
*/
int PLT_estCaseVide(PLT_Plateau plateau , POS_Position pos);

/**
* \fn void PLT_retournerPion(PLT_Plateau* plateau, POS_Position pos)
* \brief Procédure qui modifie un plateau pour retourner un pion
* \param plateau Plateau de jeu
* \param position Position du pion à retourner
* \return void
*/
void PLT_retournerPion(PLT_Plateau* plateau, POS_Position pos);

/**
* \fn void PLT_enleverPion(PLT_Plateau* plateau, POS_Position pos)
* \brief Procédure qui modifie un plateau en vidant une case
* \param plateau Plateau de jeu
* \param position Position du pion à retourner
* \return void
*/
void PLT_enleverPion(PLT_Plateau* plateau, POS_Position pos);

#endif
