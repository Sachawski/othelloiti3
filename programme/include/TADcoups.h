/**
 * \file TADcoups.h
 * \brief Implementation du TAD Coups
 * \author P. Thulliez
 * \version 1.0
 * \date 06/12/2022
*/

#ifndef __TADCOUPS__
#define __TADCOUPS__

#include "TADcoup.h"
#include "TADplateau.h"

/**
 * \struct CPS_Coups
 * \brief Modélise une liste de coups 
 * CPS_Coups est un type qui modélise une liste de coups (CP_COUP)
*/
typedef struct {
    CP_Coup lesCoups[LARGEUR_PLATEAU*HAUTEUR_PLATEAU] ; 
    /**< Tableau contenant les différents coups*/
    int nbTotalCoups ; /**< Nombre de coups dans le tableau*/
} CPS_Coups ;

/**
 * \fn CPS_Coups CPS_coups()
 * \brief Fonction qui retourne un tableau de coups vide
 * \return CPS_Coups (vide)
 */
CPS_Coups CPS_coups();

/**
 * \fn int CPS_nbCoups(CPS_Coups coups)
 * \brief Fonction qui retourne le nombre de coups d'une liste de coups
 * \param cps Tableau de coups dont on cherche à connaitre la taille
 * \return int (nombre de coups présent dans coups)
 */
int CPS_nbCoups(CPS_Coups coups);

/**
 * \fn void CPS_ajouterCoups(CPS_Coups *coups, CP_Coup coup)
 * \brief Procédure qui ajoute un coup dans un tableau de coups
 * \param cps Liste de coup dans laquelle ajouter un coup
 * \param cp Coup à ajouter
 * \return void
 */
void CPS_ajouterCoups(CPS_Coups *coups, CP_Coup coup);

/**
 * \fn CP_Coup CPS_iemeCoup(CPS_Coups coups, unsigned short int i)
 * \brief Fonction qui retourne le coup à la position i d'un tableau de coups
 * \param cps Tableau de coup dont on cherche à connaitre le i
 * \param i Position ud coup dans le tableau de coups
 * \return CP_Coup (ieme coup du tableau de coups)
 */
CP_Coup CPS_iemeCoup(CPS_Coups coups, unsigned short int i);

#endif
