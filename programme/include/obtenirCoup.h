/**
* \file obtenirCoup.h
* \brief Implementation de la fonction obtenirCoup
* \author V. Turnel
* \version 1.0
* \date 04/12/2022
*/

#ifndef __OBTENIR_COUP__
#define __OBTENIR_COUP__
#include "TADcouleur.h"
#include "TADplateau.h"
#include "TADcoup.h"

/**
* \fn CP_Coup obtenirCoup(PLT_Plateau unPlateau, CLR_Couleur joueur, int profondeur)
* \brief Obtention d'un coup par l'IA
* \param unPlateau Plateau de jeu
* \param joueur Couleur pour laquelle l'IA doit chercher le meilleur coup
* \param profondeur Nombre d'étape que l'IA doit anticiper pour chercher le meilleur coup
* \return CP_Coup
*/
CP_Coup obtenirCoup(PLT_Plateau unPlateau, CLR_Couleur joueur, int profondeur);

#endif