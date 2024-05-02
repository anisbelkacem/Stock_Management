#include <stdio.h>
#include <stdlib.h>


typedef struct{
	char nom[100];
	long id;
	char cat[100];
	long qte;
	float prix;

}produit;


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
    }while(!feof(F) );
    return rech;
    fclose(F);



}
