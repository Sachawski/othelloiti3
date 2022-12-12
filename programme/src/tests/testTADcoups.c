#include "TADcoups.h"
#include "TADcoup.h"
#include "TADcoups.h"
#include "TADpion.h"
#include "TADposition.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <CUnit/Basic.h>

int init_suite_success (void) {
    return 0;
}

int clean_suite_success (void) {
    return 0;
}


void test_CPS_coups(void){
  
  
}

void test_CPS_nbCoups(void){
  CPS_Coups coups;
  coups.nbTotalCoups = 5;
  
  CPS_Coups varCoupsTest;
  varCoupsTest.nbTotalCoups = 5;
  int resultatObtenu = CPS_nbCoups(varCoupsTest);
  CU_ASSERT_EQUAL(coups.nbTotalCoups,resultatObtenu);
}

void test_CPS_ajouterCoups(void){
  CPS_Coups coups; CP_Coup coup;
  coups.nbTotalCoups = coups.nbTotalCoups + 1;
  coup = CP_coup(PN_pion(BLANC),POS_position(2,2));
  coups.lesCoups[coups.nbTotalCoups]=coup;

  CPS_Coups varCoupsTest;
  CPS_ajouterCoups(varCoupsTest, coup);
  CU_ASSERT_EQUAL(coups.lesCoups[coups.nbTotalCoups],varCoupsTest.lesCoups[varCoupsTest.nbTotalCoups]);
}

void test_CPS_iemeCoup(void){
  CPS_Coups coups; unsigned short int i; CP_Coup cp;
  coups.lesCoups[i]=cp;

  CPS_Coups varCoupsTest;
  varCoupsTest.lesCoups[i]=cp;
  CP_Coup resultatObtenu = CPS_iemeCoup(varCoupsTest,i);
  CU_ASSERT_EQUAL(resultatObtenu,cp);
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
    if ((NULL == CU_add_test(pSuite, "Test general de CPS_coups", test_CPS_coups))
        || (NULL == CU_add_test(pSuite, "Test general de CPS_nbCoups", test_CPS_nbCoups))
        || (NULL == CU_add_test(pSuite, "Test general de CPS_ajouterCoups", test_CPS_ajouterCoups))
        || (NULL == CU_add_test(pSuite, "Test general de CPS_iemeCoup", test_CPS_iemeCoup))) {

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
