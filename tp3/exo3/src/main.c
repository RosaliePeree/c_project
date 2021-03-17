#include <stdio.h>
#include <stdlib.h>
#include "exo.h"

int main(){
	int hours;
	int minutes;
	int seconds;
	printf("Hours :");
	scanf("%i",&hours);
	printf("\nMinutes :");
	scanf("%i",&minutes);
	printf("\nSeconds :");
	scanf("%i",&seconds);
	printf("\nTotal : %i seconds\n",horloge(hours,minutes,seconds));
}