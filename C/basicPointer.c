#include <stdio.h>
#include <stdlib.h>

int retour(int x,int y);

//This is a basic program which introduce pointers

int main(int argc,char*argv[])
{
    int x = 0, y = 0, r = 0;
    printf("Donner deux entiers: \n");
    scanf("%d%d", &x, &y);
    r = retour(x, y);
    printf("La valeur retourne est: %d\n", r);
    return 0;
}

int retour(int x, int y)// It turn x + y
{
    int *p = NULL;
    p = &x;
    *p += y;
    return *p;
}

