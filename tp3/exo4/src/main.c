/*
 ============================================================================
 Name        : exo4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Ecrire un programme qui à l’aide d’une fonction compare(...) 
 			compare deux entiers fournis par l’utilisateur et qui retourne:
 			
 			1.La valeur entière 1 si les entiers sont égaux, 0 sinon
 			2.Le caractère V si les entiers sont égaux, F sinon.

 			Même question avec la comparaison de deux flottants.
 			Le programme principal devra afficher la valeur retournée par la 
 			fonction.
 ============================================================================
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exo.h"

void emptyBuffer();
 
int read(char*,int);

int main(){
	char tmp[15];
	int first, second;
	printf("\nEnter an integer (14 char)");
	read(tmp, 14);	
	first = atoi(tmp);
	printf("\nEnter an integer (14 char)");
	read(tmp, 14);	
	second = atoi(tmp);
	printf("\nCompare : %d", compareInt1(first, second));
	printf("\nCompare : %c", compareInt2(first, second));


	int third, fourth;
	printf("\nEnter a float (14 char)");
	read(tmp, 14);	
	third = atof(tmp);
	printf("\nEnter a float (14 char)");
	read(tmp, 14);	
	fourth = atoi(tmp);
	printf("\nCompare : %d", compareFloat1(third, fourth));
	printf("\nCompare : %c", compareFloat2(third, fourth));
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