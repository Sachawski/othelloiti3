#include <stdio.h>
#include <CUnit/Basic.h>
#include "TADcouleur.h"
#include <stdbool.h>
int init_suite_success (void) {
    return 0;
}

int clean_suite_success (void) {
    return 0;
}
 
void test_CLR_estBlanc(void){
CLR_Couleur couleur = CLR_blanc();
int resultatObtenu = CLR_estBlanc(couleur);
int resultatAttendu = 1;
CU_ASSERT_EQUAL(resultatAttendu,resultatObtenu);
}

void test_CLR_changerCouleur(void){
CLR_Couleur couleur= CLR_noir();
CLR_Couleur resulatAttendu = BLANC;
CLR_Couleur resultatObtenu = CLR_changerCouleur(couleur);
CU_ASSERT_EQUAL(resultatObtenu,resulatAttendu);
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
    if ((NULL == CU_add_test(pSuite, "Test general de CLR_estBlanc", test_CLR_estBlanc ))
        || (NULL == CU_add_test(pSuite, "Test general de CLR_changerCouleur", test_CLR_changerCouleur))) {

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
