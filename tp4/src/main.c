#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exo.h"

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
