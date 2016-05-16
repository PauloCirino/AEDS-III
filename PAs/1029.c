#include <stdio.h>
#include <stdlib.h>

int main(){

	int numCases;
	scanf("%d", &numCases);

	int cont;
	for(cont = 0; cont<numCases; cont++){
        int F;
        scanf("%d",&F);
        int * seqFib = malloc((F+1)* sizeof(int));
        int * seqOneFib = malloc((F+1)* sizeof(int));

        seqFib[0] = 0;
        seqFib[1] = 0;
        seqOneFib[0] = 0;
        seqOneFib[1] = 1;

        int cont1;
        for(cont1 = 2; cont1<(F+1); cont1++){
            seqFib[cont1] = seqFib[cont1-1] + seqFib[cont1-2] + 2;
            seqOneFib[cont1] = seqOneFib[cont1-1] + seqOneFib[cont1-2];
        }

        printf("fib(%d) = %d calls = %d\n", F, seqFib[F], seqOneFib[F]);



	}
	return 0;
}
