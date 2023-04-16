#include "Liste_Chainerbis.h"
Pointbis* creerPointbis(float abs,float ord)
{
    Pointbis* p;
    p  = (Pointbis*)malloc(sizeof(Pointbis));
    p->x = abs;
    p->y = ord;
    p->suiv = NULL;
    p->prec = NULL;
    return p;
}

Courbebis creerCourbebis(short n)
{
    Pointbis* maillon;
    Pointbis* debut;
    Pointbis* courant;
    short i;
    float a,b;
    if(n >= 1)
    {
        printf("donez abs et ord");
        scanf("%2f %2f",&a ,&b);
        maillon = creerPointbis(a,b);
        debut = courant = maillon;
        for(i=1;i<n;i++)
        {
            printf("donez abs et ord");
            scanf("%2f %2f",&a ,&b);
            maillon = creerPointbis(a,b);
            courant->suiv = maillon;
            maillon->prec =  courant;
            courant = courant->suiv;
        }
        return debut;
    }
    else return NULL;
}


void afficheCourbebis(Courbebis c)
{
    Courbebis courant = c;
    while(courant->suiv !=NULL)
    {
        printf("%f %f\n",courant->x,courant->y);
        courant = courant->suiv;
    }
    courant = courant->prec;
    while( courant->prec != NULL)
    {
        printf("%f %f\n",courant->x,courant->y);
        courant = courant->prec;
    }
}

Courbebis insererEnTeteCourbebis(Courbebis c,float a,float b)
{
    Pointbis* maillon = creerPointbis(a,b);
    Pointbis* courant;
    if(c)
    {
     courant->prec = maillon;
     maillon->suiv = c;
                 c = maillon ;
    }
    else c = maillon;
    return c;
}
Courbebis insererEnQueuCourbebis(Courbebis c,float a,float b)
{
    Courbebis maillon = creerPointbis(a,b);
    Courbebis  courant = c;
    if(c!=NULL)
    {
        while(courant->suiv!=NULL)
            courant = courant->suiv;
        maillon->prec =courant;
        courant->suiv = maillon;

    }
    else c = maillon;
    return c;
}


Courbebis insererEnPositionCourbebis(Courbebis c,float a,float b,short i)
{   Courbebis maillon = creerPointbis(a,b);
    Courbebis  courant = c;
    Courbebis  p;
    short j;
    if(c!=NULL)
    {
        for(j=1;j<i;j++)
            courant = courant->suiv ;
        p =  courant->suiv;
        maillon->suiv  = p;
        maillon->prec = courant;
        courant->suiv = maillon ;
        p->prec  = maillon;
    }
    else c = maillon;
    return c;
}

Courbebis supprimerEnTeteCourbebis(Courbebis c)
{   Courbebis tete = c;
    if(c!=NULL)
    { tete = c->suiv;
        if(tete!=NULL)
            tete->prec = NULL;

      free(c);
    }
    return tete;
}



Courbebis supprimerEnQueuCourbebis(Courbebis c)
{
     Courbebis courant = c;
     if(c!=NULL)
     {  while(courant->suiv!=NULL)
            courant = courant->suiv;
        Courbebis precedent = courant->prec;
        precedent->suiv = NULL;
        free(courant);
     }
     return c;
}
Courbebis supprimerEnPositionCourbebis(Courbebis c,short i)
{
    short j;
     Courbebis a,b;
     a = c;
     for(j=1;j<i;j++)
         a = a->suiv;
     b = a->suiv;
     a->suiv =  b->suiv;
     (b->suiv)->prec = a;
     free(b);
     return c;
}
