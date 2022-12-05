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

bool PLT_estCaseVide(PLT_Plateau plateau , POS_Position pos);
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