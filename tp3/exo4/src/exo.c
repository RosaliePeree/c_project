#include "exo.h"

int compareInt1(int a, int b){
	if (a == b)
		return 1;
	return 0;
}

char compareInt2(int a, int b){
	if (a == b)
		return 'V';
	return 'F';
}

int compareFloat1(float a, float b){
	if (a == b)
		return 1;
	return 0;
}

char compareFloat2(float a, float b){
	if (a == b)
		return 'V';
	return 'F';
}