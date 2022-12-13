#include <stdio.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "TADcoup.h"
#include "TADpion.h"
#include "TADposition.h"
#include "TADcouleur.h"


int init_suite_success (void) {
    return 0;
}

int clean_suite_success (void) {
    return 0;
}

void test_CP_pion(void) {
    POS_Position position = POS_position(6,6);
    PN_Pion pion = PN_pion(BLANC);
    CP_Coup cp = CP_coup(pion,position);
    PN_Pion resultatAttendu = pion;
    PN_Pion resultatObtenu = CP_pion(cp);
    CU_ASSERT_EQUAL(resultatAttendu.couleur,resultatObtenu.couleur);
}

void test_CP_position(void) {
    POS_Position position = POS_position(6,6);
    PN_Pion pion = PN_pion(BLANC);
    CP_Coup cp = CP_coup(pion,position);
    POS_Position resultatAttendu = position;
    POS_Position resultatObtenu = CP_position(cp);
    CU_ASSERT_EQUAL(resultatAttendu.x,resultatObtenu.x);
    CU_ASSERT_EQUAL(resultatAttendu.y,resultatObtenu.y);
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
