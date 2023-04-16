#ifndef HACHAGE_H_INCLUDED
#define HACHAGE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50
#define Taille 100

typedef char chaine[N];

typedef struct etudiant
  {
    chaine nom;//ici prit comme cle
    chaine prenom;
    chaine ufr;
    chaine P_etudiant;
    struct etudiant * precedant;
    struct etudiant * suivant;
  }etudiant;

typedef etudiant *ETUDIANT;

ETUDIANT tableHachage[Taille];

short fonctionHachage(ETUDIANT, short);

etudiant * creerEtidiant(chaine, chaine, chaine, chaine);
ETUDIANT saisirUnEtudiant();
void saisirEtudiant(short, short);
void gestionCollision(ETUDIANT, ETUDIANT);

short comparer2Etudiant(ETUDIANT, ETUDIANT);
short accederEtudiantEncasCollision(ETUDIANT, ETUDIANT);
ETUDIANT rechercherEtudiant(ETUDIANT*, ETUDIANT, short);
void afficheEtudiant(ETUDIANT, short, short);
void afficheTableEtudiant(ETUDIANT*, short);


#endif // HACHAGE_H_INCLUDED
