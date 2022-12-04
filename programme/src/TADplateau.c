#include "../include/TADplateau.h"
#include "../include/definitionTypes.h"

PLT_Plateau PLT_plateau()
{   
    PLT_Plateau plateau ;
    return plateau ;
}


void PLT_poserPion(PLT_Plateau* plateau, POS_Position pos, PN_Pion pion);
{
    int x = pos.x ;
    int y = pos.y ; 
    *plateau[x][y].casePion = pion ;
}


PN_Pion PLT_obtenirPion(PLT_Plateau plateau, POS_Position pos);
{
    int x = pos.x ;
    int y = pos.y ; 
    PN_Pion res = plateau[x][y].casePion ; 
    return res ;
}


bool PLT_estCaseVide(PLT_Plateau plateau , POS_Position pos);
{
    int x = pos.x ;
    int y = pos.y ;
    bool res = plateau[x][y].estVide ;
    return res ;
}


void PLT_retournerPion(PLT_Plateau* plateau, POS_Position pos);
{
    int x = pos.x ; 
    int y = pos.y ;
    *plateau[x][y].casePion = couleurChangerCouleur(pion.couleur);
}


void PLT_enleverPion(PLT_Plateau* plateau, POS_Position pos);
{
    int x = pos.x ; 
    int y = pos.y ;
    *plateau[x][y].estVide = True ;
}
