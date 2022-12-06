/**
2 * \file faireUneParite.h
3 * \brief Implantation du faireUneParite
4 * \author C. Yang
5 * \version 1.0
6 * \date 06/12/2022
7 *
8 */


#include "TADcouleur.h"
#include "TADcoup.h"
#include "TADcoups.h"
#include "TADpion.h"
#include "TADplateau.h"
#include "TADposition.h"

/**
 * \typedef affichagePlateau
 * \brief affichier le plateau
 */
typedef void affichagePlateau(PLT_Plateau);


/**
* \fn CP_Coup obtenirCoupEnFctDuJoueur(PLT_Plateau plateau)
* \brief obtenir le coup choisi de joueur
* \param PLT_Plateau
* \return CP_Coup
*/
CP_Coup obtenirCoupEnFctDuJoueur(PLT_Plateau plateau);

/**
 * \typedef EtatPartie
 * \brief il y a deux conditions: Egalisation et Agagnant
 */
typedef enum{Egalisation, Agagnant} etatPartie;/* pas sûr */

/**
* \fn faireUnePartie(obtenirCoupEnFctDuJoueur, obtenirCoupEnFctDuJoueur, affichagePlateau, EtatPartie, CLR_Couleur)
* \brief 
* \param obtenirCoupEnFctDuJoueur, obtenirCoupEnFctDuJoueur, 
* \param obtenirCoupEnFctDuJoueur
* \param affichagePlateau
* \param EtatPartie
* \param CLR_Couleur
*/

void faireUnePartie(obtenirCoupEnFctDuJoueur, obtenirCoupEnFctDuJoueur, affichagePlateau, etatPartie, CLR_Couleur);
/*
pas encore fini, elle manque la type de obtenirCoup EtatPartie
*/