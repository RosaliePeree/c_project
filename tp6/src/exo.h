#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
	char nom[20];
	char prenom[20];
	int badgeNumber;
	char code[4];
	time_t timestamp;
} person;

/* Node of a doubly linked list */
typedef struct node {
    person* data;
    struct node* next; // Pointer to next node in DLL
    struct node* prev; // Pointer to previous node in DLL
} node;

void display(node* list);

node* removeEntry(node*);
void newEntry(node*);
int displayMenu();
void saveToFile(node*);
void loadFromFile(node*);
void simulate(node* list);
void changeCode(node* list);

person* findPerson(node* list, int badgeNumber);

int read(char*, int);
void emptyBuffer();