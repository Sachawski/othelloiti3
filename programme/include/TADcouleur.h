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


/* Modélisation d'une couleur qui est soit noir, soit blanche
    */
typedef enum {BLANC,NOIR} CLR_Couleur ;



 /* Modélisation de la couleur NOIR
    */
CLR_Couleur CLR_noir();

 /* Modélisation de la couleur BLANC
    */
CLR_Couleur CLR_blanc();

 /* fonction permettant de savoir si la couleur est BLANC.
    Retourne Vrai (1) si la couleur est BLANC et Faux (0) si la couleur est NOIR
    */
int CLR_estBlanc(CLR_Couleur c);

 /* fonction qui change la couleur d'une couleur donnée
    Si la couleur donnée est BLANC, la fonction changerCouleur retourne NOIR
    Si la couleur donnée est NOIR, la fonction changerCouleur retourne BLANC
    */

CLR_Couleur CLR_changerCouleur(CLR_Couleur c1);

#endif
