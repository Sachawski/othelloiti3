/**
 * \file TADcouleur.h
 * \brief Implementation du TAD Couleur 
 * \author P. Thulliez
 * \version 1.0
 * \date 06/12/2022
*/

#ifndef  __TADCOULEUR__
#define __TADCOULEUR__


/**
 * \enum CLR_Couleur
 * \brief Modélise les couleurs blanc et noir
*/
typedef enum {
    BLANC, /**< Couleur blanche*/
    NOIR /**< Couleur noire*/
} CLR_Couleur ;

/**
 * \fn CLR_Couleur CLR_noir()
 * \brief Fonction qui retourne la couleur NOIR
 * \return CLR_Couleur (couleur NOIR)
 */
CLR_Couleur CLR_noir();

/**
 * \fn CLR_Couleur CLR_blanc()
 * \brief Fonction qui retourne la couleur BLANC
 * \return CLR_Couleur (couleur BLANC)
 */
CLR_Couleur CLR_blanc();

/**
 * \fn int CLR_estBlanc(CLR_Couleur couleur)
 * \brief Fonction qui retourne un booleen.
  Si la couleur est BLANC alors le booleen retourne Vrai, sinon il retourne Faux.
 * \return bool (1 si est BLANC, 0 sinon)
 */
int CLR_estBlanc(CLR_Couleur couleur);

/**
 * \fn CLR_Couleur CLR_changerCouleur(CLR_Couleur couleur)
 * \brief Fonction qui retourne la couleur inverse à celle donnée en entrée.
 * \return CLR_Couleur (couleur inverse de la couleur donnée en paramètre)
 */
CLR_Couleur CLR_changerCouleur(CLR_Couleur couleur);

#endif
