/**
 * \file TADpion.h
 * \brief Implementation du TAD Pion
 * \author C. Yang
 * \version 1.0
 * \date 03/12/2022
*/

#ifndef  __TADPION__
#define  __TADPION__

#include "TADcouleur.h"

/**
 * \struct PN_Pion
 * \brief Modélise un pion 
 * PN_Pion est un type qui modélise ce qu'est un pion à jouer
*/
typedef struct {
    CLR_Couleur couleur ; /**< Couleur du pion */
} PN_Pion ;
    
/**
* \fn PN_Pion PN_pion(CLR_couleur couleur)
* \brief Fonction qui crée un pion à partir d'une couleur
* \param couleur Couleur du pion à créer 
* \return PN_Pion 
*/
PN_Pion PN_pion(CLR_Couleur couleur);

/**
* \fn CLR_Couleur PN_obtenirCouleurSuperieure(PN_Pion)
* \brief fonction qui peremt d'obtenir la couleur du'un pion
* \param pion Pion dont on veut la couleur
* \return CLR_Couleur (Couleur du pion donné)
*/
CLR_Couleur PN_obtenirCouleurSuperieure(PN_Pion pion);

/**
* \fn void PN_retournerPion(PN_Pion *pion)
* \brief Procédure qui permet de retourner un pion
* \param pion Pion à retourner
* \return void 
*/
void PN_retournerPion(PN_Pion *pion);

#endif