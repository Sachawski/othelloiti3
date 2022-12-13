#include <stdio.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "TADcoup.h"
#include "TADpion.h"
#include "TADposition.h"
#include "TADcouleur.h"
#include "TADplateau.h"

int init_suite_success (void) {
    return 0;
}

int clean_suite_success (void) {
    return 0;
}

int plateauEgaux(PLT_Plateau plateau1, PLT_Plateau plateau2) {
  long int i = 0;
  long int j = 0;
  int sontEgaux = 1;
  
  while(sontEgaux && (i<HAUTEUR_PLATEAU)) {
    while(sontEgaux && (j<LARGEUR_PLATEAU)){
        sontEgaux = ((plateau1.tabPlateau[i][j].estVide == plateau2.tabPlateau[i][j].estVide) );
        if (!(plateau1.tabPlateau[i][j].estVide == plateau2.tabPlateau[i][j].estVide)){
            sontEgaux = (plateau1.tabPlateau[i][j].casePion.couleur == plateau2.tabPlateau[i][j].casePion.couleur);
        }
        
        j++;
    }
    i++;
  }
  return sontEgaux; 
}


void test_PLT_plateau(void) {
    C_Case cV ;
    cV.estVide = 1 ;

    C_Case tableauVide[LARGEUR_PLATEAU][HAUTEUR_PLATEAU] = {
        { cV, cV, cV, cV, cV, cV, cV, cV},
        { cV, cV, cV, cV, cV, cV, cV, cV},
        { cV, cV, cV, cV, cV, cV, cV, cV},
        { cV, cV, cV, cV, cV, cV, cV, cV},
        { cV, cV, cV, cV, cV, cV, cV, cV},
        { cV, cV, cV, cV, cV, cV, cV, cV},
        { cV, cV, cV, cV, cV, cV, cV, cV},
        { cV, cV, cV, cV, cV, cV, cV, cV}
    };
    PLT_Plateau plateauAttendu;

    memcpy(plateauAttendu.tabPlateau,tableauVide,sizeof(C_Case)*HAUTEUR_PLATEAU*LARGEUR_PLATEAU);
    
    PLT_Plateau plateauObtenu = PLT_plateau();

    CU_ASSERT_TRUE(plateauEgaux(plateauAttendu,plateauObtenu));

}

void test_PLT_poserPion(void) {
    // case remplie 
    PN_Pion pion = PN_pion(BLANC) ;
    C_Case cR ;
    cR.estVide = 0;
    cR.casePion = pion ;

    // definition de ce qu'on attend
    PLT_Plateau plateauAttendu = PLT_plateau();
    plateauAttendu.tabPlateau[6][6] = cR;

    // def de ce qu'on obtient
    POS_Position position = POS_position(6,6) ;
    PLT_Plateau plateauObtenu = PLT_plateau();
    PLT_poserPion(&plateauObtenu,position,pion);
    CU_ASSERT_TRUE(plateauEgaux(plateauAttendu,plateauObtenu));
}

void test_PLT_obtenirPion(void) {
    // case remplie et pion attendu
    PN_Pion resultatAttendu = PN_pion(BLANC) ;
    C_Case cR ;
    cR.estVide = 0;
    cR.casePion = resultatAttendu ;

    // definition du plateau de test
    PLT_Plateau plateau = PLT_plateau();
    plateau.tabPlateau[6][6] = cR ;
    // def de ce qu'on obtient
    POS_Position position = POS_position(6,6);
    PN_Pion resultatObtenu = PLT_obtenirPion(plateau,position);
    CU_ASSERT_EQUAL(resultatAttendu.couleur,resultatObtenu.couleur);
}

void test_PLT_estCaseVide(void) {
    // case vide 
    C_Case cV ;
    cV.estVide = 1 ;
    int resultatAttendu = cV.estVide ; 
    // definition du plateau de test
    PLT_Plateau plateau = PLT_plateau();

    // def de ce qu'on obtient
    POS_Position position = POS_position(6,6);
    int resultatObtenu = PLT_estCaseVide(plateau,position);
    CU_ASSERT_EQUAL(resultatAttendu,resultatObtenu);
}

void test_PLT_retournerPion(void) {
    // case remplie Blanc
    PN_Pion pionAttendu = PN_pion(BLANC);   
    C_Case cRBlanc;
    cRBlanc.estVide = 0;
    cRBlanc.casePion = pionAttendu ;

    // definition de ce qu'on attend
    PLT_Plateau plateauAttendu = PLT_plateau();
    plateauAttendu.tabPlateau[6][6] = cRBlanc ;
    
    // case remplie Noir
    PN_Pion pionN = PN_pion(NOIR);
    C_Case cRNoir ;
    cRNoir.estVide = 0;
    cRNoir.casePion = pionN ;

    // definition du plateau de travail
    PLT_Plateau plateauObtenu = PLT_plateau() ;
    plateauObtenu.tabPlateau[6][6] = cRNoir ;

    // def de ce qu'on obtient
    POS_Position position = POS_position(6,6);
    PLT_retournerPion(&plateauObtenu,position);
    CU_ASSERT_TRUE(plateauEgaux(plateauAttendu,plateauObtenu));
}

void test_PLT_enleverPion(void) {
    // definition de ce qu'on attend
    PLT_Plateau plateauAttendu = PLT_plateau();

    // case remplie Noir
    PN_Pion pion = PN_pion(BLANC) ;
    C_Case cRNoir ;
    cRNoir.estVide = 0;
    cRNoir.casePion = pion ;

    // definition du plateau de travail
    PLT_Plateau plateauObtenu = PLT_plateau();
    plateauObtenu.tabPlateau[6][6] = cRNoir ;

    // def de ce qu'on obtient
    POS_Position position = POS_position(6,6);
    PLT_enleverPion(&plateauObtenu,position);
    CU_ASSERT_TRUE(plateauEgaux(plateauAttendu,plateauObtenu));
}

int main(int argc , char** argv){
    CU_pSuite pSuite = NULL;

    /* initialisation du registre de tests */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();


    /* ajout d’une suite de test */
    pSuite = CU_add_suite("Tests boite noire",init_suite_success,clean_suite_success );
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Ajout des tests à la suite de tests boite noire */
    if ((NULL == CU_add_test(pSuite, "Test general de PLT_plateau", test_PLT_plateau))
        || (NULL == CU_add_test(pSuite, "Test general de PLT_poserPion", test_PLT_poserPion))
        || (NULL == CU_add_test(pSuite, "Test general de PLT_obtenirPion", test_PLT_obtenirPion))
        || (NULL == CU_add_test(pSuite, "Test general de PLT_estCaseVide", test_PLT_estCaseVide))
        || (NULL == CU_add_test(pSuite, "Test general de PLT_retournerPion", test_PLT_retournerPion))
        || (NULL == CU_add_test(pSuite, "Test general de PLT_enleverPion", test_PLT_enleverPion))) {

        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Lancement des tests */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    printf("\n");
    CU_basic_show_failures(CU_get_failure_list());
    printf("\n\n");

    /* Nettoyage du registre */
    CU_cleanup_registry();
    return CU_get_error();
}