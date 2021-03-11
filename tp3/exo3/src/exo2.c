/*
 * exo2.c
 *
 *  Created on: 9 mars 2021
 *      Author: ycott
 */
#include <stdio.h>
#include <stdlib.h>

int horloge(int hours, int minutes, int seconds){
	return hours*3600+minutes*60+seconds;
}

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

