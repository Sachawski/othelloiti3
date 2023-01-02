/**
2 * \file IHM.c
3 * \brief Fichier contenant les fonctions de l'IMB
4 * \author V. Turnel, S. Wojciechowski
5 * \version 1.0
6 * \date 04/12/2022
7 *
8 */

#include "TADposition.h"
#include "TADpion.h"
#include "TADcouleur.h"
#include "TADplateau.h"
#include "TADcoup.h"
#include "TADcoups.h"
#include "faireUnePartie.h"
#include "IMB.h"
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
* \fn CP_Coup interactionBroker(PLT_Plateau plateau, CLR_Couleur couleur, int profondeur)
* \brief Fonction qui permet de lire le coup envoyer par le broker.
* \param plateau Inutilisé ici, présente pour des raisons de cohérence au niveaud des appels.
* \param couleur Couleur du broker.
* \param profondeur Inutilisé ici, présente pour des raisons de cohérence au niveau des appels.
* \return CP_Coup (Coup du broker)
*/
CP_Coup interactionBroker(PLT_Plateau plateau, CLR_Couleur couleur, int profondeur) {
    CP_Coup coupBroker ;
    PN_Pion pionBroker ;
    POS_Position coorTemp ;
    char buffer[LONGUEUR_COUP] ;
    char x ;
    int y ;
    //read(STDIN_FILENO,buffer,LONGUEUR_COUP);
    fgets(buffer,sizeof(buffer),stdin);
    
    x = buffer[0] ;
    y = buffer[1] ;
    
    coorTemp = POS_position(x-97,y-1);
    pionBroker = PN_pion(couleur);

    coupBroker = CP_coup(pionBroker,coorTemp);

    return coupBroker ;
}

/**
* \fn void envoiBroker(PLT_Plateau plateau, CP_Coup coup)
* \brief Procédure qui permet d'écrire le coup de l'IA dans le terminal pour le transmettre au broker
* \param plateau Inutilisé ici, présente pour des raisons de cohérence au niveaud des appels
* \param coup Coup joué par l'IA
*/
void envoiBroker(PLT_Plateau plateau, CP_Coup coup, int possibilite) {
    int x,y ;
    char xChar,yChar;
    char buffer[LONGUEUR_COUP];

    if(possibilite){
        x = POS_obtenirX(CP_position(coup));
        y = POS_obtenirY(CP_position(coup));

        xChar = x+'a'; 
        yChar = y+'1';

        buffer[0] = xChar ;
        buffer[1] = yChar ;
        buffer[2] = '\n' ;

        int w = write(STDOUT_FILENO, buffer, strlen(buffer));
        if (w < 0)
            perror (" Erreur lors de l’ecriture : ");
    }
    else {
        int w = write(STDOUT_FILENO, "passe\n", strlen("passe\n"));
        if (w < 0)
            perror (" Erreur lors de l’ecriture : ");
        
    }

}

/**
* \fn finDePartieBroker(CLR_Couleur couleurGagnante, EtatPartie etat)
* \brief Indique l'état de fin de partie en mode tournois.
* \param couleurGagnante La couleur gagnante en cas de victoire.
* \param etat Etat du plateau de la partie en fin de jeu : Victoire | Egalite.
*/
void finDePartieBroker(CLR_Couleur couleurGagnante, EtatPartie etat){
  if(etat==partieGagnee){
    if(couleurGagnante == NOIR)
      printf("noir\n");
    else
      printf("blanc\n");
  } else {
    printf("nulle\n");
  }
}