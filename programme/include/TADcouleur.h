/**
2 * \file TADcouleur.h
3 * \brief Implantation du TAD Couleur
4 * \author P. Thulliez
5 * \version 1.0
6 * \date 06/12/2022
7 *
8 */

#ifndef  __TADCOULEUR__
#define __TADCOULEUR__
#include "definitionTypes.h"


 /* Modélisation de la couleur Noir
    */
CLR_Couleur noir();

 /* Modélisation de la couleur Blanc
    */
CLR_Couleur blanc();

 /* fonction permettant de savoir si la couleur est Blanc.
    Retourne Vrai (1) si la couleur est Blanc et Faux (0) si la couleur est Noir
    */
int estBlanc(CLR_Couleur c);

 /* fonction qui change la couleur d'une couleur donnée
    Si la couleur donnée est Blanc, la fonction changerCouleur retourne Noir
    Si la couleur donnée est Noir, la fonction changerCouleur retourne Blanc
    */

CLR_Couleur changerCouleur(CLR_Couleur c1);

#endif
