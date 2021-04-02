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
	int X=0;
	char tmp[100];
	read(tmp, 90);
	X = atoi(tmp);
	int somme=0;
	for(int i=1;i<=X;i=i+1){
		somme=somme+i;
	}
	printf("%i\n",somme);
	somme=0;
	for(int i=X;i>0;i=i-1){
		somme=somme+i;
	}
	printf("%i\n",somme);
	somme=0;
	int i=1;
	while(i<=X){
		somme=somme+i;
		i=i+1;
	}
	printf("%i\n",somme);
	somme=0;
	i=X;
	while(i>0){
		somme=somme+i;
		i=i-1;
	}
	printf("%i\n",somme);
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
