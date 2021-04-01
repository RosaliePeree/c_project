/*
 * exo5.c
 *
 *  Created on: 1 avr. 2021
 *      Author: ycott
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
typedef struct maillon {
int x;
struct maillon * suiv;
} maillon;

void emptyBuffer();

int read(char *chain, int length);

void afficherListe(maillon *lc){
	while (lc != NULL) //tant que le maillon courant n'est pas le suivant du dernier maillon de la liste
	{
	printf("Valeur du champs courant = %d \n",lc->x);
	printf("Adresse maillon courant= %X et du suivant %X\n",lc, lc->suiv);
	lc = lc->suiv;//passe au suivant
	}
}


void supprimerMaillon(maillon ** tete){
	int entreeValide=0;
	int X;
	while(!entreeValide){
		printf("Entrez le numero du maillon a supprimer : \n");
		X=0;
		char rea[100];
		read(rea, 90);
		X = atoi(rea);
		if(X<N && X>=0){
			entreeValide=1;
		}
	}
	if(X==0){
		*tete=(*tete)->suiv;
	}
	else{
		maillon *lc=*tete;
		for(int cpt=1;cpt<X;cpt++){
			lc=lc->suiv;
		}
		maillon mail=*lc->suiv;
		lc->suiv=mail.suiv;
	}
}

void main(void)
{
maillon *lc;
maillon *tete;
int cpt;
/*init des maillons*/
lc = (maillon *) malloc(sizeof(maillon));
tete = lc;
//Creation des maillons en fin de liste
for(cpt=1;cpt<N;cpt++) //pour tous les maillons à créer
{
lc->suiv = (maillon *) malloc(sizeof(maillon));
lc = lc->suiv;
}
lc->suiv = NULL;
cpt = 0;
lc = tete;
//remplissage des valeurs de chacun des maillons
while (lc != NULL) //tant que le maillon courant n'est pas le suivant du dernier maillon de la liste
{
lc->x = cpt; //affectation
cpt++; //increment du compteur
lc = lc->suiv;//passe au suivant
}
lc = tete;
afficherListe(tete);
supprimerMaillon(&tete);
afficherListe(tete);
}

void emptyBuffer(){
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

int read(char *chain, int length)
{
    char *entry = NULL;

    if (fgets(chain, length, stdin) != NULL)
    {
        entry = strchr(chain, '\n');
        if (entry != NULL)
        {
            *entry = '\0';
        }
        else
        {
            emptyBuffer();
        }
        return 1;
    }
    else
    {
        emptyBuffer();
        return 0;
    }
}
