#ifndef  __TADPOSITION__
#define __TADPOSITION__

/**
2 * \file TADposition.h
3 * \brief Implantation du TAD Position
4 * \author P. Thulliez
5 * \version 1.0
6 * \date 06/12/2022
7 *
8 */



typedef struct 
    {
        /* Modélisation d'une position par ses coordonnées selon :
        - la colonne x
        - la ligne y
        */

        int x;
        int y;
    } POS_Position ;



/*  fonction qui retourne une position de type Position grâce à une largeur et une hauteur en entrée 
        */

POS_Position POS_position(int largeur, int hauteur );


/*  fonction qui permet de retourner la largeur (abscisse X) d'une Position
        */

int POS_obtenirX(POS_Position unePosition);


/*  fonction qui permet de retourner la hauteur (ordonnée Y) d'une Position
        */
int POS_obtenirY(POS_Position unePosition);

#endif
