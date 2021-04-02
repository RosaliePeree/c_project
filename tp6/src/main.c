#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exo.h"

int main(){

	node * list = malloc(sizeof(node));
	node *tmp = malloc(sizeof(node));
	list->next = NULL;
	list->data = NULL;
	list->prev = NULL;

	display(list);
	if(!list){
		printf("ERREUR : impossibile d'initialiser list");
		return 1;
	}
	int choix=-1;
	while(choix!=0){
		choix=displayMenu();
		switch(choix){
		case 0:
			break;
		case 1:
			display(list);
			break;
		case 2:
			newEntry(list);
			break;
		case 3:
			tmp = removeEntry(list);
			list = tmp;
			break;
		case 4:
			changeCode(list);
			break;
		case 5:
			simulate(list);
			break;
		case 6:
			saveToFile(list);
			break;
		case 7:
			printf("testfunct");
			loadFromFile(list);
			printf("testfunt2");
			break;
		}
	}
}
