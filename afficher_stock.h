#include <stdio.h>
#include <stdlib.h>



typedef struct{
	char nom[100];
	long id;
	char cat[100];
	long qte;
	float prix;

}produit;


void aff_stock()
{
    FILE *F;
    F=fopen("stock.txt","r");
    printf("LE STOCK CONTIENT LES PRODUITS SUIVANTS:  \n \n ");
    printf("IDENTIFIANT \t NOM \t QUANTITE \t PRIX \t \t CATEGORIE \n");
    char str[10000];
    fflush(stdin);
    int ch = getc(F);
    while (ch != EOF)
    {
        putchar(ch);
        ch = getc(F);
    }
    if (feof(F))  printf("\n ***** VOUS AVEZ ATTEINT LA FIN DU FICHIER. ");
    else printf("\n <!> ATTENTION! UNE ERREUR EST SURVENUE! <!> ");
    fclose(F);
    getchar();
}
