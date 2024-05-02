#include <stdio.h>
#include <stdlib.h>


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



/////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// --------- procedure ajouter un produit--------------
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
        F=fopen("C:\\Users\\amani\\OneDrive\\Bureau\\mini projet\\main1.c\\stock.txt","w" );
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
        F=fopen("C:\\Users\\amani\\OneDrive\\Bureau\\mini projet\\main1.c\\stock.txt","r");
        Fich=fopen("C:\\Users\\amani\\OneDrive\\Bureau\\mini projet\\main1.c\\stock1.txt","w");

        do
        {
            produit prod;
             fscanf(F,"%d%s%d%f%s\n",&prod.id,prod.nom,&prod.qte,&prod.prix,prod.cat);
            if (id==prod.id)
            {

                prod.qte+=qte;
                fprintf(Fich,"%d\t%s\%d\t\t%f\t%s \n",prod.id,prod.nom,prod.qte,prod.prix,prod.cat);}
        }while(!feof(F));
        fclose(F);
        fclose(Fich);
        remove("C:\\Users\\amani\\OneDrive\\Bureau\\mini projet\\main1.c\\stock.txt");
        rename("C:\\Users\\amani\\OneDrive\\Bureau\\mini projet\\main1.c\\stock1.txt","C:\\Users\\amani\\OneDrive\\Bureau\\mini projet\\main1.c\\stock.txt");


    }
    printf("FELICITATION; VOTRE AJOUT A ETE EFFECTUE AVEC SUCCES! ");


}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//----------procedure d'affichage du description d'un produit------------
void affdes()
{
    FILE *F;
    F=fopen("C:\\Users\\amani\\OneDrive\\Bureau\\mini projet\\main1.c\\stock.txt","r" );
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
///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// -------------------- procedure supprimer un produit -----------------

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
                F=fopen("C:\\Users\\amani\\OneDrive\\Bureau\\mini projet\\main1.c\\stock.txt","r");
                Fich=fopen("C:\\Users\\amani\\OneDrive\\Bureau\\mini projet\\main1.c\\stock1.txt","w");
                do
                {
                    produit prod;
                    fscanf(F,"%d%s%d%f%s\n",&prod.id,prod.nom,&prod.qte,&prod.prix,prod.cat);

                    if (id!=prod.id)
                    {fprintf(Fich,"\n%d\t%s\t%d\t\t%f\t%s",prod.id,prod.nom,prod.qte,prod.prix,prod.cat);}
                }while(!feof(F));
                fclose(F);
                fclose(Fich);
                F=fopen("C:\\Users\\amani\\OneDrive\\Bureau\\mini projet\\main1.c\\stock.txt","w");
                Fich=fopen("C:\\Users\\amani\\OneDrive\\Bureau\\mini projet\\main1.c\\stock1.txt","r");
                do
                {
                    produit prod;
                    fscanf(Fich,"%d%s%d%f%s\n",&prod.id,prod.nom,&prod.qte,&prod.prix,prod.cat);
                    fprintf(F,"\n%d\t%s\t%d\t\t%f\t%s",prod.id,prod.nom,prod.qte,prod.prix,prod.cat);
                }while(!feof(Fich));
                printf("FELICITATION; VOTRE SUPPRESSION A ETE EFFECTUEE AVEC SUCCES! ");
                fclose(F);
                fclose(Fich);


            }

    }


}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
// ------------------ procedure modifier un produit ------------------

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
                F=fopen("C:\\Users\\amani\\OneDrive\\Bureau\\mini projet\\main1.c\\stock.txt","r");
                Fich=fopen("C:\\Users\\amani\\OneDrive\\Bureau\\mini projet\\main1.c\\stock1.txt","w");
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
                F=fopen("C:\\Users\\amani\\OneDrive\\Bureau\\mini projet\\main1.c\\stock.txt","w");
                Fich=fopen("C:\\Users\\amani\\OneDrive\\Bureau\\mini projet\\main1.c\\stock1.txt","r");
                do
                {
                    produit prod;
                    fscanf(Fich,"%d%s%d%f%s\n",&prod.id,prod.nom,&prod.qte,&prod.prix,prod.cat);
                    fprintf(F,"\n%d\t%s\t%d\t\t%f\t%s",prod.id,prod.nom,prod.qte,prod.prix,prod.cat);
                }while(!feof(Fich));
                fclose(F);
                fclose(Fich);
                printf("  FELICITATION; VOTRE MODIFICATION A ETE EFFECTUEE AVEC SUCCES!   ");
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
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
//----------------- fonction recherche dans le stock --------------------


int recherche(long id)
{
    FILE *F;
    F=fopen("C:\\Users\\amani\\OneDrive\\Bureau\\mini projet\\main1.c\\stock.txt","r" );
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
/////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//-------------- procedure d'affichage du stock -------------

void aff_stock()
{
    FILE *F;
    F=fopen("C:\\Users\\amani\\OneDrive\\Bureau\\mini projet\\main1.c\\stock.txt","r");
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
