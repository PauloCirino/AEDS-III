#include <stdio.h>
#include <stdlib.h>
#include "Algoritimos.h"
#include "Grafos/Grafo.h"
#include "Estruturas/Fila.h"
#include "Estruturas/Lista.h"

//Algoritimo baseado no pseudo-código presente em https://en.wikipedia.org/wiki/Breadth-first_search
//Marca de Branco todos os vertices dentro do raio do corpo de bombeiros
void marcaDentroRaio(grafo G, int quartBombeiro)
{
    G->cor[quartBombeiro] = Branco;

    int numQuart = G->numVertices;
    int distMaxBombeiros = G->distMaxBombeiros;
    int * distVec = malloc( numQuart * sizeof(int) );
    int * nextVec = malloc( numQuart * sizeof(int) );

    int cont;
    for(cont=0; cont<numQuart; cont++)
    {
        distVec[cont] = InfI;
        nextVec[cont] = -1;
    }
    distVec[quartBombeiro] = 0;

    fila F = initFila();
    Queue(F,quartBombeiro);
    //Enquanto Pilha não está vazia coloco todos vertices adjacentes a posição atual na pilha
    while(! isEmpty(F))
    {
        //Retira do Topo da pilha e percorre lista de ajacencia da posição
        int vertice = deQueue(F);

        //Caso Vazio(Sei da redundância)
        if(vertice != -1)
        {
            //Caminha por todos os vertices adjacentes
            lista aux = G->listaAdj[vertice];
            while(aux != NULL)
            {
                int verticeAdjacente = aux->connectedTo;

                //se ninguem nunca passou nele coloca na pilha
                if(distVec[verticeAdjacente] == InfI)
                {
                    distVec[verticeAdjacente] = distVec[vertice] + 1;
                    nextVec[verticeAdjacente] = vertice;
                    Queue(F,verticeAdjacente);

                    if(distVec[verticeAdjacente] <= distMaxBombeiros)
                    {
                        G->cor[verticeAdjacente] = Branco;
                    }
                }
                aux = aux->next;
            }
        }
    }
    free(distVec);
    free(nextVec);
    liberaFila(F);
}

/*
//Funções para o Dijkstra
*/

//Algorítimo que simula o Queue de prioridade
void addToPriorityQueue(int vertice, int * frindge, int * sizeFrindge)
{
    int newFrindgeSize = *sizeFrindge + 1;
    frindge[newFrindgeSize - 1] = vertice;
    *sizeFrindge = newFrindgeSize;
}

int popMinCostSum(int * frindge, float * costSum, int *sizeFrindge)
{
    int sizeFrindgeAux = *sizeFrindge;

    //Testa se a frindge esta vazia
    if (sizeFrindgeAux == 0)
    {
        return -1;
    }

    //A posição do vetor frindge onde o vertice representado tem costSum minimo
    int posMinCostSum = 0;
    int verticeMinCostSum = frindge[0];
    float minCostSum = costSum[verticeMinCostSum];

    //Acha posição do vetor frindge(o vertice) que têm menor valor minCostSum
    int cont;
    for(cont=1; cont<sizeFrindgeAux; cont++)
    {
        if(minCostSum > costSum[frindge[cont]] )
        {
            posMinCostSum = cont;
            verticeMinCostSum = frindge[cont];
            minCostSum = costSum[verticeMinCostSum];
        }

        //tratamento lexicográfico
        else if(minCostSum == costSum[frindge[cont]] && verticeMinCostSum > frindge[cont])
        {
            posMinCostSum = cont;
            verticeMinCostSum = frindge[cont];
            minCostSum = costSum[verticeMinCostSum];
        }

    }

    //faz swap da posição com menor valor e a ultima posição do vetor
    if(posMinCostSum != (sizeFrindgeAux-1) )
    {
        int aux = frindge[ sizeFrindgeAux - 1 ];
        frindge[ sizeFrindgeAux - 1 ] = frindge[posMinCostSum];
        frindge[posMinCostSum] = aux;
    }

    //Diminui o tamanho da frindge
    frindge[sizeFrindgeAux-1] = -1 ;
    sizeFrindgeAux-- ;
    *sizeFrindge = sizeFrindgeAux;

    return verticeMinCostSum;
}

//Algorítimo baseados na implementação do pseudo-código presente no https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
void Dijkstra(grafo G)
{

    int root = G->root;
    int end = G->end;
    if( (G->cor[root] != Branco) || (G->cor[end] != Branco) )
    {
        return;
    }

    //Seta e aloca vetores auxiliares para guardar valor de custo e anteriores e periferia
    int numVertices = G->numVertices;
    int * frindge = malloc( numVertices * sizeof(int));
    int * previous = malloc( numVertices * sizeof(int));
    float * costSum = malloc( numVertices * sizeof(float) );

    int cont;
    for(cont=0; cont<numVertices; cont++)
    {
        costSum[cont] = InfF;
        previous[cont] = -1;
        frindge[cont] = -1;
    }

    //Seta a fringe com o vertice de entrada e o custo inicial a 0
    int sizeFrindge = 1;
    frindge[sizeFrindge-1] = root;
    costSum[root] = 0.0;


    while( ( G->cor[end] != Vermelho ) &&  ( sizeFrindge > 0 ) )
    {
        int vertice = popMinCostSum(frindge, costSum, &sizeFrindge);
        lista auxList = G->listaAdj[vertice];
        while( auxList != NULL )
        {
            //Se ninguem passou por ele marca e coloca no queue
            if(G->cor[auxList->connectedTo] == Branco)
            {
                G->cor[auxList->connectedTo] = Azul;
                addToPriorityQueue(auxList->connectedTo, frindge, &sizeFrindge);
            }

            //Caminha por todos os vertices adjacentes atualizando o custo até cada, quando menor que
            //anteorior substitui o custo e o anterior
            if( (G->cor[auxList->connectedTo] == Branco) || ( G->cor[auxList->connectedTo] == Azul ) )
            {
                float auxCost = costSum[vertice] + auxList->cost ;
                if(costSum[auxList->connectedTo] > auxCost)
                {
                    costSum[auxList->connectedTo] = auxCost;
                    previous[auxList->connectedTo] = vertice;
                    G->probs[auxList->connectedTo] = (auxList->prob);
                }
            }
            auxList = auxList->next;
        }
        //Já caminhou por ele todo
        G->cor[vertice] = Vermelho;
    }
    G->anterior = previous;

    free(frindge);
    free(costSum);
}
