#ifndef  __TADCOUP__
#define __TADCOUP__
#include "pion.h"
#include "position.h"

struct Coup {
  Pion pion;
  Position pos;
}

Coup coupCoup(Pion pion,Position pos);
Pion coupObtenirPionCoup(Coup coup);
Position coupObtenirPositionCoup(Coup coup);

#endif
