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


void modif ()
{
    char rep[5];
    int id;
    printf("VEUILLER ENTRER L'IDENTIFIANT DU PRODUIT A MODIFIER: ");
    scanf("%d",&id);
    fflush(stdin);
    if (recherche(id)==1)
    {
        printf("\n VOULEZ-VOUS VRAIMENT MODIFIER CE PRODUIT? (oui/non):  " );
        gets(rep);
        fflush(stdin);
        if (rep[0]=='o')
            {
                FILE* Fich, *F;
                F=fopen("stock.txt","r");
                Fich=fopen("stock1.txt","w");
                do
                {
                    produit produit;
                    fscanf(F,"%d%s%d%f%s\n",&produit.id,produit.nom,&produit.qte,&produit.prix,produit.cat);
                    if (id==produit.id)
                    {
                        produit.id=id;
                        printf("\n VEUILLEZ DONNER LE NOUVEAU NOM DU PRODUIT A MODIFIER: ");
                        gets(produit.nom);
                        printf("\n VEUILLEZ DONNER LA NOUVELLE CATEGORIE DU PRODUIT A MODIFIER: ");
                        gets(produit.cat);
                        printf("\n VEUILLEZ DONNER LE NOUVEAU PRIX DU PRODUIT A MODIFIER: ");
                        float prix;
                        scanf("%f",&prix);
                        produit.prix=prix;
                        printf("\n VEUILLEZ DONNER LA NOUVELLE QUANTITE DU PRODUIT A MODIFIER: ");
                        int qte;
                        scanf("%d",&qte);
                        produit.qte=qte;
                        fflush(stdin);
                        fprintf(Fich,"%d\t%s\t%d\t\t%f\t%s\n",produit.id,produit.nom,produit.qte,produit.prix,produit.cat);}
                }while(!feof(F));
                fclose(F);
                fclose(Fich);
                F=fopen("stock.txt","w");
                Fich=fopen("stock1.txt","r");
                do
                {
                    produit prod;
                    fscanf(Fich,"%d%s%d%f%s\n",&prod.id,prod.nom,&prod.qte,&prod.prix,prod.cat);
                    fprintf(F,"\n%d\t%s\t%d\t\t%f\t%s",prod.id,prod.nom,prod.qte,prod.prix,prod.cat);
                }while(!feof(Fich));
                fclose(F);
                fclose(Fich);
                printf("  FELICITATIONS; VOTRE MODIFICATION A ETE EFFECTUEE AVEC SUCCES!   ");
            }
            else
            {
                printf("\n VOTRE MODIFICATION A ETE ANNULEE \n ");

            }
    }
    else
    {
        printf("\n DESOLE; L'IDENTIFIANT ENTRE N'EXISTE PAS! \n");

    }


}
