#include <stdio.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "faireUnePartiePrive.h"
#include "faireUnePartie.h"
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

void test_coupLegal(void) {
    PLT_Plateau plateau;
    plateau = initialiserPlateau();
    // Coups légals dès le début par les noirs
    CP_Coup coup1 = CP_coup(PN_pion(NOIR),POS_position(2,3));
    CP_Coup coup2 = CP_coup(PN_pion(NOIR),POS_position(3,2));
    CP_Coup coup3 = CP_coup(PN_pion(NOIR),POS_position(5,4));
    CP_Coup coup4 = CP_coup(PN_pion(NOIR),POS_position(4,5));
    // Coups jouables dès le début par les noirs (d'après la fonction)
    CU_ASSERT_TRUE(coupLegal(plateau,coup1));
    CU_ASSERT_TRUE(coupLegal(plateau,coup2));
    CU_ASSERT_TRUE(coupLegal(plateau,coup3));
    CU_ASSERT_TRUE(coupLegal(plateau,coup4));
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
    if ((NULL == CU_add_test(pSuite, "Test general de coupLegal", test_coupLegal ))
        // || (NULL == CU_add_test(pSuite, "Test general de obtenirCoup", test_obtenirCoup))
        ) 
        {

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
