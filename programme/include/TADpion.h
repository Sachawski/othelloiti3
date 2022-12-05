/**
2 * \file TADpion.h
3 * \brief Implantation du TAD Pion
4 * \author C. Yang
5 * \version 1.0
6 * \date 03/12/2022
7 *
8 */

#ifndef  __TADPION__
#define __TADPION__
#include "TADcouleur.h"
typedef struct
{
    /* Modélisation d'un pion par un caractéristique :
        - couleur de pion
    */
  CLR_Couleur couleur;
} PN_Pion;

/**
* \fn PN_Pion PN_pion(CLR_couleur couleur)
* \brief Création d’un Pion à partir d'une couleur
* \param CLR_Couleur 
* \return PN_Pion
*/
PN_Pion PN_pion(CLR_Couleur couleur);

/**
* \fn CLR_Couleur PN_obtenirCouleurSuperieure(PN_Pion)
* \brief obtenir la couleur de ce pion
* \param PN_Pion
* \return CLR_Couleur
*/
CLR_Couleur PN_obtenirCouleurSuperieure(PN_Pion pion);

/**
* \fn PN_retournerPion(PN_Pion *pion)
* \brief retourner un pion
* \param PN_Pion
*/
void PN_retournerPion(PN_Pion *pion);
#endif