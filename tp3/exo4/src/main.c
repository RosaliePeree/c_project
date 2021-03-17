/*
 ============================================================================
 Name        : exo4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Ecrire un programme qui à l’aide d’une fonction compare(...) 
 			compare deux entiers fournis par l’utilisateur et qui retourne:
 			
 			1.La valeur entière 1 si les entiers sont égaux, 0 sinon
 			2.Le caractère V si les entiers sont égaux, F sinon.

 			Même question avec la comparaison de deux flottants.
 			Le programme principal devra afficher la valeur retournée par la 
 			fonction.
 ============================================================================
 */ 

#include <stdio.h>
#include <stdlib.h>
#include "exo.h"

int main(){
	int first, second;
	printf("\nEnter an integer");
	scanf("%d", &first);
	printf("\nEnter an integer");
	scanf("%d", &second);
	printf("\nCompare : %d", compareInt1(first, second));
	printf("\nCompare : %c", compareInt2(first, second));


	int third, fourth;
	printf("\nEnter a float");
	scanf("%d", &third);
	printf("\nEnter a float");
	scanf("%d", &fourth);
	printf("\nCompare : %d", compareFloat1(third, fourth));
	printf("\nCompare : %c", compareFloat2(third, fourth));
}