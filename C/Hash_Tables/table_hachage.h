#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char Chaine[40]
typedef struct Mot
    {
        Chaine mot;
        short cle;
        struct Mot *suiv;
        struct Mot *prec;
    }Mot;
typedef Mot *ListeMot;
typedef listeMot HACHAGE[100];
Mot* creerMot(chaine,short);
ListeMot creerListeMot(short);
void afficherListeMot(ListeMot);
int hachage(Mot);

void afficherMot(Mot);
listeMot insererEnTeteMot(listeMot,chaine,short);
listeMot insererEnQueueMot(listeMot,chaine,short);


