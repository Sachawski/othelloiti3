#ifndef  __TADPLATEAU__
#define __TADPLATEAU__
Plateau plateau();
void poserPion(Plateau* plateau, Position pos, Pion pion);
Pion obtenirPion(Plateau plateau, Position pos);
bool estCaseVide(Plateau plateau , Position pos);
void retournerPion(Plateau* plateau, Position pos);
void enleverPion(Plateau* plateau, Position pos);
#endif