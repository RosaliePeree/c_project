/*
* TP 5 : Pointeurs
*
* insuffisance des appels de fonction
* avec passage par valeur
*/
#include <stdio.h>
void echanger(int * pa, int * pb)
{
int tmp;
tmp = *pa;
*pa = *pb;
*pb = tmp;
}
void main()
{
int x,y;
x = 12;
y = 34;
printf("Avant échange : x = %d ; y = %d\n",x,y);
echanger(&x,&y);
printf("Après échange : x = %d ; y = %d\n",x,y);
}
