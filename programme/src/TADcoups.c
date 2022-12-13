#include "TADcoups.h"
#include "TADcoup.h"
#include "TADcoups.h"
#include "TADpion.h"
#include "TADposition.h"
#include <stdio.h>
#include <stdlib.h>

CPS_Coups CPS_coups() {
  CPS_Coups resultat;

  resultat.nbTotalCoups=0;
  return resultat;
}

int CPS_nbCoups(CPS_Coups cps){
  return cps.nbTotalCoups;
}

void CPS_ajouterCoups(CPS_Coups *cps, CP_Coup unCoup){
  cps->nbTotalCoups=cps->nbTotalCoups+1;
  cps->lesCoups[cps->nbTotalCoups]=unCoup;
}

CP_Coup CPS_iemeCoup(CPS_Coups cps, unsigned short int place){
  return cps.lesCoups[place];
}
