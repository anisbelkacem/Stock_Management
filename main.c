#include <stdio.h>
#include <stdlib.h>
#include "Produit.h"

typedef struct{
	char nom[100];
	long id;
	char cat[100];
	long qte;
	float prix;

}produit;

typedef struct{
	int a;
	int m;
	int j;

}date;

int main()
{
   char rep[4]="";
    do
    {
        int menu();
        switch(menu())
        {
        case 1:
            printf("**** VOUS AVEZ CHOISIT D'AJOUTER UN PRODUIT **** \n");
            Ajouter();
            break;
        case 2:
            printf("**** VOUS AVEZ CHOISIT D'AFFICHER LA DESCRIPTION D'UN PRODUIT ****\n" );
            affdes();
            break;
        case 3:
            printf("**** VOUS AVEZ CHOISIT DE SUPPRIMER UN PRODUIT ****\n");
            supp();
            break;
        case 4:
            printf("**** VOUS AVEZ CHOISIT DE MODIFIER UN PRODUIT **** \n");
            modif ();
            break;
        case 5:
            printf("**** VOUS ETES EN QUÊTE D'UN PRODUIT ****\n");
            printf("DONNER L'IDENTIFIANT A CHERCHER: ");
            long id;
            scanf("%d",&id);
            printf("%d",recherche(id));
            break;
        case 6:
            printf("**** VOUS AVEZ CHOISIT D'AFFICHER LE CONTENU DU STOCK ****\n");
            aff_stock();
        case 7:
            return 0;
        }
        printf("\n VOULEZ-VOUS CONTINUER? (oui/non): ");
        gets(rep);
        fflush(stdin);
    }while(rep[0]=='o');
    system("exit");

}
