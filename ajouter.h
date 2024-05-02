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


void Ajouter()
{

    long id;
    printf("VEUILLEZ DONNER L'IDENTIFIANT DU PRODUIT A AJOUTER: ");
    scanf("%d",&id);
    fflush(stdin);
    if (recherche(id)==-1)
        {
        FILE *F;
        produit prod;
        F=fopen("stock.txt","w" );
        prod.id=id;
        printf("VEUILLEZ DONNER LE NOM DU PRODUIT A AJOUTER: ");
        gets(prod.nom);
        fflush(stdin);
        printf("VEUILLEZ DONNER LA CATEGORIE DU PRODUIT A AJOUTER: ");
        gets(prod.cat);
        fflush(stdin);
        printf("VEUILLEZ DONNER LE PRIX DU PRODUIT A AJOUTER: ");
        float prix;
        scanf("%f",&prix);
        prod.prix=prix;
        fflush(stdin);
        int qte;
        printf("VEUILLEZ DONNER LA QUANTITE DU PRODUIT A AJOUTER: ");
        scanf("%d",&qte);
        prod.qte=qte;
        fflush(stdin);
        fprintf(F,"\n%d\t%s\t%d\t\t%f\t%s",prod.id,prod.nom,prod.qte,prod.prix,prod.cat);
        fclose(F);
    }
    else
    {
        int qte;
        printf("LE PRODUIT EXISTE DEJA \n");
        printf("VEUILLEZ DONNER LA QUANTITE A AJOUTER POUR CE PRODUIT: ");
        scanf("%d",&qte);
        FILE* Fich, *F;
        F=fopen("stock.txt","r");
        Fich=fopen("stock1.txt","w");

        do
        {
            produit prod;
             fscanf(F,"%d%s%d%f%s\n",&prod.id,prod.nom,&prod.qte,&prod.prix,prod.cat);
            if (id==prod.id)
            {

                prod.qte+=qte;
                fprintf(Fich,"%d\t%s\t%d\t\t%f\t%s \n",prod.id,prod.nom,prod.qte,prod.prix,prod.cat);}
        }while(!feof(F));
        fclose(F);
        fclose(Fich);
        remove("stock.txt");
        rename("stock1.txt","stock.txt");


    }
    printf("FELICITATIONS; VOTRE AJOUT A ETE EFFECTUE AVEC SUCCES! ");


}
