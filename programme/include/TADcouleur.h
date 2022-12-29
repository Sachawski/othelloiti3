/**
2 * \file TADcouleur.h
3 * \brief Implantation du TAD Couleur
4 * \author P. Thulliez
5 * \version 1.0
6 * \date 06/12/2022
7 *
8 */

#ifndef  __TADCOULEUR__
#define __TADCOULEUR__


/* Modélisation d'une couleur qui est soit noir, soit blanche
    */
typedef enum {BLANC,NOIR} CLR_Couleur ;



/**
 * \fn CLR_Couleur CLR_noir()
 * \brief Fonction qui retourne la couleur NOIR
 * \return CLR_Couleur
 */
CLR_Couleur CLR_noir();

/**
 * \fn CLR_Couleur CLR_blanc()
 * \brief Fonction qui retourne la couleur BLANC
 * \return CLR_Couleur
 */

CLR_Couleur CLR_blanc();

/**
 * \fn int  CLR_estBlanc(CLR_Couleur c)
 * \brief Fonction qui retourne un booleen. Si la couleur est BLANC alors le booleen retourne Vrai, sinon il retourne Faux.
 * \return bool
 */

int CLR_estBlanc(CLR_Couleur c);

/**
 * \fn CLR_Couleur CLR_changerCouleur(CLR_Couleur c1)
 * \brief Fonction qui retourne la couleur adverse à celle donnée en entrée.
 * \return CLR_Couleur
 */

CLR_Couleur CLR_changerCouleur(CLR_Couleur c1);

#endif
