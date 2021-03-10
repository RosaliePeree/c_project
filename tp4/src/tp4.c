/*
 * tp4.c
 *
 *  Created on: 10 mars 2021
 *      Author: ycott
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int jour;
	int mois;
	int annee;
}date;

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
			scanf("%i", &choice);
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
		printf("Entrez le nom du contact : ");
		scanf("%20s",&nom);
		printf("Entrez le prenom du contact : ");
		scanf("%20s",&prenom);
		printf("Entrez le jour de naissance du contact : ");
		scanf("%i",&jour);
		printf("Entrez le mois de naissance du contact : ");
		scanf("%i",&mois);
		printf("Entrez l'annee de naissance du contact : ");
		scanf("%i",&annee);
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
	for(int i=0;)
}

void rechercheContact(){

}

void suppressionContact(){
	int id;
	printf("Entrez le numero du contact : ");
	scanf("%i",&id);
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

int main(){
	int choix=-1;
	while(choix!=0){
		choix=afficherMenu();
		switch(choix){
		case 0:
			break;
		case 1:
			nouveauContact();
			break;
		case 2:
			afficherContacts();
			break;
		case 3:
			triContacts();
			break;
		case 4:
			rechercheContact();
			break;
		case 5:
			suppressionContact();
			break;
		}
	}
}
