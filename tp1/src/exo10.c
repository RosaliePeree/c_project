/*
 * exo1.c
 *
 *  Created on: 17 mars 2021
 *      Author: ycott
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void emptyBuffer();

int read(char *chain, int length);

int main(void) {
	printf("Enter a number : \n");
	int A=0;
	char rea[100];
	read(rea, 90);
	A = atoi(rea);
	printf("Enter a second number : \n");
	int B=0;
	read(rea, 90);
	B = atoi(rea);

	if(A<B){
		int tmp=A;
		A=B;
		B=tmp;
	}
	while(A%B!=0){
		int tmp=A%B;
		if(tmp>B){
			A=tmp;
		}
		else{
			A=B;
			B=tmp;
		}
	}
	printf("PGCD : %i",B);
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
