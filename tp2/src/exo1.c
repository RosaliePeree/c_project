/*
 * exo1.c
 *
 *  Created on: 8 mars 2021
 *      Author: Cottin Yohan
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void square(int);
void rightTri(int);
void leftTri(int);
void upTri(int);
void diamond(int);
void emptyBuffer();
int read(char*, int);

int main(void) {
	int X=0;	
	char tmp[4];
	while(X<1){
		printf("Enter a number (nn) :\n");
		read(tmp, 3);	
		X = atoi(tmp);
	}
	int shape=0;
	while(shape>5 || shape<1){
		printf("Choose a shape:\n1: square\n2: right triangle\n3: left triangle\n4: triangle\n5: diamond\n");
		read(tmp, 2);	
		shape = atoi(tmp);
	}
	switch(shape){
	case 1:
		square(X);
		break;
	case 2:
		rightTri(X);
		break;
	case 3:
		leftTri(X);
		break;
	case 4:
		upTri(X);
		break;
	case 5:
		diamond(X);
		break;
	}
	return EXIT_SUCCESS;
}

void square(int X){
	for (int Y=0;Y<X;Y=Y+1){
		for(int i=0;i<X;i=i+1){
			printf("*");
		}
		printf("\n");
	}
}

void rightTri(int X){
	for (int Y=0;Y<X;Y=Y+1){
		for(int i=0; i<=Y;i=i+1){
			printf("*");
		}
		printf("\n");
	}
	for (int Y=1;Y<X;Y=Y+1){
			for(int i=0; i<X-Y;i=i+1){
				printf("*");
			}
			printf("\n");
		}
}

void leftTri(int X){
	for (int Y=1;Y<=X;Y=Y+1){
		for(int i=0; i<X-Y;i=i+1){
			printf(" ");
		}
		for(int i=0; i<Y;i=i+1){
					printf("*");
				}
		printf("\n");
	}
	for (int Y=1;Y<X;Y=Y+1){
		for(int i=0; i<Y;i=i+1){
			printf(" ");
		}
		for(int i=0; i<X-Y;i=i+1){
			printf("*");
		}
		printf("\n");
	}
}

void upTri(int X){
	for (int Y=1;Y<=X;Y=Y+1){
		for(int i=0; i<X-Y;i=i+1){
			printf(" ");
		}
		for(int i=1; i<Y*2;i=i+1){
			printf("*");
		}
		printf("\n");
	}
}

void diamond(int X){
	upTri(X);
	for(int Y=1;Y<X;Y=Y+1){
		for(int i=0;i<Y;i=i+1){
			printf(" ");
		}
		for(int i=1;i<(X-Y)*2;i=i+1){
			printf("*");
		}
		printf("\n");
	}
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