#include "TADposition.h"

POS_Position POS_position(int largeur, int hauteur) {
  POS_Position pos ;
  pos.x = largeur ;
  pos.y = hauteur ;
  return pos ;
}

int POS_obtenirX(POS_Position unePosition) {
  return unePosition.x ;
}

int POS_obtenirY(POS_Position unePosition) {
  return unePosition.y ;
}