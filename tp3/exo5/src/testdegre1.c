/*
 * testdegre1.c
 *
 *  Created on: 9 mars 2021
 *      Author: ycott
 */
#include <stdio.h>
#include <stdlib.h>
#include "degre.h"

int main(){
	printf(" 15 Celsius equals %f Fahrenheit\n",CelsiusAFahrenheit(15.0));
	printf(" 15 Fahrenheit equals %f Celsius\n",FahrenheitACelsius(15.0));
	printf(" 15 Celsius equals %f Kelvin\n",CelsiusAKelvin(15.0));
	printf(" 15 Fahrenheit equals %f Kelvin\n",FahrenheitAKelvin(15.0));
	printf(" 15 Kelvin equals %f Fahrenheit\n",KelvinAFahrenheit(15.0));
	printf(" 15 Kelvin equals %f Celsius\n",KelvinACelsius(15.0));
}
