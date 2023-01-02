/**
2 * \file IMB.h
3 * \brief Implantation de la fonction de l'IMB
4 * \author V. Turnel, S. Wojciechowski
5 * \version 1.0
6 * \date 04/12/2022
7 *
8 */

#ifndef __IMB__
#define __IMB__

#define LONGUEUR_COUP 3

/**
* \fn CP_Coup interactionBroker(PLT_Plateau plateau, CLR_Couleur couleur, int profondeur)
* \brief Fonction qui permet de lire le coup envoyer par le broker.
* \param plateau Inutilisé ici, présente pour des raisons de cohérence au niveaud des appels.
* \param couleur Couleur du broker.
* \param profondeur Inutilisé ici, présente pour des raisons de cohérence au niveau des appels.
* \return CP_Coup (Coup du broker)
*/
CP_Coup interactionBroker(PLT_Plateau plateau, CLR_Couleur couleur, int profondeur) ;

/**
* \fn void envoiBroker(PLT_Plateau plateau, CP_Coup coup)
* \brief Procédure qui permet d'écrire le coup de l'IA dans le terminal pour le transmettre au broker
* \param plateau Inutilisé ici, présente pour des raisons de cohérence au niveaud des appels
* \param coup Coup joué par l'IA
*/
void envoiBroker(PLT_Plateau plateau, CP_Coup coup, int possibilite);

/**
* \fn finDePartieBroker(CLR_Couleur couleurGagnante, EtatPartie etat)
* \brief Indique l'état de fin de partie en mode tournois.
* \param couleurGagnante La couleur gagnante en cas de victoire.
* \param etat Etat du plateau de la partie en fin de jeu : Victoire | Egalite.
*/
void finDePartieBroker(CLR_Couleur couleurGagnante, EtatPartie etat);

#endif