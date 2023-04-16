#include "Liste_Chainerbis.h"

int main()
{
float a,b;
    Courbebis courbe;
    short n;
    printf("donnez le nombre de point\n:");
    scanf("%d",&n);
    printf("\n");
    courbe = creerCourbebis(n);
    afficheCourbebis(courbe);
    return 0;
}
