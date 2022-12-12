#include "TADcoups.h"
#include "TADcoup.h"
#include "TADcoups.h"
#include "TADpion.h"
#include "TADposition.h"
#include <stdio.h>
#include <stdlib.h>

CPS_Coups CPS_coups{
  CPS_Coups coups; unsigned short int i;unsigned short int j; unsigned short int k; POS_Position pos; PN_Pion pion; Plateau plateau;
  coups.nbTotalCoups=0;
  k=0;
  plateau = PLT_plateau();
    for(i=1,LARGEUR_PLATEAU,i++){
      for(j=1;HAUTEUR_PLATEAU;j++){
	  pos = POS_position(i,j);
	  pion=PLT_obtenirPion(plateau,pos);
	  coups.lesCoups[k]=CP_coup(pion,pos);
	  k++;
	}
    }
  return coups;
}

int CPS_nbCoups(CPS_Coups cps){
  return cps.nbTotalCoups;
}

void CPS_ajouterCoups(CPS_Coups cps, CP_Coup unCoup){
  cps.nbTotalCoups=cps.nbTotalCoups+1;
  cps.lesCoups[cps.nbTotalCoups]=unCoup;
}

CP_Coup CPS_iemeCoup(CPS_Coups cps, unsigned short int place){
  return cps.lesCoups[place];
}
