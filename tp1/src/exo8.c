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
#include <string.h>

void emptyBuffer();

int read(char *chain, int length);

int main(void) {
	float first;
	float second;
	char c;

	// Calculator with if...else
	do {
		printf("\nCalculator. Press 's' to exit");
		printf("\nSelect an operation: /, *, -, +");
		char tmp[15];
		read(tmp, 1);	
		c = tmp[0];
		printf("\nOperation selected: %c", c);
		printf("\nEnter a number (float)");	
		read(tmp, 14);	
		first = atof(tmp);	
		printf("\nEnter a number (float)");	
		read(tmp, 14);	
		second = atof(tmp);
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
		char tmp[15];
		read(tmp, 1);	
		c = tmp[0];	
		printf("\nOperation selected: %c", c);
		printf("\nEnter a number (float)");	
		read(tmp, 14);	
		first = atof(tmp);	
		printf("\nEnter a number (float)");	
		read(tmp, 14);	
		second = atof(tmp);
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



void emptyBuffer(){
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}
 
int read(char *chain, int length)
{
    char *entry = NULL;
 
    if (fgets(chain, length, stdin) != NULL)
    {
        entry = strchr(chain, '\n');
        if (entry != NULL)
        {
            *entry = '\0';
        }
        else
        {
            emptyBuffer();
        }
        return 1;
    }
    else
    {
        emptyBuffer();
        return 0;
    }
}