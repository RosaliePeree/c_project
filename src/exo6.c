/*
 ============================================================================
 Name        : exo3.c
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

	//
	printf("5 & 6 : ");
	X = 5 & 6;
	printf("%f", X); 

	//
	printf("\n5 && 6 : ");
	X = 5 && 6;
	printf("%f", X); 

	//
	printf("\n5 | 6 : ");
	X = 5 | 6;
	printf("%f", X); 

	//
	printf("\n5 || 6 : ");
	X = 5 || 6;
	printf("%f", X); 

	//
	printf("\n5 ^ 6 : ");
	X = 5 ^ 6;
	printf("%f", X); 

	//
	printf("\n5 ^ 6 : ");
	X = 5 ^^ 6;
	printf("%f", X); 

	//
	printf("\n~5 : ");
	X = ~5;
	printf("%f", X); 

	//
	printf("\n!5 : ");
	X = !5;
	printf("%f", X); 

	return EXIT_SUCCESS;
}
