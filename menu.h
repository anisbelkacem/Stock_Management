#include <stdio.h>
#include <stdlib.h>
#include "recherche.h"


typedef struct{
	char nom[100];
	long id;
	char cat[100];
	long qte;
	float prix;

}produit;


int menu()
{
    system("cls");
    printf("             ****** SOYEZ LE(A) BIENVENU(E) CHEZ NOUS ... VOUS AVEZ CI-DESSOUS LE MENU DES COMMANDES ******\n");
    printf("                ******** PRENEZ VOTRE TEMPS POUR CHOISIR L'OPTION QUI VOUS INTERESSE LE PLUS ********\n");
    printf("                            ************ NOUS SOMMES A VOTRE SERVICE! ************\n ");
    printf("                                                                                                              \n");
    printf("    ************************************************___MENU___***************************************************\n");
    printf("                                                                                                              \n");
    printf("    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("    *                                                                                                           *\n");
    printf("    *                                1 -->  AJOUTER UN PRODUIT.                                                 *\n");
    printf("    *                                2 -->  AFFICHER LA DESCRIPTION D'UN PRODUIT.                               *\n");
    printf("    *                                3 -->  SUPPRIMER UN PRODUIT.                                               *\n");
    printf("    *                                4 -->  MODIFIER UN PRODUIT.                                                *\n");
    printf("    *                                5 -->  CHERCHER UN PRODUIT DANS LE STOCK.                                  *\n");
    printf("    *                                6 -->  AFIICHER LE STOCK.                                                  *\n");
    printf("    *                                7 -->  QUITTER.                                                            *\n");
    printf("    *                                                                                                           *\n");
    printf("    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    int choix;
    do{
        printf("\n ENTRER VOTRE CHOIX S'IL VOUS PLAIT!  ");
        scanf("%d",&choix);
    }while(choix<1 || choix>7 );
    return choix;
}

int recherche(long id)
{
    FILE *F;
    F=fopen("stock.txt","r" );
    long rech=-1;
    do
    {
        produit prod;
        fscanf(F,"%d\t%s\t%d\t\t%f%s\n",&prod.id,prod.nom,&prod.qte,&prod.prix,prod.cat);
        fflush(stdin);
        if (prod.id==id)
            {
                rech=1;
                break;
            }
    }
    while(!feof(F) );
    return rech;
    fclose(F);
}
