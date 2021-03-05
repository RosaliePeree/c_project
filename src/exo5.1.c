/*
 ============================================================================
 Name        : exo5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Ecrire un programme qui réalise les calculs suivants et qui
 			affiche chacune des valeurs: 
 			de la variable flottante puis entière X = 10 / 3
 			de la variable flottante X = 10.0 / 3
 			de la variable flottante X = 10.0 / 3.0
 			de la variable flottante X = (float) 10 / 3 
 			de la variable flottante X = ((float) 10) / 3
 			de la variable flottante X = ((float) 10) /3 (affichage avec 1 puis 5 chiffres avec la virgule)

 			Expliquer les différences 
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {	
	float X;
	//le calcul de deux int donne un int (arrondi), qui transformé en float sera juste un int avec des 0s après la virgule
	printf("la variable flottante X = 10 / 3 : ");
	X = 10 / 3;
	printf("%f", X); 

	//le calcul de deux int donne un int arrondi.
	printf("\nla variable entiere X = 10 / 3 : ");
	int Y;
	Y = 10 / 3;
	printf("%d", Y);
	
	//le calcul contient un float et, le float étant plus "fort" que le int, ce dernier prend précédence sur le calcul et le 3 est considéré comme un 3.0
	printf("\nla variable flottante X = 10.0 / 3 : ");
	X = 10.0 / 3;
	printf("%f", X);
	
	//le calcul de deux floats
	printf("\nla variable flottante X = 10.0 / 3.0 : ");
	X = 10.0 / 3.0;
	printf("%f", X);
	
	//le calcul contient un float casté et, le float étant plus "fort" que le int, ce dernier prend précédence sur le calcul et le 3 est considéré comme un 3.0
	printf("\nla variable flottante X = (float) 10 / 3 : ");
	X = (float)10 / 3;
	printf("%f", X);
	
	//le calcul contient un float casté et, le float étant plus "fort" que le int, ce dernier prend précédence sur le calcul et le 3 est considéré comme un 3.0
	printf("\nla variable flottante X = ((float) 10) / 3 : ");
	X = ((float)10) / 3;
	printf("%f", X);

	//le calcul contient un float casté et, le float étant plus "fort" que le int, ce dernier prend précédence sur le calcul et le 3 est considéré comme un 3.0
	printf("\nlavariable flottante X = ((float) 10) /3 (affichage avec 1 chiffre avec la virgule) : ");
	X = ((float)10) / 3;
	printf("%.1f", X);

	//le calcul contient un float casté et, le float étant plus "fort" que le int, ce dernier prend précédence sur le calcul et le 3 est considéré comme un 3.0
	printf("\nla variable flottante X = ((float) 10) /3 (affichage avec 5 chiffres avec la virgule) : ");
	X = ((float)10) / 3;
	printf("%.5f", X);

	return EXIT_SUCCESS;
}
