/** \file
 * \brief Developpement du TAD Couleur
 * \author P. Thulliez
 * \version 1.0
 * \date 06/12/2022     
 */


#include <stdlib.h>
#include "TADcouleur.h"

/**
 * \fn CLR_Couleur CLR_noir()
 * \brief Fonction qui retourne la couleur NOIR
 * \return CLR_Couleur
 */

CLR_Couleur CLR_noir(){
	return NOIR;
}

/**
 * \fn CLR_Couleur CLR_blanc()
 * \brief Fonction qui retourne la couleur BLANC
 * \return CLR_Couleur
 */

CLR_Couleur CLR_blanc(){
	return BLANC;
}

/**
 * \fn int  CLR_estBlanc(CLR_Couleur c)
 * \brief Fonction qui retourne un booleen. Si la couleur est BLANC alors le booleen retourne Vrai, sinon il retourne Faux.
 * \return bool
 */

int CLR_estBlanc(CLR_Couleur c){
	return c==BLANC;
}

/**
 * \fn CLR_Couleur CLR_changerCouleur(CLR_Couleur c1)
 * \brief Fonction qui retourne la couleur adverse à celle donnée en entrée.
 * \return CLR_Couleur
 */

CLR_Couleur CLR_changerCouleur(CLR_Couleur c1){
	if(CLR_estBlanc(c1)){
		return NOIR;
	}
	else{
		return BLANC;
	}
}

