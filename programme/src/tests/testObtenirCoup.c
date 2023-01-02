#include <stdio.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "faireUnePartiePrive.h"
#include "faireUnePartie.h"
#include "obtenirCoup.h"
#include "obtenirCoupPrive.h"
#include "TADcoup.h"
#include "TADpion.h"
#include "TADposition.h"
#include "TADcouleur.h"
#include "TADplateau.h"
#include "IHM.h"

#define PROFONDEUR_THEO 3


int init_suite_success (void) {
    return 0;
}

int clean_suite_success (void) {
    return 0;
}

int plateauEgaux(PLT_Plateau plateau1, PLT_Plateau plateau2) 
{
    long int i = 0;
    long int j = 0;
    int sontEgaux = 1;

    while(sontEgaux && (i<HAUTEUR_PLATEAU)) 
    {
        while(sontEgaux && (j<LARGEUR_PLATEAU))
        {
            sontEgaux = ((plateau1.tabPlateau[i][j].estVide == plateau2.tabPlateau[i][j].estVide) );
            j++;
        }
        i++;
    }
    return sontEgaux; 
}

PLT_Plateau initPlateauTest()
{

    PLT_Plateau plateau = initialiserPlateau();
    
    // Création d'une situation de jeu compliquée
    PLT_poserPion(&plateau,POS_position(4,0),PN_pion(BLANC));
    PLT_poserPion(&plateau,POS_position(5,0),PN_pion(BLANC));
    PLT_poserPion(&plateau,POS_position(6,0),PN_pion(BLANC));
    PLT_poserPion(&plateau,POS_position(2,1),PN_pion(NOIR));
    PLT_poserPion(&plateau,POS_position(3,1),PN_pion(BLANC));
    PLT_poserPion(&plateau,POS_position(4,1),PN_pion(BLANC));
    PLT_poserPion(&plateau,POS_position(5,1),PN_pion(NOIR));
    PLT_poserPion(&plateau,POS_position(2,2),PN_pion(NOIR));
    PLT_poserPion(&plateau,POS_position(3,2),PN_pion(NOIR));
    PLT_poserPion(&plateau,POS_position(4,2),PN_pion(NOIR));
    PLT_poserPion(&plateau,POS_position(5,2),PN_pion(NOIR));
    PLT_poserPion(&plateau,POS_position(7,2),PN_pion(NOIR));
    PLT_poserPion(&plateau,POS_position(2,3),PN_pion(NOIR));
    PLT_poserPion(&plateau,POS_position(5,3),PN_pion(BLANC));
    PLT_poserPion(&plateau,POS_position(6,3),PN_pion(BLANC));
    PLT_poserPion(&plateau,POS_position(7,3),PN_pion(NOIR));
    PLT_poserPion(&plateau,POS_position(2,4),PN_pion(NOIR));
    PLT_poserPion(&plateau,POS_position(5,4),PN_pion(NOIR));
    PLT_poserPion(&plateau,POS_position(6,4),PN_pion(NOIR));
    PLT_poserPion(&plateau,POS_position(7,4),PN_pion(NOIR));
    PLT_poserPion(&plateau,POS_position(2,5),PN_pion(BLANC));
    PLT_poserPion(&plateau,POS_position(3,5),PN_pion(BLANC));
    PLT_poserPion(&plateau,POS_position(4,5),PN_pion(BLANC));
    PLT_poserPion(&plateau,POS_position(5,5),PN_pion(BLANC));
    PLT_poserPion(&plateau,POS_position(6,5),PN_pion(BLANC));
    PLT_poserPion(&plateau,POS_position(7,5),PN_pion(NOIR));
    PLT_retournerPion(&plateau,POS_position(3,3));
    PLT_retournerPion(&plateau,POS_position(4,4));
    PLT_retournerPion(&plateau,POS_position(4,3)); 
    

    return plateau;
}

void test_obtenirCoupsPossibles(void) {
    PLT_Plateau plateau;
    CPS_Coups resultatAttendu = CPS_coups();

    
    plateau = initialiserPlateau();
    // Coups jouables dès le début par les noirs
    CPS_ajouterCoups(&resultatAttendu,CP_coup(PN_pion(NOIR),POS_position(3,2)));
    CPS_ajouterCoups(&resultatAttendu,CP_coup(PN_pion(NOIR),POS_position(2,3)));
    CPS_ajouterCoups(&resultatAttendu,CP_coup(PN_pion(NOIR),POS_position(5,4)));
    CPS_ajouterCoups(&resultatAttendu,CP_coup(PN_pion(NOIR),POS_position(4,5)));
    
    // Coups jouables dès le début par les noirs (d'après la fonction)
    CPS_Coups resultatObtenu = obtenirCoupsPossibles(plateau,NOIR);
    CU_ASSERT_EQUAL(resultatAttendu.nbTotalCoups,resultatObtenu.nbTotalCoups);
    CU_ASSERT_EQUAL(POS_obtenirX(CP_position(CPS_iemeCoup(resultatObtenu,1))),POS_obtenirX(CP_position(CPS_iemeCoup(resultatAttendu,1))));
    CU_ASSERT_EQUAL(POS_obtenirX(CP_position(CPS_iemeCoup(resultatObtenu,2))),POS_obtenirX(CP_position(CPS_iemeCoup(resultatAttendu,2))));
    CU_ASSERT_EQUAL(POS_obtenirX(CP_position(CPS_iemeCoup(resultatObtenu,3))),POS_obtenirX(CP_position(CPS_iemeCoup(resultatAttendu,3))));
    CU_ASSERT_EQUAL(POS_obtenirX(CP_position(CPS_iemeCoup(resultatObtenu,4))),POS_obtenirX(CP_position(CPS_iemeCoup(resultatAttendu,4))));

    CU_ASSERT_EQUAL(POS_obtenirY(CP_position(CPS_iemeCoup(resultatObtenu,1))),POS_obtenirY(CP_position(CPS_iemeCoup(resultatAttendu,1))));
    CU_ASSERT_EQUAL(POS_obtenirY(CP_position(CPS_iemeCoup(resultatObtenu,2))),POS_obtenirY(CP_position(CPS_iemeCoup(resultatAttendu,2))));
    CU_ASSERT_EQUAL(POS_obtenirY(CP_position(CPS_iemeCoup(resultatObtenu,3))),POS_obtenirY(CP_position(CPS_iemeCoup(resultatAttendu,3))));
    CU_ASSERT_EQUAL(POS_obtenirY(CP_position(CPS_iemeCoup(resultatObtenu,4))),POS_obtenirY(CP_position(CPS_iemeCoup(resultatAttendu,4))));

}

void test_obtenirCoup(void) {
    PLT_Plateau plateau;

    plateau = initialiserPlateau();
    // Création d'une situation de jeu compliquée
    PLT_poserPion(&plateau,POS_position(2,4),PN_pion(NOIR));
    PLT_poserPion(&plateau,POS_position(1,4),PN_pion(NOIR));
    PLT_poserPion(&plateau,POS_position(5,4),PN_pion(NOIR));
    PLT_poserPion(&plateau,POS_position(6,4),PN_pion(BLANC));
    PLT_retournerPion(&plateau,POS_position(4,4));
    PLT_retournerPion(&plateau,POS_position(4,3));
    // Meilleur coup théorique pour les noirs
    CP_Coup resultatAttendu = CP_coup(PN_pion(BLANC),POS_position(0,4));
    // Meilleur pour les noirs d'après la machine
    CP_Coup resultatObtenu = obtenirCoup(plateau,BLANC,PROFONDEUR_THEO);
    CU_ASSERT_EQUAL(PN_obtenirCouleurSuperieure(CP_pion(resultatAttendu)),PN_obtenirCouleurSuperieure(CP_pion(resultatObtenu)));
    CU_ASSERT_EQUAL(POS_obtenirX(CP_position(resultatObtenu)),POS_obtenirX(CP_position(resultatAttendu)));
    CU_ASSERT_EQUAL(POS_obtenirY(CP_position(resultatObtenu)),POS_obtenirY(CP_position(resultatAttendu)));
}

void test_compteurCouleur(void) 
{

    PLT_Plateau plateau = initPlateauTest();

    int compteurAttenduBlanc = 13 ;
    int compteurObtenuBlanc = compteurCouleur(plateau,CLR_blanc()) ;
    int compteurAttenduNoir = 17 ;
    int compteurObtenuNoir = compteurCouleur(plateau,CLR_noir()) ;
    CU_ASSERT_EQUAL(compteurAttenduNoir,compteurObtenuNoir);
    CU_ASSERT_EQUAL(compteurAttenduBlanc,compteurObtenuBlanc);
}

void test_score(void) 
{
    PLT_Plateau plateau = initPlateauTest();

    int scoreAttenduBlanc = -6; 
    int scoreObtenuBlanc = score(plateau,CLR_blanc()) ;
    int scoreAttenduNoir = 31 ;
    int scoreObtenuNoir = score(plateau,CLR_noir()) ;
    CU_ASSERT_EQUAL(scoreAttenduNoir,scoreObtenuNoir);
    CU_ASSERT_EQUAL(scoreAttenduBlanc,scoreObtenuBlanc);
}


void test_evaluer(void) 
{

    PLT_Plateau plateau = initPlateauTest();

    int evaluationAttenduBlanc = -37 ;
    int evaluationObtenuBlanc = evaluer(plateau,CLR_blanc()) ;
    int evaluationAttenduNoir = 37 ;
    int evaluationObtenuNoir = evaluer(plateau,CLR_noir()) ;
    CU_ASSERT_EQUAL(evaluationAttenduNoir,evaluationObtenuNoir);
    CU_ASSERT_EQUAL(evaluationAttenduBlanc,evaluationObtenuBlanc);
}

void test_plateauBloque(void) 
{
    PLT_Plateau plateau = initPlateauTest();

    int resultatAttendu = 0 ;
    int resultatObtenu = plateauBloque(plateau) ;
    CU_ASSERT_EQUAL(resultatObtenu,resultatAttendu);
}

void test_plateauBloquePourUneCouleur(void) 
{

    PLT_Plateau plateau = initPlateauTest();
    
    int resultatAttenduBlanc = 0 ;
    int resultatObtenuBlanc = plateauBloquePourUneCouleur(plateau,CLR_blanc()) ;
    int resultatAttenduNoir = 0 ;
    int resultatObtenuNoir = plateauBloquePourUneCouleur(plateau,CLR_noir()) ;
    CU_ASSERT_EQUAL(resultatObtenuBlanc,resultatAttenduBlanc);
    CU_ASSERT_EQUAL(resultatObtenuNoir,resultatAttenduNoir);
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
    if ((NULL == CU_add_test(pSuite, "Test general de obtenirCoupsPossibles", test_obtenirCoupsPossibles ))
        || (NULL == CU_add_test(pSuite, "Test general de obtenirCoup", test_obtenirCoup))
        || (NULL == CU_add_test(pSuite, "Test general de compteurCouleur", test_compteurCouleur))
        || (NULL == CU_add_test(pSuite, "Test general de score", test_score))
        || (NULL == CU_add_test(pSuite, "Test general de evaluer", test_evaluer))
        || (NULL == CU_add_test(pSuite, "Test general de plateauBloquePourUneCouleur", test_plateauBloquePourUneCouleur))
        || (NULL == CU_add_test(pSuite, "Test general de plateauBloque", test_plateauBloque))) {

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