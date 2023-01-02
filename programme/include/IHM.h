/**
2 * \file IHM.h
3 * \brief Implantation de la fonction de l'IHM
4 * \author V. Turnel, S. Wojciechowski
5 * \version 1.0
6 * \date 04/12/2022
7 *
8 */

#ifndef __IHM__
#define __IHM__

#include "faireUnePartie.h"
#include "TADposition.h" 
#include "TADplateau.h"
#include "TADcoups.h" 
#include "TADcoup.h"
#include "TADcouleur.h"
#include "TADpion.h"

/**
* \fn afficherPlateau(PLT_Plateau plateau, CP_Coup coup, int possibilite)
* \brief Affiche le plateau actuel dans le terminal.
* \param plateau Représente le plateau de jeu.
* \param coup Inutile de cette procédure.
* \param possibilite Indique si le joueur à la possibilité de jouer.
*/
void afficherPlateau(PLT_Plateau plateau, CP_Coup coup, int possibilite);


/**
* \fn afficherFinDePartie(CLR_Couleur couleurGagnante, EtatPartie etat)
* \brief Affiche L'état de fin de partie dans le terminal.
* \param couleurGagnante La couleur gagnante en cas de victoire.
* \param etat Etat du plateau de la partie en fin de jeu : Victoire | Egalite.
*/
void afficherFinDePartie(CLR_Couleur couleurGagnante, EtatPartie etat);

/**
* \fn interractionJoueur(PLT_Plateau plateau, CLR_Couleur couleur, int profondeur)
* \brief Permet d'obtenir un coup de la part d'un Humain
* \param plateau Représente le plateau de jeu.
* \param couleur Couleur du joueur humain.
* \param profondeur Inutile dans cette fonction.
*/
CP_Coup interactionJoueur(PLT_Plateau plateau, CLR_Couleur couleur, int profondeur);
#endif

