#include <stdlib.h>
#include "TADcouleur.h"

CLR_Couleur CLR_noir() {
	return NOIR ;
}

CLR_Couleur CLR_blanc() {
	return BLANC ;
}

int CLR_estBlanc(CLR_Couleur c) {
	return c == BLANC ;
}

CLR_Couleur CLR_changerCouleur(CLR_Couleur c1) {
	if (CLR_estBlanc(c1)) {
		return NOIR ;
	}
	else {
		return BLANC ;
	}
}