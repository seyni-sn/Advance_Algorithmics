#include "liste_CHAINER.H"
//=========================CREER POINT ET COURBE======================
//creerPoint prend en parametre l'abscisse et ordonner et retourne le point
Point* creerPoint(float abs,float ord)
    {
        Point* p;
        p  = (Point*)malloc(sizeof(Point));
        p->x = abs;
        p->y = ord;
        p->suiv = NULL;
        return p;
    }

//creerCourbe prend en parametre le nombre de point de la courbe et renvoie la courbe
Courbe creerCourbe(short n)
    {
        Point* maillon;
        Point* debut;
        Point* courant;
        short i;
        float a,b;
        if(n >= 1)
        {
            printf("donez abs et ord");
            scanf("%f %f",&a ,&b);
            maillon = creerPoint(a,b);
            debut = courant = maillon;
            for(i=1;i<n;i++)
            {
                printf("donez abs et ord");
                scanf("%f %f",&a ,&b);
                maillon = creerPoint(a,b);
                courant->suiv = maillon;
                courant =  courant->suiv;
            }
            return debut;
        }
        else return NULL;
    }

//afficheCcoubre pris en entrer
    void afficheCourbe(Courbe c)
    {
        Courbe courant = c;
        while(courant !=NULL)
        {
            printf("%f %f\n",courant->x,courant->y);
            courant = courant->suiv;
        }
    }
//========================INSERER EN TETE-QUEUE-POSITION================

//insereEnTeteCourbe prend en parametre la coube et le point a inserer au debut
Courbe insererEnTeteCourbe(Courbe c,float a,float b)
    {
        Point* maillon = creerPoint(a,b);
        if (c!=NULL)
        {   maillon->suiv = c;
            c = maillon;
        }
        else c = maillon;
        return c;
    }

//insereEnQueueCourbe prend en parametre la coube et le point a inserer a la fin
Courbe insererEnQueuCourbe(Courbe c,float a,float b)
    {
        Courbe maillon = creerPoint(a,b);
        Courbe  courant = c;
        if(c!=NULL)
        {
            while(courant->suiv!=NULL)
                courant = courant->suiv;
            courant->suiv = maillon;
        }
        else c = maillon;
        return c;
    }

//insereEnTeteCourbe prend en parametre la coube et le point a inserer a la position donner
Courbe insererEnPositionCourbe(Courbe c,float a,float b,short i)
    {   Courbe maillon = creerPoint(a,b);
        Courbe  courant = c;
        short j;
        if(c!=NULL)
        {
            for(j=1;j<i;j++)
                courant = courant->suiv ;
            maillon->suiv  =  courant->suiv;
            courant = maillon;
            return c;
        }
        else c = maillon;
        return c;
    }
//=================SUPPRIMER EN TETE-QUEUE-POSITION================

//supprimerENTeteCourbe prend en parametr la coube et supprime l'element en tete
Courbe supprimerEnTeteCourbe(Courbe c)
    {
        if(c!=NULL)
        {
            Courbe s = c;
            c =  c->suiv;
            free(s);
        }
        return c;
    }


//supprimerEnQueueCourbe prend en parametr la coube et supprime l'element de la fin
Courbe supprimerEnQueuCourbe(Courbe c)
    {
         Courbe courant = c;
         Courbe precedent = c;
         while(courant->suiv!=NULL)
         {
             precedent =courant;
             courant = courant->suiv;
         }
         precedent->suiv = NULL;
         free(courant);
         return c;
    }
//supprimerENTeteCourbe prend en parametr la coube et supprime l'elementdonnez a la position i
Courbe supprimerEnPositionCourbe(Courbe c,short i)
    {
        short j;
         Courbe courant = c;
         Courbe precedent = c;
         for(j=1;j<i;j++)
         {
             precedent = courant;
             courant = courant->suiv;
         }
         precedent->suiv = courant->suiv ;
         free(courant);
         return c;
    }

//================PILES=========================================================

	//Initialisation de la pile
void initialiserPile(PilePoint pile)
    {
        pile.taille = 0;
        pile.sommet = NULL;
    }


    //Test si une pile est vide
short pileVideTest(PilePoint pile)
    {
        return(pile.taille == 0);
    }


    //Retourne le sommet d'une pile
Courbe pileSommet(PilePoint pile)
    {
        return (pile.sommet);
    }



    //Empilement
PilePoint empiler(PilePoint pile,float abs,float ord)
    {
        pile.sommet = insererEnTeteCourbe(pile.sommet,abs,ord);
        pile.taille++;
        return pile;
    }



    //Depilement
PilePoint depiler(PilePoint pile)
    {
        pile.sommet = supprimerEnTeteCourbe(pile.sommet);
        pile.taille--;
        if(pile.taille == 0)
            pile.sommet = NULL;
        return pile;
    }



    //Saisir une pile
PilePoint saisirPile(short nombre2pile)
    {
        short i;
        float abs,ord;
        PilePoint pile;
        initialiserPile(pile);
        for(i=0;i<nombre2pile;i++)
        {   printf("Donnez abscisse et ordonne");
            scanf("%f %f",&abs,&ord);
            pile = empiler(pile,abs,ord);
        }return pile;
    }



    //Affichage d'une pile
void afficherPile(PilePoint pile)
    {
        Courbe pilesommet;
        printf("La taille du pile est:%2d",pile.taille);
        printf("\n");
        while(!pileVideTest(pile))
        {
            pilesommet =  pileSommet(pile);
            afficheCourbe(pilesommet);
            pile = depiler(pile);
        }

    }



//========================FILES====================================


	//Test si une file est vide
short fileVideTest(FilePoint file)
    {
       return (file.taille == 0);
    }



    //Renvoie la tete d'une file
Courbe fileTete(FilePoint file)
    {
        return (file.tete);
    }



    //Initiale une file
void initialiserFile(FilePoint file)
    {
        file.tete = NULL;
        file.queu = NULL;
        file.taille = 0;
    }




    //Enfilement
FilePoint enfiler(FilePoint file,float abs,float ord)
    {

        /*file.queu = insererEnQueuCourbe(file.queu,abs,ord);
        file.taille++;
        return file;*/
        Courbe maillon;
        maillon = creerPoint(abs,ord);
        if (fileVideTest(file))
            file.tete = file.queu = maillon;
        else
        {
        	(file.queu)->suiv = maillon;
        }
        file.taille++;
        return file;
    }




    //Defilement
FilePoint defiler(FilePoint file)
    {
        file.tete = supprimerEnTeteCourbe(file.tete);
        file.taille--;
        if(file.taille == 0)
            file.queu = NULL;
        return file;
    }



    //Saisie d'une file
 FilePoint saisirFile(short nombre2file)
    {
        FilePoint file;
        short i;
        float abs,ord;
        initialiserFile(file);
        for(i=0;i<nombre2file;i++)
        {   printf("donnez abs et ord");
            scanf("%f %f",&abs,&ord);
            file = enfiler(file,abs,ord);
        }return file;
    }



    //Affiche file
void afficherFile(FilePoint file)
    {

        Courbe filetete;
        printf("Taille de la file %d\n",file.taille);

        while(!fileVideTest(file))
        {
            filetete = fileTete(file);
            afficheCourbe(filetete);
           // printf("\n");
            file = defiler(file);

        }
    }
