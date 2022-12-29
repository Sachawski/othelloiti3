/** \file TADcoups.c
 * \brief Fichier du developpement du TAD Coups
 * \author P. Thulliez
 * \version 1.0
 * \date 05/12/2022     
 */


#include "TADcoups.h"
#include "TADcoup.h"
#include "TADcoups.h"
#include "TADpion.h"
#include "TADposition.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * \fn CPS_Coups CPS_coups()
 * \brief Fonction qui retourne une liste de Coups vide
 * \return CPS_Coups
 */

CPS_Coups CPS_coups() {
  CPS_Coups resultat;

  resultat.nbTotalCoups=0;
  return resultat;
}


/**
 * \fn int CPS_nbCoups(CPS_Coups cps)
 * \brief Fonction qui retourne le nombre de Coups d'une liste de Coups
 * \return int
 */

int CPS_nbCoups(CPS_Coups cps){
  return cps.nbTotalCoups;
}

/**
 * \fn CPS_ajouterCoups(CPS_Coups *cps, CP_Coup unCoup)
 * \brief Ajoute un Coup dans une liste de Coups
 * \param CPS_Coups
 * \param CP_Coup
 */

void CPS_ajouterCoups(CPS_Coups *cps, CP_Coup unCoup){
  cps->nbTotalCoups=cps->nbTotalCoups+1;
  cps->lesCoups[cps->nbTotalCoups]=unCoup;
}

/**
 * \fn CP_Coup CPS_iemeCoup(CPS_Coups cps, unsigned short int place)
 * \brief Fonction qui retourne le Coup à la place i d'une liste de Coups
 * \return CP_Coup
 */

CP_Coup CPS_iemeCoup(CPS_Coups cps, unsigned short int place){
  return cps.lesCoups[place];
}
