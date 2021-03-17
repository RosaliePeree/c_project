#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exo.h"


void emptyBuffer();
 
int read(char*,int);

int main(){
	int hours;
	int minutes;
	int seconds;
	char tmp[15];
	printf("Hours :");
	read(tmp, 14);	
	hours = atoi(tmp);
	printf("\nMinutes :");
	read(tmp, 14);	
	minutes = atoi(tmp);
	printf("\nSeconds :");
	read(tmp, 14);	
	seconds = atoi(tmp);
	printf("\nTotal : %i seconds\n",horloge(hours,minutes,seconds));
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