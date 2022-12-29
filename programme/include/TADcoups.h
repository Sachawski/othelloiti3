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
#include "TADplateau.h"

typedef struct 
    {   
        /* Modélisation d'une liste de coups par ses deux caractéristiques :
        - le tableau contenant les coups
        - le nombre total de coups
        */

        CP_Coup lesCoups[LARGEUR_PLATEAU*HAUTEUR_PLATEAU] ;
        int nbTotalCoups ;
    } CPS_Coups ;



/**
 * \fn CPS_Coups CPS_coups()
 * \brief Fonction qui retourne une liste de Coups vide
 * \return CPS_Coups
 */

CPS_Coups CPS_coups();


/**
 * \fn int CPS_nbCoups(CPS_Coups cps)
 * \brief Fonction qui retourne le nombre de Coups d'une liste de Coups
 * \return int
 */

int CPS_nbCoups(CPS_Coups cps);

/**
 * \fn CPS_ajouterCoups(CPS_Coups *cps, CP_Coup unCoup)
 * \brief Ajoute un Coup dans une liste de Coups
 * \param CPS_Coups
 * \param CP_Coup
 */

void CPS_ajouterCoups(CPS_Coups *cps, CP_Coup unCoup);

/**
 * \fn CP_Coup CPS_iemeCoup(CPS_Coups cps, unsigned short int place)
 * \brief Fonction qui retourne le Coup à la place i d'une liste de Coups
 * \return CP_Coup
 */

CP_Coup CPS_iemeCoup(CPS_Coups cps, unsigned short int place);

#endif
