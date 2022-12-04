/**
2 * \file obtenirCoup.h
3 * \brief Implantation de la fonction obtenirCoup
4 * \author V. Turnel
5 * \version 1.0
6 * \date 04/12/2022
7 *
8 */

#ifndef __OBTENIR_COUP__
#define __OBTENIR_COUP__
#include "TADcouleur.h"
#include "TADplateau.h"


/**
* \fn CP_Coup obtenirCoup(PLT_Plateau unPlateau, CLR_Couleur joueur, int profondeur)
* \brief Obtention d'un coup par l'IA
* \param unPlateau représente le plateau de jeu
* \param joueur représente la couleur pour laquelle l'IA doit chercher le meilleur coup
* \param profondeur représente le nombre d'étape que l'IA doit anticiper pour chercher le meilleur coup
* \return CP_Coup
*/
CP_Coup obtenirCoup(PLT_Plateau unPlateau, CLR_Couleur joueur, int profondeur);

#endif