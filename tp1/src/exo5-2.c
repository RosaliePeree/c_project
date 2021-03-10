/*
 ============================================================================
 Name        : exo5.2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Ecrire un programme qui réalise les calculs suivants et qui
 			affiche chacune des valeurs: 
 			de la variable entière X = 5 % 2
 			de la variable flottante X = 5.0 % 2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {	
	int X;
	//le calcul de deux int donne un int (arrondi), qui transformé en float sera juste un int avec des 0s après la virgule
	X = 5 % 2;
	printf("la variable entiere X = 5 mod 2 : %d", X);

	//l'opérateur % est un opérateur entier, on en peux pas l'appliquer sur un float
	printf("\nla variable flottante X = 5.0 mod 2 : ");
	printf("impossible d'effectuer un modulo sur un float ou un double.");
	
	return EXIT_SUCCESS;
}
