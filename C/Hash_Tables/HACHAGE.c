#include "HACHAGE.h"

  //Definton de notre fonction de hachage
short fonctionHachage(ETUDIANT etu, short nMax)
  {
    short i;
    short  nombreHache = 0;
    for (i = 0 ; etu->nom[i] != '\0' ; i++)
      {
        nombreHache += etu->nom[i];
      }
    nombreHache %= nMax;
    return nombreHache;
  }


  // Cree une entree(etudiant)
ETUDIANT creerEtudiant(chaine nom, chaine prenom, chaine ufr,chaine P_etudiant)
  {
    etudiant *etu = (etudiant*)malloc(sizeof(etudiant));
    if (etu == NULL)
      {
        exit(EXIT_FAILURE);
      }
    strcpy(etu->nom, nom);
    strcpy(etu->prenom, prenom);
    strcpy(etu->ufr, ufr);
    strcpy(etu->P_etudiant, P_etudiant);
    etu->precedant = NULL;
    etu->suivant = NULL;
    return etu;
  }




ETUDIANT saisirUnEtudiant()
    {
        chaine nom;
        chaine prenom;
        chaine ufr;
        chaine P_etudiant;

        printf("\nDonner le nom de l'etudiant\n");
        scanf("%s", nom);
        getchar();
        printf("Donner le prenom de l'etudiant\n");
        scanf("%s", prenom);
        getchar();
        printf("Donner l'urf de l'etudiant\n");
        scanf("%s", ufr);
        getchar();
        printf("Donner le P de l'etudiant\n");
        scanf("%s", P_etudiant);
        getchar();

        return creerEtudiant(nom, prenom, ufr, P_etudiant);
    }



  //Saisir les entrees dans la table de hachage
void saisirEtudiant(short n, short nMax)
  {
    etudiant * etuCourant;
    short i, hache;

    if (n < 1 || n>nMax)
      {
        exit(EXIT_FAILURE);
      }
    else
      {
        for (i = 0; i < n; i++)
          {
            printf("\n\nSaisir etudiant %d\n", i+1);
            etuCourant = saisirUnEtudiant();

            if (etuCourant == NULL)
              {
                exit(EXIT_FAILURE);
              }
            hache = fonctionHachage(etuCourant, nMax);
            if (tableHachage[hache ] == NULL)
              {
                tableHachage[hache] = etuCourant;
              }
            else
              {
                gestionCollision(tableHachage[hache], etuCourant);
              }

          }
      }
      printf("\n\n");
  }



  //En cas de collision on stock les entrees ayant le meme hache dans une liste doublement chainee
void gestionCollision(ETUDIANT etu, ETUDIANT nouveauEtu)//Inserer a la fin de la liste en cas de collision
    {
      etudiant * etuCourant;
      etuCourant = etu;
      if(etu != NULL)
        {
          while (etuCourant->suivant != NULL)
            {
              etuCourant = etuCourant->suivant;
            }
          etuCourant->suivant = nouveauEtu;
          nouveauEtu->precedant = etuCourant;
        }
    }



    //Comparaisons de  deux etudiants
short comparer2Etudiant(ETUDIANT etuTable, ETUDIANT etuChercher)
  {
    short test = 0;
    if (etuTable == NULL || etuChercher == NULL)
      {
        exit(EXIT_FAILURE);
      }
    else
      {
        if((!strcmp(etuTable->nom, etuChercher->nom) || !strcmp(etuTable->prenom, etuChercher->prenom) ||
          !strcmp(etuTable->ufr, etuChercher->ufr) || !strcmp(etuTable->P_etudiant, etuChercher->P_etudiant)))
          {
            test = 0;
          }
        else
          {
            test = 1;
          }
      }
    return test;
  }




  //En cas de collision on cherche sur une liste doublement chainee
short accederEtudiantEncasCollision(ETUDIANT etuTable, ETUDIANT etuChercher)
    {
      etudiant * etuCourant;
      etuCourant = etuTable;
      short trouve = 0;
      if (etuCourant == NULL || etuChercher == NULL)
        {
          exit(EXIT_FAILURE);
        }
      else
        {
          while ((etuCourant->suivant != NULL) && (trouve == 0))
            {
              etuCourant = etuCourant->suivant;
              trouve = comparer2Etudiant(etuCourant, etuChercher);
            }
        }
      return trouve;
    }




    // rechercher un etudiant dans la table
ETUDIANT rechercherEtudiant(ETUDIANT *table, ETUDIANT etuChercher, short nMax)
    {
      short trouve = 0;
      short hache = fonctionHachage(etuChercher, nMax);
      ETUDIANT etuTable = table[hache];
      if (etuTable == NULL)
        {
          trouve = 0;
        }
      else
        {
          trouve = comparer2Etudiant(etuTable, etuChercher);
          if (trouve == 0)
            {
              trouve = accederEtudiantEncasCollision(etuTable, etuChercher);
            }
        }
      return trouve == 0 ? NULL : etuChercher;
    }




void afficheEtudiant(ETUDIANT etu, short i, short nMax)
  {
    if (etu == NULL)
      {
        exit(EXIT_FAILURE);
      }
    printf("indice-Tab: %d, hascode: %d\n nom: %s, prenom: %s, ufr: %s, P_etudiant %s\n",
          i, fonctionHachage(etu, nMax), etu->nom, etu->prenom, etu->ufr, etu->P_etudiant);
  }




  // lister la table
  // et calculer le nombre moyen d'accès pour retrouver un élément
void afficheTableEtudiant(ETUDIANT *table, short nMax)
  {
    short j = 0;
    short i;
    short nbreOccupe = 0;
    float tauxOccupe = 0;
    ETUDIANT etuCourant;
    for (i = 0; i < nMax; i++)
      {
        etuCourant = table[i];
        if (etuCourant != NULL)
          {
            afficheEtudiant(etuCourant, i, nMax);
            j++;
            while (etuCourant->suivant != NULL)
              {
                etuCourant = etuCourant->suivant;
                printf("              ||\n");
                afficheEtudiant(etuCourant, i, nMax);
                j++;
              }
          }
      }
    nbreOccupe = j;
    tauxOccupe = 100*(nbreOccupe / (float)nMax);
    printf ("\nNombre d'elements dans la table : %d", nbreOccupe);
    printf ("\nTaux d'occupation de la table : %f\n", tauxOccupe);
  }

