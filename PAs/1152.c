#include <stdio.h>
#include <stdlib.h>
 
#define MAX 200000
 
typedef struct
{
    int valFrom;
    int valTo;
    int cost;
} aresta;
 
aresta Grafo[MAX];
int grau[MAX];
 
int compara (const void * a, const void * b)
{
    aresta *A = (aresta *)a;
    aresta *B = (aresta *)b;
    return (A->cost - B->cost);
}
 
void imprimeGrafo(int numArestas)
{
    int cont;
    for(cont=0; cont<numArestas; cont++)
    {
        printf("%d\t %d\t %d\n",Grafo[cont].valFrom,Grafo[cont].valTo,Grafo[cont].cost);
    }
}
 
int ciclo(int valFrom, int valTo) {
 
    while (grau[valFrom] > -1)
    {
        //printf("Grau = %d \n",grau[valFrom]);
        valFrom = grau[valFrom];
    }
 
    while (grau[valTo] > -1)
    {
        valTo = grau[valTo];
    }
 
    if (valFrom != valTo)
    {
        grau[valTo]=valFrom;
        return 0;
    }
 
    return 1;
}
 
 int main()
{
    FILE * arq = fopen("input.txt","r");
    while(1)
    {
        int numArestas, numVertices;
        scanf("%d %d", &numVertices, &numArestas);
        //printf("%d %d\n",numVertices,numArestas);
        if(numVertices == 0 && numArestas==0)
        {
            return 0;
        }
 
        int cont;
        for(cont = 0; cont<numVertices; cont++ )
        {
            grau[cont] = -1;
        }
 
        int custoTotal=0, novoCusto=0;
        for(cont = 0; cont < numArestas; cont++)
        {
            scanf("%d %d %d", &Grafo[cont].valFrom, &Grafo[cont].valTo, &Grafo[cont].cost);
            //grau[Grafo[cont].valFrom]++;
            //grau[Grafo[cont].valTo]++;
            custoTotal+=Grafo[cont].cost;
            //printf("%d %d %d\n", valFrom, valTo, cost);
        }
 
        qsort(Grafo,numArestas,sizeof(aresta),compara);
        //imprimeGrafo(numArestas);
 
        cont = 0;
        int newNumAresta = 0;
        while ((newNumAresta < numVertices-1) && cont < numArestas) {
            if (!ciclo(Grafo[cont].valFrom, Grafo[cont].valTo))
            {
                newNumAresta++;
                novoCusto += Grafo[cont].cost;
            }
            cont++;
        }
        printf("%d\n",custoTotal-novoCusto);
 
    }
    return 0;
}
