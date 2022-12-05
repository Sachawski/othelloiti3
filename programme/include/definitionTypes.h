#ifndef __DEFINITIONTYPES__
#define __DEFINITIONTYPES__

#define HAUTEUR_PLATEAU 8
#define LARGEUR_PLATEAU 8
#define False 0 
#define True 1

typedef enum {BLANC,NOIR} Couleur ;

typedef struct 
    {
        Couleur couleur ;
    } Pion ;

typedef struct 
    {
        int x;
        int y;
    } Position ;

typedef struct 
    {
        Pion pion ;
        Position position ;
    } Coup ;

typedef struct 
    {   
        Coup lesCoups[LARGEUR_PLATEAU*HAUTEUR_PLATEAU] ;
        int nbTotalCoups ;
    } Coups ;

typedef struct 
    {
        int estVide ;
        Pion pion ;
    } Case ;

typedef Case Plateau[LARGEUR_PLATEAU][HAUTEUR_PLATEAU] ;

#endif