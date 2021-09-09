#include <stdio.h>
#include <sys/time.h>

int normaliseCapteur( int valCapteur[4] );

int main(void)
{
    int valCapteur[8] = { 2, 56, 180, 60, 10, 1020, 65, 55 };
    int valCapteurfinal[4];
    float moyenne;
	int i;
    int j;
    int k;
    unsigned long duree;
    struct timeval debutCalcul, finCalcul;

    // Heure debut du calcul
    gettimeofday(&debutCalcul,NULL);
    
    // tri croissant
   	for(i=0;i<7;i++)
		{
			for(j=i+1;j<8;j++)
				{
       				if (valCapteur[i]>valCapteur[j]) 
       					{
           					k=valCapteur[i];
            				valCapteur[i]=valCapteur[j];
            				valCapteur[j]=k;
            			}
       			}
		}
		
	// mettre les valeurs selectionnées dans un autre tableau
	valCapteurfinal[0]=valCapteur[2];
	valCapteurfinal[1]=valCapteur[3];
	valCapteurfinal[2]=valCapteur[4];
	valCapteurfinal[3]=valCapteur[5];	

    // Refaire le calcul 1000000 fois pour augmenter la duree de calcul
    // j'ai rajouté de la durée de calcul sinon ca m'affichait 0 ms
    for( j = 0; j < 1000000; j++) {
        moyenne = normaliseCapteur(valCapteurfinal);
    }

    // Heure fin du calcul
    gettimeofday(&finCalcul,NULL);

    printf("moyenne %.2f\n", moyenne);

    duree = ((finCalcul.tv_sec - debutCalcul.tv_sec) * 1000000) + (finCalcul.tv_usec - debutCalcul.tv_usec);
    printf( "Duree %ld ms\n", duree );  
}

int normaliseCapteur( int valCapteur[8] )
{
    int i;
    int total=0;
    float moyenne;

    total = 0;
    for( i = 0; i < 4; i++) {
        total += valCapteur[i];
    }
    moyenne = total / 4;
	//moyenne = total>>2; //différence de environ 13 ms avec le divisé par 4
	
    return(moyenne);
}
