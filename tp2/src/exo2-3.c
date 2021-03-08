/*
 ============================================================================
 Name        : exo2-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : On dispose de N=30 valeurs numériques que l’on désire classer 
 			par ordre croissant (on aurait pu choisir décroissant). Chacune de 
 			ces valeurs sera choisie aléatoirement dans l’intervalle [0;50] 
 			et placée dans un tableau TAB de taille N. Faites 3 programmes qui 
 			effectuent les 3 méthodes de tri suivantes et affichent à l’écran 
 			le tableau TAB en ligne puis en dessous le tableau TAB trié:

 			1)Tri bulles
 			On compare les couples de valeurs TAB[i] et TAB[i+1] pour i variant 
 			de 0 à N-2: Si TAB[i]>TAB[i+1], on les permute. L’algorithme s’arrête 
 			quand il n’y a plus de permutations à effectuer: le tableau TAB est
 			alors trié.

 			2)Tri par recherche des minima successifs
 			Dans un premier passage, on recherche le minimum du tableau TAB 
 			que l’on permute avec TAB[0] Puis sur les N-1 éléments restants, 
 			on cherche le deuxième minimum que l’on permute avec TAB[1].Etc...

 			3)Tri par insertion
 			Insérer une valeur V à la place j d’un tableau déjà trié consiste 
 			à décaler vers la droite tous les éléments du tableau à partir de 
 			la place i puis à faire T[j]=V.Pour  trier  le  tableau  TAB,  il  
 			suffit  alors  d’insérer  TAB[i]  dans  les  i-1  premiers éléments 
 			déjà triés et placé dans un autre tableau, ceci pour i variant de 
 			1 à N-1.
 ============================================================================
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


void swap(int *a, int *b){
	*a = *a - *b;
	*b = *a + *b;
	*a = *b - *a;
}


/*3)Tri par insertion
	Insérer une valeur V à la place j d’un tableau déjà trié consiste 
	à décaler vers la droite tous les éléments du tableau à partir de 
	la place i puis à faire T[j]=V.Pour  trier  le  tableau  TAB,  il  
	suffit  alors  d’insérer  TAB[i]  dans  les  i-1  premiers éléments 
	déjà triés et placé dans un autre tableau, ceci pour i variant de 
	1 à N-1.
*/
void triInsert(int *tab, int size){	
 	int i = 1;
	while (i < size) {
    	int j = i;
    	while (j > 0 && tab[j-1] > tab[j]){
        	swap(&tab[j-1], &tab[j]);
        	j--;
        }
        i++;
   	}
}

void print(int *tab, int size){
	printf("[");
	for(int i=0;i<size;i=i+1){
		printf("%i",tab[i]);
		if (i+1<size){
			printf(";");
		}
	}
	printf("]\n");
}

int main(void) {
  	// Use current time as
    // seed for random generator
    srand(time(0));
	int N=30;
	int TAB[N];
	for (int i = 0; i < N; ++i)
	{
		TAB[i]=rand()%51;
	}
	print(TAB, N);

	triInsert(TAB, N);

	print(TAB, N);

	return EXIT_SUCCESS;
}
