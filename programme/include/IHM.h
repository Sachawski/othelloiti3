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
* \fn afficherPlateau(PLT_Plateau plateau)
* \brief Affiche le plateau actuel dans le terminal.
* \param plateau Représente le plateau de jeu.
*/
void afficherPlateau(PLT_Plateau plateau, CP_Coup coup, int possibilite);

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

