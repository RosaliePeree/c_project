/*
 ============================================================================
 Name        : exo12.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Ecrire un programme qui récupère un texte qui se termine par le 
 			caractère ‘#’ et qui affiche le nombre de voyelle qu’il contient
 ============================================================================
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 

int main(void) {
	char c;
	char str[200];
	int i = 0;

	// Get the array of text 
	do {
		if (i > sizeof(str) - 1)
			return EXIT_FAILURE;
		c = getch();
		if (c != '#')
			printf("%c",c);
		str[i++] = c;
	} while(c != '#');

	// Count the vowels
	int count = 0;
	for (i = 0; i < sizeof(str) - 1; i++){
		switch (str[i]){
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'y':
				count ++;
			break;
		}
	}

	// Display the results
	if (count != 1){
		printf("\nThere are %d vowels in this sentence", count);
	} else {		
		printf("\nThere is %d vowel in this sentence", count);
	}
	return EXIT_SUCCESS;
}
