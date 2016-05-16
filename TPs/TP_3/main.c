#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "Estruturas_E_Funcoes.h"

int numThreads;

int main(int argc, char ** argv)
{
//Confere a quantidade de argumentos
    if(argc != 3)
    {
        printf("Error número de parametros - Utilização correta : \t");
        printf("./tp2 -t [Numero de Threads]\n");
        return -1;
    }

//Confere se têm o argumento -a
    if(strcmp(argv[1], "-t"))
    {
        printf("Error número de parametros - Utilização correta : \t");
        printf("./tp2 -t [Numero de Threads]\n");
        return -1;
    }

//Confere se parametro é algum dos metodos validos
    numThreads = atoi(argv[2]);
    if(numThreads == 0)
    {
        return -1;
    }

    int numInstances;
    scanf("%d", &numInstances);
    int cont;
    for(cont = 0; cont < numInstances; cont++) // Enquanto existir instâncias
    {
        int idealSum;
        scanf("%d", &idealSum);

        char auxChar = '\n';
        while(auxChar == '\n' || auxChar == ' ')
        {
            scanf("%c", &auxChar);
        }

        int sizeValueVet = 1;
        int * valueVet = (int*) malloc(sizeValueVet * sizeof(int) );
        valueVet[sizeValueVet - 1] = 0;

        while(auxChar !='\n' )
        {
            if(auxChar == ' ')
            {
                sizeValueVet++;
                valueVet = (int*) realloc(valueVet, sizeValueVet * sizeof(int));
                valueVet[sizeValueVet -1] = 0;
            }

            else
            {
                int pos = sizeValueVet - 1;
                valueVet[pos] *= 10;
                valueVet[pos] += (int) auxChar - 48;
            }

            scanf("%c", &auxChar);
        }
        //Aloca árvore
        tree T = initTree(idealSum, valueVet,sizeValueVet, numThreads);
        leaf L = T->topo ;
        growTree(L);

        //Cria thread que percorre e cria árvore
        pthread_t MAIN;
        (void) pthread_create(&MAIN, NULL, NewSpawnTree, (void *) L);
        pthread_join(MAIN,NULL); // espera esse percorrimento acabar

        //Confere se encontrou o resultado
        if(T->FLAG == 0)
        {
            printf("sim\n");
        }
        else
        {
            printf("nao\n");
        }

        //libera Memoria
        liberaArvore(T);
        free(valueVet);


    }

    return 0;
}
