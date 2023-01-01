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