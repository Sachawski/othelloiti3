#include "../include/TADpion.h"
#include "../include/TADcouleur.h"

PN_Pion PN_pion(CLR_Couleur couleur){
  PN_Pion pion;
  pion.couleur=couleur;
  return pion;
}

CLR_Couleur PN_obtenirCouleurSuperieure(PN_Pion pion){
  return pion.couleur;
}

void PN_retournerPion(PN_Pion *pion){
  pion->couleur=CLR_changerCouleur(pion->couleur);
}
