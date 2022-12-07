/**
2 * \file TADplateau.h
3 * \brief Implantation du TAD Plateau
4 * \author S. Wojciechowski
5 * \version 1.0
6 * \date 04/12/2022
7 *
8 */

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
 *
 * Une case du plateau de jeu est modélisée par deux caractéristiques : 
 * - le fait qu'elle soit vide ou non
 * - la couleur qui y est présente
 *
 * \var PN_Pion C_Case::casePion
 * \brief Pion présent sur la case
 *
 * \var int C_Case::estVide
 * \brief Indique si la case est vide ou non
 */

/**
 * \typedef PLT_Plateau
 * \brief Plateau de jeu
 *
 * Plateau de jeu modélisé par un tableau de C_Case de taille LARGEUR_PLATEAU x HAUTEUR_PLATEAU
 */

typedef struct 
    {
        /* Modélisation d'une case par ses deux caractéristiques :
        - le fait qu'elle soit vide ou non
        - la couleur qui y serait présente
        */

        int estVide ;
        PN_Pion casePion ;
    } C_Case ;

<<<<<<< HEAD
=======
/*typedef C_Case PLT_Plateau[LARGEUR_PLATEAU][HAUTEUR_PLATEAU] ;*/

typedef struct{
  C_Case plateau[LARGEUR_PLATEAU][HAUTEUR_PLATEAU] ;
}PLT_Plateau;

>>>>>>> 1e6169fbd1a9cfccf0aea035150f50761552ceae

typedef struct 
    {
        C_Case tabPlateau[LARGEUR_PLATEAU][HAUTEUR_PLATEAU] ;
    } PLT_Plateau ;
/**
* \fn PLT_Plateau PLT_plateau()
* \brief Création d’un Plateau vide de largeur LARGEUR_PLATEAU et hauteur HAUTEUR_PLATEAU
* \return PLT_Plateau
*/

PLT_Plateau PLT_plateau();

/**
* \fn PLT_poserPion(PLT_Plateau* plateau, POS_Position pos, PN_Pion pion)
* \brief Création d’un Coup à partir d'un pion et d'une position
* \param plateau plateau sur lequel on veut poser le pion
* \param position emplacement du coup
* \param pion pion à poser
* \return void
*/

void PLT_poserPion(PLT_Plateau* plateau, POS_Position pos, PN_Pion pion);

/**
* \fn PN_Pion PLT_obtenirPion(PLT_Plateau plateau, POS_Position pos)
* \brief Permet d'obtenir le pion d'une position
* \param plateau plateau de jeu
* \param position emplacement du pion voulu
* \return PN_Pion
*/

PN_Pion PLT_obtenirPion(PLT_Plateau plateau, POS_Position pos);

/**
* \fn bool PLT_estCaseVide(PLT_Plateau plateau , POS_Position pos);
* \brief Permet de savoir si une case est vide
* \param plateau plateau de jeu
* \param position emplacement de la case voulu
* \return bool
*/

int PLT_estCaseVide(PLT_Plateau plateau , POS_Position pos);
/**
* \fn void PLT_retournerPion(PLT_Plateau* plateau, POS_Position pos)
* \brief Modifie un plateau pour retourner un pion
* \param plateau plateau de jeu
* \param position emplacement du pion voulu
* \return void
*/

void PLT_retournerPion(PLT_Plateau* plateau, POS_Position pos);
/**
* \fn void PLT_enleverPion(PLT_Plateau* plateau, POS_Position pos)
* \brief Modifie un plateau en vidant une case
* \param plateau plateau de jeu
* \param position emplacement du pion voulu
* \return void
*/
void PLT_enleverPion(PLT_Plateau* plateau, POS_Position pos);
#endif