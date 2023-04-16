#include"Liste_CHAINER.h"
int main()
{   float abs,ord;
    Courbe courbe;
    short nombre2point,ichoix,iposition;
    short nombre2file,nombre2pile;
    FilePoint file;
    PilePoint pile;
    do  {system("cls");
        printf("---------------MENU--------------\n");
        printf("\n-------------------------------------\n");
        printf("1.Creer une courbe\n");
        printf("2.Inserer en tete un point dans une Courbe\n");
        printf("3.Inserer en queue un point dans une courbe\n");
        printf("4.Inserer a une position donnee un point dans une courbe\n");
        printf("5.Supprimer en tete un point dans une Courbe\n");
        printf("6.Supprimer en queue un point dans une Courbe\n");
        printf("7.Supprimer a une position donnee un point dans une Courbe\n");
        printf("8.Enfilement\n");
        printf("9.Denfilement\n");
        printf("10.Empilement\n");
        printf("11.Dempilement\n");
        printf("12.Saisir file et Afficher file \n");
        printf("13.Saisir pile et Afficher pile \n");
        printf("14.Quitter le programme \n");
        printf("Entrez un choix");
        scanf("%d",&ichoix);
        switch(ichoix)
        {
        case 1://Creer une courbe
            printf("Donnez le nombre de point de la courbe\n:");
            scanf("%d",&nombre2point);
            printf("\n");
            courbe = creerCourbe(nombre2point);
            afficheCourbe(courbe);
            system("pause");
            break;
        case 2://Inserer en tete un point dans une Courbe
            printf("Donnez le point a inserer  en tete \n:");
            scanf("%2f %2f",&abs,&ord);
            courbe = insererEnTeteCourbe(courbe,abs,ord);
            afficheCourbe(courbe);
            system("pause");
            break;
        case 3: //Inserer en queue un point dans une courbe
            printf("Donnez le point a inserer  en queue \n:");
            scanf("%2f %2f",&abs,&ord);
            courbe = insererEnQueuCourbe(courbe,abs,ord);
            afficheCourbe(courbe);
            system("pause");
            break;
        case 4: //Inserer a une position donnee un point dans une courbe
            printf("Donnez la position du point a inserer\n:");
            scanf("%d",&iposition);
            printf("Donnez le point a inserer a la position %d\n:",iposition);
            scanf("%2f %2f",&abs,&ord);
            courbe = insererEnPositionCourbe(courbe,abs,ord,iposition);
            afficheCourbe(courbe);
            system("pause");
            break;
        case 5: //Supprimer en tete un point dans une Courbe
            printf("Suppression du premier point\n:");
            courbe = supprimerEnTeteCourbe(courbe);
            afficheCourbe(courbe);
            system("pause");
            break;
        case 6: //Supprimer en queue un point dans une Courbe
            printf("Suppression du dernier point\n:");
            courbe = supprimerEnQueuCourbe(courbe);
            afficheCourbe(courbe);
            system("pause");
            break;
        case 7: // Supprimer a une position donnee un point dans une Courbe
            printf("Donnez la position du point a supprimer\n");
            scanf("%d",&iposition);
            printf("Suppression du %d eme point\n:",iposition);
            courbe = supprimerEnPositionCourbe(courbe,iposition);
            afficheCourbe(courbe);
            system("pause");
            break;
        case 8: //Enfilement
            initialiserFile(file);
            file = enfiler(file,1,1);
            afficherFile(file);
            system("pause");
            break;
        case 9: //Defiment
            file = defiler(file);
            afficherFile(file);
            system("pause");
            break;
        case 10: //Empilement
            initialiserPile(pile);
            pile = empiler(pile,2,2);
            pile = empiler(pile,1,1);
            afficherPile(pile);
            system("pause");
            break;
        case 11: //Depilement
            pile = depiler(pile);
            afficherPile(pile);
            system("pause");
            break;

        case 12: //Saisir file
            printf("Donner le nombre le file\n");
            scanf("%d",&nombre2file);
            file = saisirFile(nombre2file);
            afficherFile(file);
            system("pause");
            break;

        case 13: //Saisir pile
            printf("Donner le nombre le pile\n");
            scanf("%d",&nombre2pile);
            pile = saisirPile(nombre2pile);
            afficherPile(pile);
            system("pause");
            break;
        case 14: //Quitter
            break;
        default:
            printf("Bonjour il faut un chiffre compris entre 1 et 14");
            system("pause");
            break;
        }
    }while(ichoix != 14);
    return 0;
    }
