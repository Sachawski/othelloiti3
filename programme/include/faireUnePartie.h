/**
2 * \file faireUneParite.h
3 * \brief Implantation du faireUneParite
4 * \author C. Yang
5 * \version 1.0
6 * \date 06/12/2022
7 *
8 */
#ifndef __FAIREUNEPARITE__
#define __FAIREUNEPARITE__
#include "TADcouleur.h"
#include "TADcoup.h"
#include "TADcoups.h"
#include "TADpion.h"
#include "TADplateau.h"
#include "TADposition.h"



typedef enum{IAvsIA=1, IAvsHumain, HumainvsHumain} Mode;

typedef enum{IA=1, Humain} Joueur;

/**
 * \typedef affichagePlateau
 * \brief affichier le plateau
 */
/*typedef void (*affichagePlateau)(PLT_Plateau plateau);*/
/*affichagePlateau afficherPlateau;*/

/**
*
* \typedef  CP_Coup (*obtenirCoupEnFctDuJoueur)(PLT_Plateau plateau)
* \brief obtenir le coup choisi de joueur
*/
/*typedef CP_Coup (*obtenirCoupEnFctDuJoueur)(PLT_Plateau plateau);*/
/*obtenirCoupEnFctDuJoueur obtenirCoupBlanc;*/
/*obtenirCoupEnFctDuJoueur obtenirCoupNoir;*/

/**
 * \typedef EtatPartie
 * \brief il y a deux conditions: Egalisation et Agagnant
 */
typedef enum{partieGagnee, partieNulle, partieEegal} EtatPartie;


/**
* \fn faireUnePartie(obtenirCoupEnFctDuJoueur (*obtenirCoupBlanc)(PLT_Plateau plateau), obtenirCoupEnFctDuJoueur (*obtenirCoupBlanc)(PLT_Plateau plateau), affichagePlateau (*afficher)(PLT_Plateau), EtatPartie (*etatPartie)(PLT_Plateau plateau), CLR_Couleur couleur)
* \brief
* \param obtenirCoupEnFctDuJoueur
* \param obtenirCoupEnFctDuJoueur
* \param affichagePlateau
* \param EtatPartie
* \param CLR_Couleur
*/
void faireUnePartie(CP_Coup (*obtenirCoupBlanc)(PLT_Plateau plateau, Joueur joueur, CLR_Couleur couleur), CP_Coup (*obtenirCoupNoir)(PLT_Plateau plateau, Joueur joueur, CLR_Couleur couleur), void (*afficher)(PLT_Plateau plateau), EtatPartie *egalite, CLR_Couleur couleurGagnant, Mode mode);


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
* \paramplateau
* \param CP_Coup
*/
void jouer(PLT_Plateau *plateau, CP_Coup);


/**
* \fn retournerPionsEmprisonnes(PLT_Plateau plateau, CP_Coup coup)
* \brief
* \paramplateau
* \paramcoup
*/
void retournerPionsEmprisonnes(PLT_Plateau *plateau, CP_Coup coup);


/**
* \fn etatPartie(PLT_Plateau plateau, CLR_Couleur *couleur, EtatPartie *egalite)
* \brief
* \paramplateau
* \paramcouleur
* \paramegaltie
*/
void etatPartie(PLT_Plateau plateau, CLR_Couleur *couleur, EtatPartie *egalite);




/**
* \fn PLT_Plateau initialiserPlateau(void)
* \brief
* \return PLT_Plateau
*/
PLT_Plateau initialiserPlateau(void);

void afficherPlateau(PLT_Plateau plateau);

int evaluerNb(PLT_Plateau plateau, CLR_Couleur couleur);

void menu(Mode *mode);

CP_Coup obtenirCoupEnFctDuJoueur(PLT_Plateau plateau, Joueur joueur, CLR_Couleur couleur);

CP_Coup coupEnFctJoueur(CP_Coup (*obtenirCoupBlanc)(PLT_Plateau plateau, Joueur joueur, CLR_Couleur couleur), CP_Coup (*obtenirCoupNoir)(PLT_Plateau plateau, Joueur joueur, CLR_Couleur couleur), CLR_Couleur couleur, PLT_Plateau plateau, Joueur joueur1, Joueur joueur2);
#endif

