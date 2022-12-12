#include <stdio.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "faireUnePartiePrive.h"
#include "TADcoup.h"
#include "TADpion.h"
#include "TADposition.h"
#include "TADcouleur.h"

#define PROFONDEUR_THEO 10 


int init_suite_success (void) {
    return 0;
}

int clean_suite_success (void) {
    return 0;
}

void test_obtenirCoupsPossibles(void) {
    PLT_PLATEAU plateau;

    initialiserPlateau(&plateau);
    // Coups jouables dès le début par les noirs
    CPS_ajouterCoups(resultatAttendu,CU_coup(PN_pion(NOIR),POS_position(2,3)));
    CPS_ajouterCoups(resultatAttendu,CU_coup(PN_pion(NOIR),POS_position(3,2)));
    CPS_ajouterCoups(resultatAttendu,CU_coup(PN_pion(NOIR),POS_position(5,4)));
    CPS_ajouterCoups(resultatAttendu,CU_coup(PN_pion(NOIR),POS_position(4,5)));

    // Coups jouables dès le début par les noirs (d'après la fonction)
    CPS_Coups resultatObtenu = obtenirCoupsPossibles(plateau,NOIR);
    CU_ASSERT_EQUAL(resultatAttendu.nbTotalCoups,resultatObtenu.nbTotalCoups);
    CU_ASSERT_EQUAL(resultatAttendu.lesCoups,resultatObtenu.lesCoups);
}

void test_obtenirCoup(void) {
    PLT_PLATEAU plateau;

     initialiserPlateau(&plateau);
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

    // Meilleur coup théorique pour les noirs
    CP_Coup resultatAttendu = CP_coup(PN_pion(NOIR),POS_position(3,0))

    // Meilleur pour les noirs d'après la machine
    CP_Coup resultatObtenu = obtenirCoup(&plateau,NOIR,PROFONDEUR_THEO);
    CU_ASSERT_EQUAL(resultatAttendu.pion.couleur,resultatObtenu.pion.couleur);
    CU_ASSERT_EQUAL(resultatAttendu.position.x,resultatObtenu.position.x);
    CU_ASSERT_EQUAL(resultatAttendu.position.y,resultatObtenu.position.y);
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
    if ((NULL == CU_add_test(pSuite, "Test general de CP_pion", test_CP_pion ))
        || (NULL == CU_add_test(pSuite, "Test general de CP_Position", test_CP_position))) {

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