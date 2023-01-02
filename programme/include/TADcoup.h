/**
 * \file TADcoup.h
 * \brief Implementation du TAD Coup
 * \author V. Turnel
 * \version 1.0
 * \date 03/12/2022
*/

#ifndef __TADcoup__
#define __TADcoup__

#include "TADpion.h"
#include "TADposition.h"

/**
 * \struct CP_Coup
 * \brief Modélise un coup
 * CP_Coup est un type qui définit un coup dans le jeu,
  c'est-à-dire la position et le pion qu'on pose
*/
typedef struct {
   PN_Pion pion ; /**< Le pion qui est joué*/
   POS_Position position ; /**< La position où l'on joue*/
} CP_Coup;

/**
* \fn CP_Coup CP_coup(PN_Pion pion, POS_Position pos)
* \brief Fonction qui crée un coup à partir d'un pion et d'une position
* \param pion Pion concernée par le coup
* \param position Position du coup
* \return CP_Coup (Le coup crée avec le pion et la position)
*/
CP_Coup CP_coup(PN_Pion pion, POS_Position pos);

/**
* \fn PN_Pion CP_pion(CP_Coup coup)
* \brief Fonction qui permet d'obtenir le pion concerné par le coup
* \param coup Le coup dont on souhaite avoir le pion
* \return PN_Pion (Le pion du coup donné)
*/
PN_Pion CP_pion(CP_Coup coup);

/**
* \fn POS_Position CP_position(CP_Coup coup)
* \brief Fonction qui permet d'obtenir la position du coup
* \param coup Le coup dont on souhaite avoir la position
* \return POS_Position (Position du coup donné)
*/
POS_Position CP_position(CP_Coup coup);

#endif
