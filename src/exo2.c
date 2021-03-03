/*
 ============================================================================
 Name        : exo2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int X = -3+4*5-6;
	printf("%d\n", X);
	X = (-3+4)*5-6;
	printf("%d\n", X);
	X = -3+(4*5)-6;
	printf("%d\n", X);
	X = -3+4*(5-6);
	printf("%d\n", X);
	return EXIT_SUCCESS;
}