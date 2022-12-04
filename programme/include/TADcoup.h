/**
2 * \file TADcoup.h
3 * \brief Implantation du TAD Coup
4 * \author V. Turnel
5 * \version 1.0
6 * \date 03/12/2022
7 *
8 */

#ifndef __TADcoup__
#define __TADcoup__
#include "TADpion.h"
#include "TADposition.h"

typedef struct
{
    /* Modélisation d'un coup par ses deux caractéristiques :
        - pion qui est joué
        - position où le pion est placé
    */

   PN_Pion pion;
   POS_Position position;

} CP_Coup;

/**
* \fn P_Coup CP_coup(PN_Pion pion, POS_Position position)
* \brief Création d’un Coup à partir d'un pion et d'une position
* \param pion pièce concernée par le coup
* \param position emplacement du coup
* \return CP_Coup
*/
CP_Coup CP_coup(PN_Pion pion, POS_Position position);

/**
* \fn PN_Pion CP_pion(CP_Coup coup)
* \brief Obtention du pion concerné par le coup
* \param coup le coup
* \return PN_Pion
*/
PN_Pion CP_pion(CP_Coup coup);

/**
* \fn POS_Position CP_position(CP_Coup coup)
* \brief Obtention de la position du coup
* \param coup le coup
* \return POS_Position
*/
POS_Position CP_position(CP_Coup coup);

#endif


