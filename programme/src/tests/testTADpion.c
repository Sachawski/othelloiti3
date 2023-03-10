#include <stdio.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "TADpion.h"
#include "TADcouleur.h"
/* 
C_INCLUDE_PATH=/opt/local/include
export C_INCLUDE_PATH

gcc -c testTADpion.c  -I ../include -I /opt/homebrew/Cellar/cunit/2.1-3/in
clude
gcc testTADpion.o -o test -L /opt/homebrew/Cellar/cunit/2.1-3/lib -lcunit
c'est l'environement de CUnit pour ma ordinateur
*/




int init_suite_success (void) {
  return 0;
}

int clean_suite_success (void) {
  return 0;
}

void test_PN_obtenirCouleurSuperieure(void) {
  PN_Pion pion= PN_pion(BLANC);
  CLR_Couleur resultatAttendu= BLANC;
  CLR_Couleur resultatObtenu= PN_obtenirCouleurSuperieure(pion);
  CU_ASSERT_EQUAL(resultatAttendu,resultatObtenu);
}

void test_PN_retournerPion(void){
  PN_Pion pion= PN_pion(BLANC);
  CLR_Couleur resultatAttendu= NOIR;
  PN_retournerPion(&pion);
  CLR_Couleur resultatObtenu= PN_obtenirCouleurSuperieure(pion);
  CU_ASSERT_EQUAL(resultatAttendu,resultatObtenu);
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
    if ((NULL == CU_add_test(pSuite, "Test general de PN_obtenirCouleurSuperieur", test_PN_obtenirCouleurSuperieure ))
        || (NULL == CU_add_test(pSuite, "Test general de PN_retournerPion", test_PN_retournerPion))) {

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
