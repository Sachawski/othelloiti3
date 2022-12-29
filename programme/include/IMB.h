#ifndef __IMB__
#define __IMB__

#define LONGUEUR_COUP 3

CP_Coup interactionBroker(PLT_Plateau plateau, CLR_Couleur couleur, int profondeur) ;

void envoiBroker(PLT_Plateau plateau, CP_Coup coup);

#endif