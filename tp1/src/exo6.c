/*
 ============================================================================
 Name        : exo6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Ecrire un programme qui réalise les calculs suivants et qui affiche 
 				chacune des valeurs: 
 				5 & 6
 				5 && 6
 				5 | 6
 				5 || 6
 				5 ^ 6
 				5 ^^ 6
 				~5
 				! 5

 				Expliquer les résultats obtenus
 ============================================================================
 */ 

#include <stdio.h>
#include <stdlib.h>

int main(void) {	
	float X;

	//opérateur bit à bit AND
	printf("5 & 6 : ");
	X = 5 & 6;
	printf("%f", X); 

	//opérateur logique AND
	printf("\n5 && 6 : ");
	X = 5 && 6;
	printf("%f", X); 

	//opérateur bit à bit OR
	printf("\n5 | 6 : ");
	X = 5 | 6;
	printf("%f", X); 

	//opérateur logique OR
	printf("\n5 || 6 : ");
	X = 5 || 6;
	printf("%f", X); 

	//opérateur bi à bit XOR
	printf("\n5 ^ 6 : ");
	X = 5 ^ 6;
	printf("%f", X); 

	printf("\n5 ^^ 6 : ");
	printf("cet operateur n'est pas un operateur valable en C"); 

	//opérateur bit a bit not
	printf("\n~5 : ");
	X = ~5;
	printf("%f", X); 

	//opérateur logique not
	printf("\n!5 : ");
	X = !5;
	printf("%f", X); 

	return EXIT_SUCCESS;
}
