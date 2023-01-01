#ifndef __IMB__
#define __IMB__

#define LONGUEUR_COUP 3

/**
* \fn CP_Coup interactionBroker(PLT_Plateau plateau, CLR_Couleur couleur, int profondeur)
* \brief Fonction qui permet de lire le coup envoyer par le broker
* \param plateau Inutilisé ici, présente pour des raisons de cohérence au niveaud des appels
* \param couleur Couleur du broker
* \param profondeur Inutilisé ici, présente pour des raisons de cohérence au niveau des appels
* \return CP_Coup (Coup du broker)
*/
CP_Coup interactionBroker(PLT_Plateau plateau, CLR_Couleur couleur, int profondeur) ;

/**
* \fn void envoiBroker(PLT_Plateau plateau, CP_Coup coup)
* \brief Procédure qui permet d'écrire le coup de l'IA dans le terminal pour le transmettre au broker
* \param plateau Inutilisé ici, présente pour des raisons de cohérence au niveaud des appels
* \param coup Coup joué par l'IA
* \return void
*/
void envoiBroker(PLT_Plateau plateau, CP_Coup coup, int possibilite);

void finDePartieBroker(CLR_Couleur couleurGagnante, EtatPartie etat);

#endif