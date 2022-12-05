#ifndef __TADCOUPS__
#define __TADCOUPS__
#include "definitionTypes.h"

CPS_Coups CPS_coups();

int CPS_nbCoups(CPS_Coups cps);

void CPS_ajouterCoups(CPS_Coups cps, CP_Coup unCoup);

CP_Coup CPS_iemeCoup(CPS_Coups cps, unsigned short int place);

#endif
