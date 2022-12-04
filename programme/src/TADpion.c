#include "../include/TADpion.h"
#include "../include/TADcouleur.h"

PN_Pion PN_pion(CLR_Couleur Couleur){
  PN_Pion pion;
  pion.couleur=Couleur;
  return pion;
}

CLR_Couleur obtenirCouleurSuperieure(PN_Pion pion){
  return pion.couleur;
}

void retournerPion(PN_Pion *pion){
  pion->couleur=changerCouleur(pion->couleur);
}
