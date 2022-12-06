/**
2 * \file TADcoups.h
3 * \brief Implantation du TAD Coups
4 * \author P.Thulliez
5 * \version 1.0
6 * \date 06/12/2022
7 *
8 */

#ifndef __TADCOUPS__
#define __TADCOUPS__
#include "TADcoup.h"

typedef struct 
    {   
        /* Modélisation d'une liste de coups par ses deux caractéristiques :
        - le tableau contenant les coups
        - le nombre total de coups
        */

        CP_Coup lesCoups[LARGEUR_PLATEAU*HAUTEUR_PLATEAU] ;
        int nbTotalCoups ;
    } CPS_Coups ;



 /* fonction qui génère une liste de Coups (de type Coups) vide
    */

CPS_Coups CPS_coups();


 /* fonction qui retourne le nombre de coups d'une liste de Coups (de type Coups)
    */

int CPS_nbCoups(CPS_Coups cps);

 /* procédure qui permet de rajouter un Coup à la liste de Coups (de type Coups)
    */

void CPS_ajouterCoups(CPS_Coups cps, CP_Coup unCoup);

 /* fonction qui retourne le ième coup de la liste de Coups (de type Coups)
    */

CP_Coup CPS_iemeCoup(CPS_Coups cps, unsigned short int place);

#endif
