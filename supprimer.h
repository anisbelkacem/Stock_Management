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


void supp()
{
    char rep[4];
    long id;
    printf("VEUILLEZ ENTRER L'IDENTIFIANT DU PRODUIT A SUPPRIMER: ");
    scanf("%d",&id);
    fflush(stdin);
    if (recherche(id)==1);
    {
        printf("\n VOULEZ-VOUS VRAIMENT SUPPRIMER CE PRODUIT? (oui/non): ");
        scanf("%s",rep);
        fflush(stdin);

        if(rep[0]=='o')
            {
                FILE* Fich, *F;
                F=fopen("stock.txt","r");
                Fich=fopen("stock1.txt","w");
                do
                {
                    produit prod;
                    fscanf(F,"%d%s%d%f%s\n",&prod.id,prod.nom,&prod.qte,&prod.prix,prod.cat);

                    if (id!=prod.id)
                    {fprintf(Fich,"\n%d\t%s\t%d\t\t%f\t%s",prod.id,prod.nom,prod.qte,prod.prix,prod.cat);}
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
                printf("FELICITATIONs; VOTRE SUPPRESSION A ETE EFFECTUEE AVEC SUCCES! ");
                fclose(F);
                fclose(Fich);


            }

    }


}
