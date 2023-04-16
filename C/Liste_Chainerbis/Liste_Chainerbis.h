#include<stdio.h>
#include<stdlib.h>
typedef struct Pointbis
{
    float x;
    float y;
    struct Pointbis *suiv;
    struct Pointbis *prec;

}Pointbis;
typedef Pointbis *Courbebis;
Pointbis* creerPointbis(float,float);
Courbebis creerCourbebis(short);
void afficheCourbebis(Courbebis);
Courbebis insererEnTeteCourbebis(Courbebis,float,float);
Courbebis insererEnQueuCourbebis(Courbebis,float,float);
Courbebis insererEnPositionCourbebis(Courbebis,float,float,short);
Courbebis supprimerEnTeteCourbebis(Courbebis);
Courbebis supprimerEnQueuCourbebis(Courbebis);
Courbebis supprimerEnPositionCourbebis(Courbebis,short);


