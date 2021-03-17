/*
 * testdegre2.c
 *
 *  Created on: 9 mars 2021
 *      Author: ycott
 */
#include <stdio.h>
#include <stdlib.h>
#include "degre.h"
#include "read.h"

char tmp[15];

int lireChoix(){
	int choice=7;
	while(choice<0 || choice >6){
		printf("Menu :\n1: Celsius to Fahrenheit\n2: Celsius to Kelvin\n3: Fahrenheit to Celsius\n");
		printf("4: Fahrenheit to Kelvin\n5: Kelvin to Celsius\n6: Kelvin to Fahrenheit\n0: Quit\n");
		read(tmp, 2);	
		choice = atoi(tmp);
	}
	return choice;
}

void executerChoix(int intchoix){
	float value;
	printf("Initial Value :\n");
	read(tmp, 4);	
	value = atof(tmp);
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

int main(void){
	int choice=1;
	while(choice!=0){
		choice=lireChoix();
		if(choice!=0){
			executerChoix(choice);
		}
	}
}


