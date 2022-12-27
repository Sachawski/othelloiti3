#include <stdio.h>
#include <stdlib.h>
#include "faireUnePartie.h"
#include "obtenirCoupPrive.h"
#include "obtenirCoup.h"
#include <math.h>
#include <assert.h>
#define profondeur 2
PLT_Plateau initialiserPlateau(void){
    PLT_Plateau plateau;
    plateau=PLT_plateau();
    PLT_poserPion(&plateau, POS_position(3, 3), PN_pion(CLR_blanc()));
    PLT_poserPion(&plateau, POS_position(3, 4), PN_pion(CLR_noir()));
    PLT_poserPion(&plateau, POS_position(4, 3), PN_pion(CLR_noir()));
    PLT_poserPion(&plateau, POS_position(4, 4), PN_pion(CLR_blanc()));
  return plateau;
}



void afficherPlateau(PLT_Plateau plateau){
    system("clear");
    printf("\n      [OTHELLO]\n\n     a  b  c  d  e  f  g  h\n  ┌─────────────────────────┐\n");
    for( int i=0; i<=63; i++ ){
        if ( i%8 == 0 )
          printf(" %d│ ", i/8+ 1 );
        if (plateau.tabPlateau[i/8][i%8].estVide==1)
          printf(" ┼ ");        //vide
        else{
          switch ( plateau.tabPlateau[i/8][i%8].casePion.couleur ){
            case NOIR:
                printf(" ○ ");        //NOIR
                break;
            case BLANC:
                printf(" ● ");        //BLANC
                break;
          }
        }
        if( i%8 == 7 ) printf("│\n");
    }
    printf("  └─────────────────────────┘\n  ");

}


CPS_Coups adversairesAdjacents(PLT_Plateau plateau, CP_Coup coup){
    int recherche, minx, miny, maxx, maxy, x, y;
    POS_Position position, positionTemp;
    CPS_Coups coupsLegals;
    recherche= 1;
    coupsLegals= CPS_coups();
    position=CP_position(coup);
    minx= fmax(0, POS_obtenirX(position)- 1);
    miny= fmax(0, POS_obtenirY(position)- 1);
    maxx= fmin(7, POS_obtenirX(position)+ 1);
    maxy= fmin(7, POS_obtenirY(position)+ 1);
    y=miny;
    while ((y<= maxy)&& recherche== 1) {
        x=minx;
        while ((x<= maxx)&& recherche== 1){
            positionTemp= POS_position(x, y);
            if (!(PLT_estCaseVide(plateau, positionTemp))&& !(POS_obtenirY(position)==POS_obtenirY(positionTemp)&& POS_obtenirX(position)== POS_obtenirX(positionTemp))){
                if ((PN_obtenirCouleurSuperieure(PLT_obtenirPion(plateau, positionTemp)))!= PN_obtenirCouleurSuperieure(CP_pion(coup))){
                    CPS_ajouterCoups(&coupsLegals, CP_coup(PLT_obtenirPion(plateau, positionTemp), positionTemp));
                }
            }
            x+= 1;
        }
        y+= 1;
    }
    return coupsLegals;
}


CPS_Coups pionMemeCouleur(PLT_Plateau plateau, CP_Coup coup, CPS_Coups pionLegal){
    CPS_Coups lesPionsMemeCouleur;
    int nb, i, x, y, directionX, directionY;
    int recherche;
    POS_Position pos;
    CP_Coup coupTemp;
    recherche= 0;
    lesPionsMemeCouleur= CPS_coups();
    nb= CPS_nbCoups(pionLegal);
    for (i= 1; i<= nb; i++){
        recherche= 0;
        coupTemp= CPS_iemeCoup(pionLegal, i);
        x= POS_obtenirX(CP_position(coupTemp));
        y= POS_obtenirY(CP_position(coupTemp));
        directionX= x- POS_obtenirX(CP_position(coup));
        directionY= y- POS_obtenirY(CP_position(coup));
        while (!recherche){
            x+= directionX;
            y+= directionY;
            if (x>= 0&& x<=7&& y>= 0&& y<=7){
                pos= POS_position(x, y);
                if (PN_obtenirCouleurSuperieure(PLT_obtenirPion(plateau, pos))== PN_obtenirCouleurSuperieure(CP_pion(coup))&& !PLT_estCaseVide(plateau, pos)){
                    CPS_ajouterCoups(&lesPionsMemeCouleur, CP_coup(PLT_obtenirPion(plateau, pos), pos));
                    break;
                }
            }
            else{
                break;;
            }
        }
    }
    return lesPionsMemeCouleur;
}



int coupLegal(PLT_Plateau plateau, CP_Coup coup){
    POS_Position position;
    CPS_Coups pionLegals;
    position= CP_position(coup);
    pionLegals= CPS_coups();
    if (PLT_estCaseVide(plateau, position)){
        if (CPS_nbCoups(adversairesAdjacents(plateau, coup))!=0){
            pionLegals= adversairesAdjacents(plateau, coup);
        
            if (CPS_nbCoups(pionMemeCouleur(plateau, coup, pionLegals))!=0){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
        
    }
    else
        return 0;
}



void etatPartie(PLT_Plateau plateau, CLR_Couleur *couleur, EtatPartie *egalite){
    EtatPartie e;
    CLR_Couleur c;
    int scoreBlanc, scoreNoir;
    if (!plateauBloque(plateau)){
        e=partieNulle;
        *egalite=e;
    }
    if (plateauBloque(plateau) ){
        scoreBlanc= evaluerNb(plateau, BLANC);
        scoreNoir= evaluerNb(plateau, NOIR);
        if (scoreBlanc> scoreNoir){
            e= partieGagnee;
            c= BLANC;
            *egalite=e;
            *couleur=c;
        }
        if (scoreNoir> scoreBlanc){
            e= partieGagnee;
            c= NOIR;
            *egalite=e;
            *couleur=c;
        }
        if (scoreNoir== scoreBlanc){
            e= partieEegal;
            *egalite=e;
        }
    }
}
int evaluerNb(PLT_Plateau plateau, CLR_Couleur couleur){
    int compteur,i,j;
    POS_Position pos ;
    compteur = 0 ;
    for (i=0;i<=7;i++) 
    {
        for (j=0;j<=7;j++) 
        {
            pos = POS_position(i,j);
            if (!PLT_estCaseVide(plateau,pos) && (PN_obtenirCouleurSuperieure(PLT_obtenirPion(plateau,pos)) == couleur))
            {
                compteur = compteur + 1 ;
            }
        }
    }
    return compteur ;
}
void retournerPionsEmprisonnes(PLT_Plateau *plateau , CP_Coup coup ) {
    CP_Coup coupTemp;
    int x,y,directionX,directionY;
    POS_Position pos;
    int xCoup = POS_obtenirX(CP_position(coup));
    int yCoup = POS_obtenirY(CP_position(coup));
    CPS_Coups coupsEmprisonnants = pionMemeCouleur(*plateau , coup , adversairesAdjacents(*plateau,coup));
    for(int i=1 ; i<=CPS_nbCoups(coupsEmprisonnants) ; i++){
        coupTemp = CPS_iemeCoup(coupsEmprisonnants, i);
        x = POS_obtenirX(CP_position(coupTemp));
        y = POS_obtenirY(CP_position(coupTemp));
        if(x-xCoup == 0) {
          directionX = 0;
          directionY = (yCoup-y)/abs(y-yCoup);
        }
        else if(y-yCoup == 0){
            directionX = (xCoup-x)/abs(x-xCoup);
            directionY = 0;
        }
        else{
          directionX = (xCoup-x)/abs(x-xCoup);
          directionY = (yCoup-y)/abs(y-yCoup);
        }
        x = x+directionX;
        y = y+directionY;
        while(x!=xCoup || y!=yCoup){
          pos = POS_position(x,y);
          PLT_retournerPion(plateau,pos);
          x = x+directionX;
          y = y+directionY;
        }

    }
}

void jouer(PLT_Plateau * plateau, CP_Coup coup){
    assert(coupLegal);
    retournerPionsEmprisonnes(plateau,coup);
    PLT_poserPion(plateau, CP_position(coup), CP_pion(coup));
    
}

void menu(Mode *mode){
    char c;
    int i;
    printf("\n            [OTHELLO]\n\n   ");
    printf("          NEW GAME\n");
    printf("            (press n)\n");
    do{
        scanf("%c",&c);
    }while(c=='n');
    system("clear");
    printf("\n        IA vs IA\n");
    printf("\n        press 1\n");
    printf("\n        IA vs Humain\n");
    printf("\n        press 2\n");
    printf("\n        Humain vs Humain\n");
    printf("\n        press 3\n");
    do{
        scanf("%d",&i);
    }while(i=='1' || i=='2' ||i=='3');
    switch(i){
        case 1: *mode=IAvsIA;
          break;
        case 2: *mode=IAvsHumain;
          break;
        case 3: *mode=HumainvsHumain;
          break;
    }
}
void faireUnePartie(CP_Coup (*obtenirCoupBlanc)(PLT_Plateau plateau, Joueur joueur, CLR_Couleur couleur), CP_Coup (*obtenirCoupNoir)(PLT_Plateau plateau, Joueur joueur, CLR_Couleur couleur), void (*afficher)(PLT_Plateau plateau), EtatPartie *egalite, CLR_Couleur couleurGagnant, Mode mode){
    PLT_Plateau plateau;
    PN_Pion joueurCourant;
    CP_Coup coup;
    EtatPartie e;
    Joueur joueur1, joueur2;
    e=partieNulle;
    joueurCourant= PN_pion(NOIR);
    plateau= initialiserPlateau();
    afficher(plateau);
    if (mode==IAvsIA){
        printf("IA1 est Noir\n");
        joueur1=IA;
        printf("IA2 est Blanc\n");
        joueur2=IA;
    }
    if (mode==IAvsHumain){
        printf("IA est Noir\n");
        joueur1=IA;
        printf("Humain est Blanc\n");
        joueur2=Humain;
    }
    if (mode==HumainvsHumain){
        printf("Humain1 est Noir\n");
        joueur1=Humain;
        printf("Humain2 est Blanc\n");
        joueur2=Humain;
    }
    while (e==partieNulle){
        jouer(&plateau, coupEnFctJoueur(obtenirCoupEnFctDuJoueur, obtenirCoupEnFctDuJoueur, PN_obtenirCouleurSuperieure(joueurCourant), plateau, joueur1, joueur2));
        afficherPlateau(plateau);
        PN_retournerPion(&joueurCourant);
        etatPartie(plateau, &couleurGagnant, &e);
    }
}

CP_Coup obtenirCoupEnFctDuJoueur(PLT_Plateau plateau, Joueur joueur, CLR_Couleur couleur){
    CP_Coup coup;
    char x;
    int y;
    if (joueur==IA)
        return obtenirCoup(plateau, couleur, profondeur);
    else{
        coup.pion.couleur=couleur;
        printf("col?");
        scanf(" %c",&x);
        printf("ligne?");
        scanf(" %dn",&y);
        coup.position.x=x-97;
        coup.position.y=y-1;
        return coup;
    }
        
}
CP_Coup coupEnFctJoueur(CP_Coup (*obtenirCoupBlanc)(PLT_Plateau plateau, Joueur joueur, CLR_Couleur couleur), CP_Coup (*obtenirCoupNoir)(PLT_Plateau plateau, Joueur joueur, CLR_Couleur couleur), CLR_Couleur couleur, PLT_Plateau plateau, Joueur joueur1, Joueur joueur2){
  CP_Coup coup;
  if (couleur==NOIR){
            printf("Noir\n");
            coup=(*obtenirCoupNoir)(plateau, joueur1, NOIR);
      return coup;
        }
  else{
            printf("blanc\n");
            coup=(*obtenirCoupBlanc)(plateau, joueur2, BLANC);
      return coup;
  }
}
