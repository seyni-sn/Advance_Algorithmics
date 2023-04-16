#include <stdio.h>
#include <stdlib.h>
#define N 100
void saisi_affich(int*);
double moyenne(int*,int);
int k = 0;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	int *t;
	t = (int*)malloc(N*sizeof(int));
	saisi_affich(t);

	return 0;
}
double moyenne(int*t,int n)
{
	int i = 0, s = 0;
	double m = 0;
	for(i=0; i< n-1; i++)
	{
	 s += t[i];
	}
	m = ((double)s / (n-1));
	return m;
}
void saisi_affich(int*t)
{
	int en = 0, i = 0;
	double m = 0;
	do
	{
		do{
		    printf("Entrez un entier positif:\n");
		    scanf("%d", &en);
		  }while(en < -2);//To allow -1 for stoping the loop
		  t[i] = en;
		  i++;
	}while(en!=-1);//Enter -1 to stop
	k = i;
	m = moyenne(t,k);
	printf("la moyenne est: %lf\n", m);
}
