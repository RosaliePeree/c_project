/*
 * exo11.c
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
	int X=0;
	char rea[100];
	read(rea, 90);
	X = atoi(rea);
	printf("Enter a second number : \n");
	int N=0;
	read(rea, 90);
	N = atoi(rea);
	if(X<1 || N<0){
		printf("ERROR : Invalid values\n");
	}
	else{
		int pow=1;
		for(int i=0;i<N;i=i+1){
			pow=pow*X;
		}
		printf("%i^%i=%i",X,N,pow);
	}

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
