/*
 ============================================================================
 Name        : exo7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Ecrire un programme qui récupère la valeur flottante du rayon d’un cercle et 
 			qui en affiche le périmètre et la surface. La constante PI aura la valeur 
 			3.14159
 ============================================================================
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void emptyBuffer();
 
int read(char *chain, int length);

int main(void) {
	const float PI = 3.14159;
	printf("Enter the radius \n");
	float X=0.0;
	char tmp[15];
	read(tmp, 14);	
	X = atof(tmp);
	float perimeter=2*X*PI;
	float area=PI*X*X;
	printf("Perimeter : %f, Area : %f",perimeter,area);
	
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