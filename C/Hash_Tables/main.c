#include "HACHAGE.h"

int main()
{
    int nombreEtudiant,indiceRechercher;
    ETUDIANT etuRechercher;
    printf("Donnez le nombre d'etudiant a saisir:\n");
    scanf("%d",&nombreEtudiant);
    saisirEtudiant(nombreEtudiant,Taille);
    afficheTableEtudiant(tableHachage, Taille);
    printf("Donnez l'etudiant a rechercher\n");
    etuRechercher = saisirUnEtudiant();
    if(rechercherEtudiant(tableHachage,etuRechercher,Taille) == NULL)
    {
       printf(" L'etudiant n'est pas dans la table\n");
    }
    else
    {   indiceRechercher = fonctionHachage(etuRechercher,Taille);
        afficheEtudiant(rechercherEtudiant(tableHachage,etuRechercher,Taille),indiceRechercher,Taille );
    }
    return 0;
}
