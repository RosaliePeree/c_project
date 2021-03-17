#include "degre.h"

float CelsiusAKelvin(float cels){
	return cels+273;
}

float CelsiusAFahrenheit(float cels){
	return (cels*9/5)+32;
}

float FahrenheitACelsius(float fahr){
	return (fahr-32)*5/9;
}

float FahrenheitAKelvin(float fahr){
	return CelsiusAKelvin(FahrenheitACelsius(fahr));
}

float KelvinACelsius(float kelv){
	return kelv-273;
}

float KelvinAFahrenheit(float kelv){
	return CelsiusAFahrenheit(KelvinACelsius(kelv));
}
