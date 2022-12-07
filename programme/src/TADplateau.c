#include "TADposition.h"
#include "TADpion.h"
#include "TADplateau.h"
#include "TADcouleur.h"

PLT_Plateau PLT_plateau()
{
    PLT_Plateau plateau ;
    int i,j;
    for (i=1; i<=8; i++)
    {
        for(j=1; j<=8; j++)
        {
            plateau.tabPlateau[i][j].estVide = 1 ;
        }
    }
    return plateau ;
}

void PLT_poserPion(PLT_Plateau* plateau, POS_Position pos, PN_Pion pion)
{
    int x = pos.x ;
    int y = pos.y ; 
    plateau->tabPlateau[x][y].casePion = pion ;
}


PN_Pion PLT_obtenirPion(PLT_Plateau plateau, POS_Position pos)
{
    int x = pos.x ;
    int y = pos.y ; 
    PN_Pion res = plateau.tabPlateau[x][y].casePion ; 
    return res ;
}


int PLT_estCaseVide(PLT_Plateau plateau , POS_Position pos)
{
    int x = pos.x ;
    int y = pos.y ;
    int res = plateau.tabPlateau[x][y].estVide ;
    return res ;
}


void PLT_retournerPion(PLT_Plateau* plateau, POS_Position pos)
{
    PN_Pion pion = PLT_obtenirPion(*plateau, pos);
    PN_retournerPion(&pion);
    PLT_enleverPion(plateau,pos);
    PLT_poserPion(plateau,pos,pion);
}


void PLT_enleverPion(PLT_Plateau* plateau, POS_Position pos)
{
    int x = pos.x ; 
    int y = pos.y ;
    plateau->tabPlateau[x][y].estVide = 1 ;
}
