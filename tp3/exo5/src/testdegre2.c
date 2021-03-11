/*
 * testdegre2.c
 *
 *  Created on: 9 mars 2021
 *      Author: ycott
 */
#include <stdio.h>
#include <stdlib.h>
#include "degre.h"

int lireChoix(){
	int choice=7;
	while(choice<0 || choice >6){
		printf("Menu :\n1: Celsius to Fahrenheit\n2: Celsius to Kelvin\n3: Fahrenheit to Celsius\n");
		printf("4: Fahrenheit to Kelvin\n5: Kelvin to Celsius\n6: Kelvin to Fahrenheit\n0: Quit\n");
		scanf("%i", &choice);
	}
	return choice;
}

void executerChoix(int intchoix){
	float value;
	printf("Initial Value :\n");
	scanf("%f",&value);
	switch(intchoix){
	case 1:
		value=CelsiusAFahrenheit(value);
		break;
	case 2:
		value=CelsiusAKelvin(value);
		break;
	case 3:
		value=FahrenheitACelsius(value);
		break;
	case 4:
		value=FahrenheitAKelvin(value);
		break;
	case 5:
		value=KelvinACelsius(value);
		break;
	case 6:
		value=KelvinAFahrenheit(value);
		break;
	}
	printf("Result : %f\n",value);
}
void main(){
	int choice=1;
	while(choice!=0){
		choice=lireChoix();
		if(choice!=0){
			executerChoix(choice);
		}
	}
}
