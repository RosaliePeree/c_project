#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exo.h"

typedef struct{
	int jour;
	int mois;
	int annee;
} date;

typedef struct {
	char nom[20];
	char prenom[20];
	date naissance;
} personne;


personne carnet[20];
int taille=0;

int afficherMenu(){
	int choice=-1;
	while(choice<0 || choice >6){
			printf("Menu :\n1: Nouveau contact\n2: Affichage des contacts\n3: Tri des contacts\n");
			printf("4: Recherche de Contact\n5: Supression d'un contact\n0: Quitter\n");
			char tmp[3];
			read(tmp, 2);
			choice = atoi(tmp);
	}
	return choice;
}

void nouveauContact(){
	if(taille>19){
		printf("Carnet d'adresses plein\n");
	}
	else{
		char nom[20];
		char prenom[20];
		int jour;
		int mois;
		int annee;
		char tmp[6];
		printf("Entrez le nom du contact : ");
		read(nom, 19);
		printf("Entrez le prenom du contact : ");
		read(prenom, 19);
		do	{	
		printf("Entrez le jour de naissance du contact format dd : ");
		read(tmp, 3);	
		jour = atoi(tmp);
		} while (jour<1 || jour>31);

		do	{	
		printf("Entrez le mois de naissance du contact format mm : ");
		read(tmp, 3);	
		mois = atoi(tmp);
		} while (mois<1 || mois>12);

		do	{	
		printf("Entrez l'annee de naissance du contact format yyyy : ");
		read(tmp, 4);	
		annee = atoi(tmp);
		} while (annee<1900 || annee>2022);


		read(tmp, 5);
		annee = atoi(tmp);
		date anniv;
		anniv.jour=jour;
		anniv.mois=mois;
		anniv.annee=annee;
		personne nouveau;
		strcpy(nouveau.nom,nom);
		strcpy(nouveau.prenom,prenom);
		nouveau.naissance=anniv;
		carnet[taille]=nouveau;
		taille=taille+1;
	}
}

void afficherContact(int i){
	if(i<taille){
		printf("Id : %i Nom : %20s Prenom : %20s Date de naissance : %i/%i/%i\n",i,carnet[i].nom,carnet[i].prenom,carnet[i].naissance.jour,carnet[i].naissance.mois,carnet[i].naissance.annee);
	}
}

void afficherContacts(){
	printf("Nombre de contacts : %i\n",taille);
	for(int i=0;i<taille;i++){
		afficherContact(i);
	}
}

void triContacts(){
	for(int i=0;i<taille-1;i=i+1){
		int min=i;
		int datemin=(carnet[i].naissance.annee*10000)+(carnet[i].naissance.mois*100)+carnet[i].naissance.jour;
		for(int j=i+1;j<taille;j=j+1){
			int datej=(carnet[j].naissance.annee*10000)+(carnet[j].naissance.mois*100)+carnet[j].naissance.jour;
			if(datej<datemin){
				min=j;
				datemin=datej;
			}
		}
		personne tmp=carnet[i];
		carnet[i]=carnet[min];
		carnet[min]=tmp;
	}
}

void rechercheContact(){
	printf("Entrez le nom du contact recherche : ");
	char nom[20];
	read(nom, 19);
	for(int i=0;i<taille;i=i+1){
		if(strcmp(nom,carnet[i].nom)==0){
			afficherContact(i);
		}
	}
}

void suppressionContact(){
	int id;
	printf("Entrez le numero du contact : ");
	char tmp[3];
	read(tmp, 2);
	id = atoi(tmp);	
	if(id>taille-1){
		printf("Contact inexistant\n");
	}
	else{
		for(int i=id;i<taille;i=i+1){
			carnet[i]=carnet[i+1];
		}
		taille=taille-1;
	}
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