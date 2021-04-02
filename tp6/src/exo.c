#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "exo.h"

int displayMenu(){
	int choice=-1;
	while(choice<0 || choice >6){
		printf("Menu :\n");
		printf("1: Afficher la liste des personnes enregistrees.\n");
		printf("2: Ajouter une personne a la liste.\n");
		printf("3: Supprimer une personne suivant le numero de badge.\n");
		printf("4: Modifier le code secret d'une personne.\n");
		printf("5: Controle d'acces via le clavier\n");
		printf("6: Sauvegarder dans bdd.txt\n");
		printf("7: Recuperer les donnees de bdd.txt\n");
		printf("0: Quitter\n");
		char tmp[3];
		read(tmp, 2);
		choice = atoi(tmp);
	}
	return choice;
}

void display(node* list){
	int i = 0;
	//S'il y a plusieurs enregistrements
	while(list->next != NULL && list->data != NULL){
		printf("\nNom : %s\nPrenom : %s\nNumero de badge : %i \n\n",list->data->nom, list->data->prenom,list->data->badgeNumber);
		list = list->next;
		i++;
	}
	//Dernier ou seul enregistrement
	if(list->data != NULL){
		printf("Nom : %s\nPrenom : %s\nNumero de badge : %i \n\n",list->data->nom, list->data->prenom,list->data->badgeNumber);
		i++;
	}

	if(i==0){
		printf("Aucun badge dans la base de donnees\n");
	}
}


int newBadgeNumber(node* list){
	int tabCardCode [9999];
	tabCardCode[0] = 0;
	int cpt = 0;

	while(list->next != NULL && cpt < 9999){
		tabCardCode[cpt]=list->data->badgeNumber;
		list = list->next;
		cpt++;
	}
	if(list->data != NULL){
		tabCardCode[cpt++]=list->data->badgeNumber;
	}

	if(tabCardCode[cpt-1] < 9999){
		return tabCardCode[cpt-1]+1;
	}
	else{
		for(int i = 0; i < 9999; i++){
			int j;
			for(j = 0; j < cpt; j++){
				if(i == tabCardCode[j])
					break;
				}
				if(j == cpt)
					return i;
		}
	}

	return -1;
}

void newEntry(node * list){
	char nom[20];
	char prenom[20];
	char code[5];
	printf("Entrez le nom du contact : ");
	read(nom, 19);
	printf("Entrez le prenom du contact : ");
	read(prenom, 19);
	time_t timer = time(NULL);
  	person* nouveau = malloc(sizeof(person));
	strcpy(nouveau->nom,nom);
	strcpy(nouveau->prenom,prenom);
	nouveau->timestamp = timer;
	int badgeNumber = newBadgeNumber(list);
	if(badgeNumber == -1){	printf("Enregistrement impossible, capacite totale atteinte");
		return;
	}
	nouveau->badgeNumber = badgeNumber;
	printf("Entrez le code pin du contact (4 chiffres) : ");
	read(code, 4);
	for (int i = 0; i < 4; ++i)
	{
		nouveau->code[i] = code[i];
	}

	int i = 0;
	node* prev = NULL; 
	while( list->next != NULL){
		prev = list; 
		list = list->next;
		i++;
	}
	if(prev != NULL)
		list->prev = prev;


	if( list->data == NULL){
		list->data = nouveau;
	}
	else {
		node* tmp = malloc(sizeof(node));
		tmp->data = nouveau;
		tmp->prev = list;
		list->next = tmp;
		list = tmp;
		list->next = NULL;
	}
}

void newPerson(node* list, person* per){
  	person* p = malloc(sizeof(per));
	strcpy(p->nom,per->nom);
	strcpy(p->prenom,per->prenom);
	time_t timer = time(NULL);
	p->timestamp = timer;
	int badgeNumber = newBadgeNumber(list);
	if(badgeNumber == -1){	printf("Enregistrement impossible, capacite totale atteinte");
		return;
	}
	p->badgeNumber = badgeNumber;
	for (int i = 0; i < 4; ++i)
	{
		p->code[i] = 0;
	}

	int i = 0;
	node* prev = NULL; 
	while( list->next != NULL){
		prev = list; 
		list = list->next;
		i++;
	}
	if(prev != NULL)
		list->prev = prev;


	if( list->data == NULL){
		list->data = p;
	}
	else {
		node* tmp = malloc(sizeof(node));
		tmp->data = p;
		tmp->prev = list;
		list->next = tmp;
		list = tmp;
		list->next = NULL;
	}
	free(p);

}

node* removeEntry(node* list){
	char badge[5];
	printf("Entrez le numero de badge du contact : ");
	read(badge, 4);
	int badgeNumber = atoi(badge);
	node* tmp = list;

	if(badgeNumber == 1){
		tmp = list->next;
		tmp->prev = NULL;
		free(list);
	}else{
		for (int i = 0; i < badgeNumber - 1; ++i)
		{
			tmp = tmp->next;
		}
		tmp->prev->next = tmp->next;
		tmp = list;
	}
	return tmp;
}

void changeCode(node* list){
	char badge[5];
	printf("Entrez le numero de badge du contact : ");
	read(badge, 4);
	int badgeNumber = atoi(badge);
	person* modif = findPerson(list, badgeNumber);
	if(modif == NULL){
		printf("\nLa personne demandee n'existe pas\n");
		return;
	}
	printf("Entrez le code pin du contact (4 chiffres) : ");
	read(modif->code, 4);
	printf("Les modifications ont ete enregistrees");
}

void simulate(node* list){
	char badge[5];
	char code[5];
	printf("Entrez le numero de badge du contact : ");
	read(badge, 4);
	int badgeNumber = atoi(badge);
	person* p = findPerson(list, badgeNumber);

	if(p != NULL){	

		printf("Entrez le code pin du contact (4 chiffres) : ");
		read(code, 4);	
		
		if(strcmp(code,p->code) == 0){
			printf("\nAcces autorise :\nUtilisateur : %s %s\n",p->prenom,p->nom);

			time_t timer = time(NULL);
			struct tm *tm = localtime(&timer);
			printf("Acces le : %s\n", asctime(tm));

			p->timestamp = timer;
		}
		else{
			printf("\nAcces non autorise\n");
		}
	}
	else{
		printf("\nLa personne demandee n'existe pas\n");
	}	
}

person* findPerson(node* list, int badgeNumber){
	
	while(list->next != NULL){
		if(list->data->badgeNumber == badgeNumber)
			return list->data;
		list = list->next;
	}
	if(list->data != NULL){
		if(list->data->badgeNumber == badgeNumber)
			return list->data;
	}
	return NULL;
}

void saveToFile(node* list){
	char fileName[64] = "bdd.txt";
	const char * openMode = "w+";
	FILE * file = fopen(fileName,openMode);

	if(fileName == NULL){
		printf("Creation du fichier impossible\n");
		return;
	}

	while(list->next != NULL){	
		fprintf(file,"%s\n",list->data->nom);
		fprintf(file,"%s\n",list->data->prenom);
		fprintf(file,"%s\n",list->data->code);
		fprintf(file,"%d\n",list->data->badgeNumber);
		fprintf(file,"%lld\n",list->data->timestamp); 
		
		list = list->next;
	}
	if(list->data != NULL){
		fprintf(file,"%s\n",list->data->nom);
		fprintf(file,"%s\n",list->data->prenom);
		fprintf(file,"%s\n",list->data->code);
		fprintf(file,"%d\n",list->data->badgeNumber);
		fprintf(file,"%lld\n",list->data->timestamp); 
	}
	
	fclose(file);
	printf("\nFichier sauvegarde dans %s\n",fileName);
}

void loadFromFile(node* list){
	char fileName[64] = "bdd.txt";
	const char * openMode = "r";
	printf("test");

	FILE * file = fopen(fileName,openMode);

	if(file == NULL){
		printf("Lecture du fichier impossible\n");
	}

	char * line = malloc(1024*sizeof(char));
	int cpt = 0;
	while(!feof(file)){
		char c = fgetc(file);
		if(c == '\n'){
			cpt++;
		}
	}

	rewind(file);// Reread the file from the first line
	cpt = 0;
	person* person;

	while (fgets(line, 1024, file) != NULL){

		line[strcspn(line, "\n")] = '\0'; // Remove \n from the
		switch (cpt%5){
			case 0 :
				person = malloc(sizeof(person));
				strcpy(person->nom,line);
				strcpy(person->prenom, line);
				break;
			case 1 :
				strcpy(person->prenom, line);
				break;
			case 2 :
				strcpy(person->code, line);
				break;
			case 3 :
				person->badgeNumber = atoi(line);
				break;
			case 4 :
				person->timestamp = atoi(line);
				newPerson(list,person);
				break;
		}
		printf("cpt %d : %d -->  %s\n",cpt,cpt%5,line);
		line = malloc(1024*sizeof(char));
		cpt ++;	
	}
	printf("Configuration %s importee\n",fileName);
	fclose(file);
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