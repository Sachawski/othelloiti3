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
#include "definitionTypes.h"
#include "TADcouleur.h"
typedef struct
{
    /* Modélisation d'un pion par un caractéristique :
        - couleur de pion
    */
  CLR_Couleur couleur;
} PN_Pion;

/**
* \fn PN_Pion creerPion(CLR_couleur couleur)
* \brief Création d’un Pion à partir d'un couleur
* \param CLR_Couleur 
* \return PN_Pion
*/
PN_Pion PN_pion(CLR_Couleur);

/**
* \fn CLR_Couleur obtenirCouleurSuperieure(PN_Pion pion)
* \brief obtenir le couleur de cette pion
* \param PN_Pion
* \return CLR_Couleur
*/
CLR_Couleur obtenirCouleurSuperieure(PN_Pion);

/**
* \procedure retournerPion(PN_Pion *pion)
* \brief retourner un pion
* \param PN_Pion
*/
void retournerPion(PN_Pion *);
#endif