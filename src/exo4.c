/*
 ============================================================================
 Name        : exo2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Ecrire un programme qui réalise les calculs suivants et qui affiche chacune 
 des valeurs de la variable entière X
 X = -3 + 4 * 5 –6
 X = (-3 + 4) * 5 –6
 X = -3 + (4 * 5) –6
 X = -3 + 4 * (5 –6)
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int X = -3+4*5-6;
	printf("X = -3 + 4 * 5 - 6 = ");
	printf("%d\n", X);
	X = (-3+4)*5-6;
	printf("X = (-3 + 4) * 5 - 6 = ");
	printf("%d\n", X);
	X = -3+(4*5)-6;
	printf("X = -3 + (4 * 5) - 6 = ");
	printf("%d\n", X);
	X = -3+4*(5-6);
	printf("X = -3 + 4 * (5 - 6) = ");
	printf("%d\n", X);
	return EXIT_SUCCESS;
}