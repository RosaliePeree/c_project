/*
 * exo2.c
 *
 *  Created on: 8 mars 2021
 *      Author: ycott
 */

#include <stdio.h>
#include <stdlib.h>

void triSelect(int * tab, int size){
	for(int i=0;i<size-1;i=i+1){
		int index=i;
		for(int j=i;j<size;j=j+1){
			if(tab[j]<tab[index]){
				index=j;
			}
		}
		int tmp=tab[i];
		tab[i]=tab[index];
		tab[index]=tmp;
	}
	printf("[");
	for(int i=0;i<size;i=i+1){
			printf("%i",tab[i]);
			if (i+1<size){
				printf(";");
			}
		}
		printf("]\n");
}

int main(void) {
	int N=10;
	int tab[N];
	printf("[");
	for(int i=0;i<N;i=i+1){
		tab[i]=rand()%51;
		printf("%i",tab[i]);
		if (i+1<N){
			printf(";");
		}
	}
	printf("]\n");

	triSelect(tab, N);
}
