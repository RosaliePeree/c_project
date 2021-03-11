/*
 ============================================================================
 Name        : exo2-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Ecrire un programme affiche «Hello world» à l’aide d’une 
 			fonction affiche_hello() en
 			1.Définissant l’entête et le corps de la fonction avant le main
 			2.Définissant l’entête de la fonction avant le main et le corps 
 				de la fonction après le main
 			3.Définissant l’entête et le corps de la fonction dans un 
 				fichier fonction.h
 			4.Définissant  l’entête  de  la  fonction  dans  un  fichier 
 				fonction.h et  le  corps  de  la  fonction  dans  un fichier 
 				fonction.c
 ============================================================================
 */ 

#include <stdio.h>
#include <stdlib.h>

void affiche_hello(){
	printf("%s\n", "Hello world");
}

int main(){
	affiche_hello();
}

