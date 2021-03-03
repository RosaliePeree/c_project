/*
 ============================================================================
 Name        : exo1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	const float PI = 3.14159;
	printf("Enter the radius \n");
	float X=0.0;
	scanf("%f",&X);
	float perimeter=2*X*PI;
	float area=PI*X*X;
	printf("Perimeter : %f, Are : %f",perimeter,area);
	
	return EXIT_SUCCESS;
}