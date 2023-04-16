#include<stdio.h>
#include<stdlib.h>
//========================DEFINITION DES STRUCTURES============
typedef struct Point
    {
        float x;
        float y;
        struct Point *suiv;
    }Point;
typedef Point *Courbe;
typedef struct
    {
        Courbe tete;
        Courbe queu;
        short taille;
    }FilePoint;
typedef struct
    {
        Courbe sommet;
        short taille;
     }PilePoint;

 //======================CREER POINT ET COURBE=====================
Point* creerPoint(float,float);
Courbe creerCourbe(short);
void afficheCourbe(Courbe);
//==================INSERER EN TETE-QUEUE-POSITION==================
Courbe insererEnTeteCourbe(Courbe,float,float);
Courbe insererEnQueuCourbe(Courbe,float,float);
Courbe insererEnPositionCourbe(Courbe,float,float,short);

//==================SUPPRIMER EN TETE-QUEUE-POSITION================
Courbe supprimerEnTeteCourbe(Courbe);
Courbe supprimerEnQueuCourbe(Courbe);
Courbe supprimerEnPositionCourbe(Courbe,short);
//=========================PILES====================================

short pileVideTest(PilePoint);
Courbe pileSommet(PilePoint);
PilePoint empiler(PilePoint,float,float);
PilePoint depiler(PilePoint);
void initialiserPile(PilePoint);
PilePoint saisirPile(short);
void afficherPile(PilePoint);

//==========================FILES====================================


short fileVideTest(FilePoint);
Courbe fileTete(FilePoint);
void initialiserFile(FilePoint);
FilePoint enfiler(FilePoint,float,float);
FilePoint defiler(FilePoint);
FilePoint saisirFile(short);
void afficherFile(FilePoint);
