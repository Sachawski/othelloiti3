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
    j = 0 ;
    i++;
  }
  return sontEgaux; 
}

void test_initialiserPlateau(void) {
    C_Case cV ;
    cV.estVide = 1 ;
    C_Case cB ;
    C_Case cN ;
    cB.estVide = 0;
    cB.casePion = PN_pion(BLANC);
    cN.estVide = 0;
    cN.casePion = PN_pion(NOIR);
    C_Case initialiserTableau[LARGEUR_PLATEAU][HAUTEUR_PLATEAU] = {
        { cV, cV, cV, cV, cV, cV, cV, cV},
        { cV, cV, cV, cV, cV, cV, cV, cV},
        { cV, cV, cV, cV, cV, cV, cV, cV},
        { cV, cV, cV, cB, cN, cV, cV, cV},
        { cV, cV, cV, cN, cB, cV, cV, cV},
        { cV, cV, cV, cV, cV, cV, cV, cV},
        { cV, cV, cV, cV, cV, cV, cV, cV},
        { cV, cV, cV, cV, cV, cV, cV, cV}
    };
    PLT_Plateau plateauAttendu;
    memcpy(plateauAttendu.tabPlateau,initialiserTableau,sizeof(C_Case)*HAUTEUR_PLATEAU*LARGEUR_PLATEAU);
    PLT_Plateau plateauObtenu = initialiserPlateau();
    CU_ASSERT_TRUE(plateauEgaux(plateauAttendu,plateauObtenu));

}
void test_coupLegal(void) {
    PLT_Plateau plateau;
    plateau = initialiserPlateau();
    // Coups légals dès le début par les noirs
    CP_Coup coup1 = CP_coup(PN_pion(NOIR),POS_position(2,3));
    CP_Coup coup2 = CP_coup(PN_pion(NOIR),POS_position(3,2));
    CP_Coup coup3 = CP_coup(PN_pion(NOIR),POS_position(5,4));
    CP_Coup coup4 = CP_coup(PN_pion(NOIR),POS_position(4,5));
    CP_Coup coup5 = CP_coup(PN_pion(NOIR),POS_position(4,6));
    // Coups jouables dès le début par les noirs (d'après la fonction)
    CU_ASSERT_TRUE(coupLegal(plateau,coup1));
    CU_ASSERT_TRUE(coupLegal(plateau,coup2));
    CU_ASSERT_TRUE(coupLegal(plateau,coup3));
    CU_ASSERT_TRUE(coupLegal(plateau,coup4));
    CU_ASSERT_FALSE(coupLegal(plateau,coup5));

}


void test_pionMemeCouleur(void){
    PLT_Plateau plateau;
    plateau = initialiserPlateau();

    PLT_poserPion(&plateau,POS_position(2,3),PN_pion(NOIR));
    PLT_poserPion(&plateau,POS_position(1,3),PN_pion(BLANC));
    PLT_poserPion(&plateau,POS_position(1,4),PN_pion(NOIR));
    PLT_poserPion(&plateau,POS_position(2,5),PN_pion(NOIR));
    PLT_poserPion(&plateau,POS_position(2,4),PN_pion(BLANC));
    PLT_poserPion(&plateau,POS_position(4,2),PN_pion(BLANC));
    PLT_poserPion(&plateau,POS_position(3,5),PN_pion(NOIR));
    PLT_poserPion(&plateau,POS_position(4,5),PN_pion(BLANC));
    
    
    
    CP_Coup coupTest = CP_coup(PN_pion(BLANC),POS_position(1,5));
    CPS_Coups resultatAttendu;
    resultatAttendu = CPS_coups();

    CP_Coup coup1 = CP_coup(PN_pion(BLANC),POS_position(1,3));
    CP_Coup coup2 = CP_coup(PN_pion(BLANC),POS_position(4,5));

    CPS_ajouterCoups(&resultatAttendu, coup1);
    CPS_ajouterCoups(&resultatAttendu, coup2);

    CPS_Coups adversairesAdj;
    adversairesAdj = CPS_coups();
    adversairesAdj = adversairesAdjacents(plateau,coupTest);
    
    CPS_Coups resultatObtenu;
    resultatObtenu = CPS_coups();
    resultatObtenu = pionMemeCouleur(plateau,coupTest,adversairesAdj);


    CU_ASSERT_EQUAL(resultatObtenu.nbTotalCoups,resultatAttendu.nbTotalCoups);
    CU_ASSERT_EQUAL(PN_obtenirCouleurSuperieure(CP_pion(CPS_iemeCoup(resultatAttendu,1))),PN_obtenirCouleurSuperieure(CP_pion(CPS_iemeCoup(resultatObtenu,1))));
    CU_ASSERT_EQUAL(PN_obtenirCouleurSuperieure(CP_pion(CPS_iemeCoup(resultatAttendu,2))),PN_obtenirCouleurSuperieure(CP_pion(CPS_iemeCoup(resultatObtenu,2))));
    
    }




void test_adversairesAdjacents(void){
  PLT_Plateau plateau;
  CPS_Coups cps;
  plateau = PLT_plateau();
  plateau = initialiserPlateau();
  
    PLT_poserPion(&plateau,POS_position(2,3),PN_pion(NOIR));
    PLT_poserPion(&plateau,POS_position(1,3),PN_pion(BLANC));
    PLT_poserPion(&plateau,POS_position(1,4),PN_pion(NOIR));
    PLT_poserPion(&plateau,POS_position(2,5),PN_pion(NOIR));
    PLT_poserPion(&plateau,POS_position(2,4),PN_pion(BLANC));
    PLT_poserPion(&plateau,POS_position(4,2),PN_pion(BLANC));
    PLT_poserPion(&plateau,POS_position(3,5),PN_pion(NOIR));
    PLT_poserPion(&plateau,POS_position(4,5),PN_pion(BLANC));

    

  CP_Coup coup0 = CP_coup(PN_pion(BLANC),POS_position(1,5));
  CP_Coup coup1 = CP_coup(PN_pion(NOIR),POS_position(1,4));
  CP_Coup coup2 = CP_coup(PN_pion(NOIR),POS_position(2,5));

  cps = CPS_coups();
  
  CPS_ajouterCoups(&cps,coup1);
  CPS_ajouterCoups(&cps,coup2);

  CPS_Coups varcps;
  varcps = adversairesAdjacents(plateau,coup0);
  
  CU_ASSERT_EQUAL(varcps.nbTotalCoups,cps.nbTotalCoups);
  CU_ASSERT_EQUAL(PN_obtenirCouleurSuperieure(CP_pion(CPS_iemeCoup(cps,1))),PN_obtenirCouleurSuperieure(CP_pion(CPS_iemeCoup(varcps,1))));
  CU_ASSERT_EQUAL(PN_obtenirCouleurSuperieure(CP_pion(CPS_iemeCoup(cps,2))),PN_obtenirCouleurSuperieure(CP_pion(CPS_iemeCoup(varcps,2))));
}

void test_evaluerNb(void){
    C_Case cV ;
    cV.estVide = 1 ;
    C_Case cB ;
    C_Case cN ;
    cB.estVide = 0;
    cB.casePion = PN_pion(BLANC);
    cN.estVide = 0;
    cN.casePion = PN_pion(NOIR);
    C_Case initialiserTableau[LARGEUR_PLATEAU][HAUTEUR_PLATEAU] = {
        { cN, cB, cB, cB, cN, cB, cN, cB},
        { cN, cB, cN, cB, cB, cN, cB, cN},
        { cB, cN, cB, cN, cB, cN, cB, cN},
        { cB, cN, cB, cV, cN, cN, cB, cB},
        { cN, cB, cN, cV, cN, cB, cN, cB},
        { cB, cB, cN, cN, cN, cB, cN, cB},
        { cN, cB, cN, cN, cN, cB, cN, cB},
        { cN, cB, cN, cN, cN, cB, cN, cB}
    };
    PLT_Plateau plateauAttendu;
    memcpy(plateauAttendu.tabPlateau,initialiserTableau,sizeof(C_Case)*HAUTEUR_PLATEAU*LARGEUR_PLATEAU);
    int resultatBlanc = evaluerNb(plateauAttendu,BLANC);
    int resultatNoir = evaluerNb(plateauAttendu,NOIR);
    CU_ASSERT_EQUAL(resultatBlanc,30);
    CU_ASSERT_EQUAL(resultatNoir,32);
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
    if ((NULL == CU_add_test(pSuite, "Test general de initialiserPlateau", test_initialiserPlateau ))
	|| (NULL == CU_add_test(pSuite, "Test general de coupLegal", test_coupLegal))
	|| (NULL == CU_add_test(pSuite, "Test general de evaluerNb", test_evaluerNb))
	|| (NULL == CU_add_test(pSuite, "Test general de pionMemeCouleur", test_pionMemeCouleur))
	|| (NULL == CU_add_test(pSuite, "Test general de adversairesAdjacents", test_adversairesAdjacents))
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
