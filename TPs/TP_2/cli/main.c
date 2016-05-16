#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Algoritimos/ForcaBruta.h"
#include "Algoritimos/Dinamico.h"
#include "Algoritimos/Guloso.h"

int main(int argc, const char * argv[])
{
    char *algoritimos [] = {"PD", "FB", "AG"};

//Confere a quantidade de argumentos
    if(argc != 3)
    {
        printf("Error número de parametros - Utilização correta : \t");
        printf("./tp2 -a [PD | AG | FB]\n");
        return -1;
    }

//Confere se têm o argumento -a
    if(strcmp(argv[1], "-a"))
    {
        printf("Error parametros errados - Utilização correta : \t");
        printf("./tp2 -a [PD | AG | FB]\n");
        return -1;
    }

    //Confere se parametro é algum dos metodos validos
    int flagAux = 0;
    int cont;
    for(cont=0; cont<3; cont++)
    {
        if(!strcmp(argv[2],algoritimos[cont]))
        {
            flagAux += 1;
        }
    }
    if(!flagAux)
    {
        printf("Error parametros errados - Utilização correta : \t");
        printf("./tp2 -a [PD | AG | FB]\n");
        return -1;
    }

    int numCases;
    scanf("%d", &numCases);

    for(cont=0; cont<numCases; cont++)
    {

        int numPlanetas, numConquitas;
        scanf("%d %d", &numPlanetas, &numConquitas);

        int * distancias = malloc((numPlanetas+1) * sizeof(int)); // Vetor com todas as ditâncias
        int * distUntil = malloc((numPlanetas+1) * sizeof(int)); // Vetor da soma das distâncias

        //Le as entradas e inicializa os vetores com os valores delas.
        int sumDist = 0;
        int cont_01;
        for(cont_01=0; cont_01< (numPlanetas+1); cont_01++)
        {
            scanf("%d", &distancias[cont_01]);
            sumDist+= distancias[cont_01];
            distUntil[cont_01] = sumDist;
        }

        //Aplica o metodo escolhido
        int val;

        if(!strcmp(argv[2], "FB") )
        {
            val = ForcaBruta(distancias, numPlanetas, numConquitas, sumDist);
        }
        else if(!strcmp(argv[2], "PD") )
        {
            val = Dinamico(distUntil,numPlanetas,numConquitas,sumDist);
        }

        else
        {
            val = Guloso(distancias, numPlanetas, numConquitas, sumDist);
        }

        printf("%d\n", val);

        free(distUntil);
        free(distancias);
    }
    return 0;
}



