/**
2 * \file faireUneParite.h
3 * \brief Implantation du faireUneParite
4 * \author C. Yang
5 * \version 1.0
6 * \date 06/12/2022
7 *
8 */
#ifndef __FAIREUNEPARITE__
#define __FAIREUNEPARTIE__
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
typedef void (*affichagePlateau)(PLT_Plateau plateau);
/*affichagePlateau afficherPlateau;*/

/**
*
* \typedef  CP_Coup (*obtenirCoupEnFctDuJoueur)(PLT_Plateau plateau)
* \brief obtenir le coup choisi de joueur
*/
typedef CP_Coup (*obtenirCoupEnFctDuJoueur)(PLT_Plateau plateau);

/*obtenirCoupEnFctDuJoueur obtenirCoupBlanc;*/
/*obtenirCoupEnFctDuJoueur obtenirCoupNoir;*/

/**
 * \typedef EtatPartie
 * \brief il y a deux conditions: Egalisation et Agagnant
 */
typedef enum{Egalisation, gagnant} EtatPartie;/* pas sûr */


/**
* \fn faireUnePartie(obtenirCoupEnFctDuJoueur (*obtenirCoupBlanc)(PLT_Plateau plateau), obtenirCoupEnFctDuJoueur (*obtenirCoupBlanc)(PLT_Plateau plateau), affichagePlateau (*afficher)(PLT_Plateau), EtatPartie (*etatPartie)(PLT_Plateau plateau), CLR_Couleur couleur)
* \brief 
* \param obtenirCoupEnFctDuJoueur 
* \param obtenirCoupEnFctDuJoueur
* \param affichagePlateau
* \param EtatPartie
* \param CLR_Couleur
*/
void faireUnePartie(obtenirCoupEnFctDuJoueur (*obtenirCoupBlanc)(PLT_Plateau plateau), obtenirCoupEnFctDuJoueur (*obtenirCoupNoir)(PLT_Plateau plateau), affichagePlateau (*afficher)(PLT_Plateau plateau), EtatPartie *egalite, CLR_Couleur couleur);


/**
* \fn int coupLegal(PLT_Plateau plateau, CP_Coup coup)
* \brief détermination de la légalité
* \param PLT_Plateau
* \param CP_Coup
* \return bool
*/
int coupLegal(PLT_Plateau plateau, CP_Coup coup);


/**
* \fn CPS_Coups adversairesAdjacents(PLT_Plateau plateau, CP_Coup coup)
* \brief trouver les coups de différentes couleurs autour de la position
* \param PLT_Plateau
* \param CP_Coup
* \return CPS_Coups
*/
CPS_Coups adversairesAdjacents(PLT_Plateau plateau, CP_Coup coup);



/**
* \fn CPS_Coups pionMemeCouleur(PLT_Plateau plateau, CP_Coup coup, CPS_Coups coups)
* \brief trouver des coups de la même couleur dans des directions différentes
* \param PLT_Plateau
* \param CP_Coup
* \param CPS_Coups
* \return CPS_Coups
*/
CPS_Coups pionMemeCouleur(PLT_Plateau plateau, CP_Coup coup, CPS_Coups coups);


/**
* \fn jouer(PLT_Plateau *plateau, CP_Coup)
* \brief mettre un coup
* \param PLT_Plateau
* \param CP_Coup
*/
void jouer(PLT_Plateau *plateau, CP_Coup);


/**
* \fn retournerPionsEmprisonnes(PLT_Plateau plateau, CP_Coup coup)
* \brief 
* \param PLT_Plateau
* \param CP_Coup
*/
void retournerPionsEmprisonnes(PLT_Plateau plateau, CP_Coup coup);


/**
* \fn etatPartie(PLT_Plateau plateau, CLR_Couleur *couleur, EtatPartie *egalite)
* \brief 
* \param PLT_Plateau
* \param CLR_Couleur
* \param EtatPartie
*/
void etatPartie(PLT_Plateau plateau, CLR_Couleur *couleur, EtatPartie *egalite); 


/**
* \fn int plateauTotalementRempli(PLT_Plateau plateau)
* \brief 
* \param PLT_Plateau
* \return bool
*/
int plateauTotalementRempli(PLT_Plateau plateau);


/**
* \fn int plateauBloque(PLT_Plateau plateau)
* \brief 
* \param PLT_Plateau
* \return bool
*/
int plateauBloque(PLT_Plateau plateau);


/**
* \fn int evaluer(PLT_Plateau plateau, CLR_Couleur couleur)
* \brief 
* \param PLT_Plateau
* \param CLR_Couleur
* \return int
*/
int evaluer(PLT_Plateau plateau, CLR_Couleur couleur);


/**
* \fn PLT_Plateau initialiserPlateau(void)
* \brief 
* \return PLT_Plateau
*/
PLT_Plateau initialiserPlateau(void);

void afficherPlateau(PLT_Plateau plateau);
#endif