#ifndef __DEFINITIONTYPES__
#define __DEFINITIONTYPES__

#define HAUTEUR_PLATEAU 8
#define LARGEUR_PLATEAU 8
#define False 0 
#define True 1

/// @brief Modélisation d'une couleur qui est soit noir, soit blanche
typedef enum {BLANC,NOIR} CLR_Couleur ;

typedef struct 
    {
        /* Modélisation d'un pion par sa couleur
        */

        CLR_Couleur couleur ;
    } PN_Pion ;

typedef struct 
    {
        /* Modélisation d'une position par ses coordonnées selon :
        - la colonne x
        - la ligne y
        */

        int x;
        int y;
    } POS_Position ;

typedef struct 
    {
        /* Modélisation d'un coup par ses deux caractéristiques :
        - pion qui est joué
        - position où le pion est placé
        */

        PN_Pion pion ;
        POS_Position position ;
    } CP_Coup ;

typedef struct 
    {   
        /* Modélisation d'une liste de coups par ses deux caractéristiques :
        - le tableau contenant les coups
        - nombre total de coups
        */

        CP_Coup lesCoups[LARGEUR_PLATEAU*HAUTEUR_PLATEAU] ;
        int nbTotalCoups ;
    } CPS_Coups ;

typedef struct 
    {
        /* Modélisation d'une case par ses deux caractéristiques :
        - le fait qu'elle soit vide ou non
        - la couleur qui y serait présente
        */

        int estVide ;
        PN_Pion pion ;
    } C_Case ;

typedef C_Case PLT_Plateau[LARGEUR_PLATEAU][HAUTEUR_PLATEAU] ;

#endif