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


void affdes()
{
    FILE *F;
    F=fopen("stock.txt","r" );
    int id;
    printf("VEUILLEZ DONNER L'IDENTIFIANT DU PRODUIT A AFFICHER: \n");
    scanf("%d",&id);
    fflush(stdin);
    if(recherche(id)==1)
    {
        do
    {
        produit prod;
        fscanf(F,"%d%s%d%f%s\n",&prod.id,prod.nom,&prod.qte,&prod.prix,prod.cat);
        if (id==prod.id)
        {
            printf("************* DESCRIPTION DU PRODUIT SELECTIONNE ************* \n \n");
            printf("IDENTIFIANT\t: %d \n",prod.id);
            printf("NOM\t: %s \n",prod.nom);
            printf("QUANTITE\t: %d \n",prod.qte);
            printf("PRIX\t: %f \n",prod.prix);
            printf("CATEGORIE\t: %s\n",prod.cat);

        }
    }while(!feof(F));
    fclose(F);
    }
    else{
        printf("DESOLE; LE PRODUIT ENTRE N'EXISTE PAS! ");
    }


}
