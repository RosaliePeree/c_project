/*
 * exo4.c
 *
 *  Created on: 1 avr. 2021
 *      Author: ycott
 */
#include <stdio.h>
#include <stdlib.h>

void echangerPointeurs(int **ppa, int **ppb)
{
int *tmp;
tmp = *ppa;
*ppa = *ppb;
*ppb = tmp;
}

int main(){
	int x,y;
	int *px, *py;
	x = 12;
	y = 34;
	px=&x;
	py=&y;
	printf("Avant échange : x = %d ; y = %d\n",*px,*py);
	echangerPointeurs(&px,&py);
	printf("Après échange : x = %d ; y = %d\n",*px,*py);
	return EXIT_SUCCESS;
}
