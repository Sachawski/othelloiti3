#include "TADposition.h"
#include "TADpion.h"
#include "TADplateau.h"
#include "TADcouleur.h"


/**
 * \fn PLT_Plateau PLT_plateau()
 * \brief Fonction qui initialise un plateau de jeu
 * \return Un plateau initialisé
 */
PLT_Plateau PLT_plateau()
{
    PLT_Plateau plateau ;
    int i,j;
    for (i=0; i<=7; i++)
    {
        for(j=0; j<=7; j++)
        {
            plateau.tabPlateau[i][j].estVide = 1 ;
        }
    }
    return plateau ;
}

/**
 * \fn void PLT_poserPion(PLT_Plateau* plateau, POS_Position pos, PN_Pion pion)
 * \brief Fonction qui pose un pion sur le plateau
 * \param plateau Le plateau de jeu
 * \param pos La position du pion
 * \param pion Le pion à poser
 */
void PLT_poserPion(PLT_Plateau* plateau, POS_Position pos, PN_Pion pion)
{
    int x = pos.x ;
    int y = pos.y ; 
    plateau->tabPlateau[y][x].estVide = 0 ;
    plateau->tabPlateau[y][x].casePion = pion ;
}

/**
 * \fn PN_Pion PLT_obtenirPion(PLT_Plateau plateau, POS_Position pos)
 * \brief Fonction qui obtient le pion qui se trouve sur le plateau
 * \param plateau Le plateau de jeu
 * \param pos La position du pion
 * \return Le pion trouvé
 */
PN_Pion PLT_obtenirPion(PLT_Plateau plateau, POS_Position pos)
{
    int x = pos.x ;
    int y = pos.y ; 
    PN_Pion res = plateau.tabPlateau[y][x].casePion ; 
    return res ;
}

/**
 * \fn int PLT_estCaseVide(PLT_Plateau plateau , POS_Position pos)
 * \brief Fonction qui indique si la case est vide
 * \param plateau Le plateau de jeu
 * \param pos La position de la case
 * \return Un entier indiquant si la case est vide
 */
int PLT_estCaseVide(PLT_Plateau plateau , POS_Position pos)
{
    int x = pos.x ;
    int y = pos.y ;
    int res = plateau.tabPlateau[y][x].estVide ;
    return res ;
}

/**
 * \fn void PLT_retournerPion(PLT_Plateau* plateau, POS_Position pos)
 * \brief Fonction qui retourne un pion sur le plateau
 * \param plateau Le plateau de jeu
 * \param pos La position du pion
 */
void PLT_retournerPion(PLT_Plateau* plateau, POS_Position pos)
{
    PN_Pion pion = PLT_obtenirPion(*plateau, pos);
    PN_retournerPion(&pion);
    PLT_poserPion(plateau,pos,pion);
}


/**
 * \fn void PLT_enleverPion(PLT_Plateau* plateau, POS_Position pos)
 * \brief Fonction qui enlève un pion du plateau
 * \param plateau Le plateau de jeu
 * \param pos La position du pion à enlever
 */
void PLT_enleverPion(PLT_Plateau* plateau, POS_Position pos)
{
    int x = pos.x ; 
    int y = pos.y ;
    plateau->tabPlateau[y][x].estVide = 1 ;
}

