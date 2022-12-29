#include "TADposition.h"
#include "TADpion.h"
#include "TADcouleur.h"
#include "TADplateau.h"
#include "TADcoup.h"
#include "TADcoups.h"
#include "faireUnePartie.h"
#include "IMB.h"
#include <stdio.h>

CP_Coup interactionBroker(PLT_Plateau plateau, CLR_Couleur couleur, int profondeur) {
    CP_Coup coupBroker ;
    PN_Pion pionBroker ;
    POS_Position coorTemp ;
    char buffer[LONGUEUR_COUP] ;
    char x ;
    int y ;

    FILE* fichier =  fopen("nomFlux","r");
    fgets(buffer,LONGUEUR_COUP,fichier);
    
    x = buffer[0] ;
    y = buffer[1] ;
    
    coorTemp = POS_position(x-97,y-1);
    pionBroker = PN_pion(couleur);

    coupBroker = CP_coup(pionBroker,coorTemp);

    return coupBroker ;
}

void envoiBroker(PLT_Plateau plateau, CP_Coup coup) {
    int x,y ;
    char xChar ;
    x = POS_obtenirX(CP_position(coup));
    y = POS_obtenirY(CP_position(coup));
    xChar = x+'a'; 

    printf("%c",x) ;
    printf("%d",y+1) ;
}
