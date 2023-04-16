#include"table_hachage.h"
Mot* creerMot(Chaine chaine,short cle)
    {
        Mot* ch;
        ch = (Mot*)malloc(sizeof(Mot));
        ch->mot = chaine;
        ch->cle = cle;
        ch->suiv = NULL;
        ch->prec =NULL;
        return ch
    }
ListeMot creerListeMot(short nblisteMot)
    {
        ListeMot listeMot;
        Chaine chaine;

    }
void afficherListeMot(ListeMot);
int hachage(Mot);


