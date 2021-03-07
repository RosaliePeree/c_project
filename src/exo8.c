/*
 ============================================================================
 Name        : exo8.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Ecrire un programme qui récupère le type d’une opération 
 			(/, *, -, +) puis les valeurs de deux opérandes (flottantes) et 
 			qui affiche le résultat. Signaler une erreur de saisie lorsque 
 			le type de l’opération n’est pas défini ou lorsque l‘opération 
 			ne peut être réalisée. Le programme devra boucler jusqu'à qu’un 
 			caractère ‘s’ soit saisi.

 			1 en utilisant des instructions if 
 			2 en utilisant une instruction case
 ============================================================================
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 

int main(void) {
	float first;
	float second;
	char c;

	// Calculator with if...else
	do {
		printf("\nCalculator. Press 's' to exit");
		printf("\nSelect an operation: /, *, -, +");
		c = getch();		
		printf("\nOperation selected: %c", c);
		printf("\nEnter a number (float)");	
		scanf("%f", &first);
		printf("\nEnter a number (float)");	
		scanf("%f", &second);
		if (c == '/')
			printf("\nResult : %f", first / second);
		else
			if (c == '*')	
				printf("\nResult : %f", first * second);
			else 
				if (c == '-')		
					printf("\nResult : %f", first - second);
				else
					if (c == '+')
						printf("\nResult : %f", first + second);				
					else
						printf("\nWrong operation type, try again");
	} while(c != 's');

	// Calculator with switch case
	do {
		printf("\n\n***********************************");
		printf("\nCalculator. Press 's' to exit");
		printf("\nSelect an operation: /, *, -, +");
		c = getch();		
		printf("\nOperation selected: %c", c);
		printf("\nEnter a number (float)");	
		scanf("%f", &first);
		printf("\nEnter a number (float)");	
		scanf("%f", &second);
		switch (c){
			case '/':		
				printf("\nResult : %f", first / second);
				break;
			case '*':
				printf("\nResult : %f", first * second);
				break;
			case '-':
				printf("\nResult : %f", first - second);
				break;
			case '+':
				printf("\nResult : %f", first + second);
				break;
			default:				
				printf("\nWrong operation type, try again");
		}
	} while(c != 's');

	return EXIT_SUCCESS;
}
