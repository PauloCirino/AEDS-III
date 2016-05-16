#include<stdlib.h>
#include<stdio.h>
#include <limits.h>
#include <float.h>
#include "Grafos/Grafo.h"
#include "Estruturas/Fila.h"
#include "Estruturas/Lista.h"

/*
//Implementação das funções que gerenciam os Grafos
*/

//Inicializa o grafo com os vetores nos tamanhos definidos pelos parametros
grafo initGrafo(int numVertices, int numArestas, int root, int end, int distMaxBombeiros, int numBombeiros)
{
    //Seta parametros do grafo
    grafo G = malloc(sizeof(*G));
    G->numVertices = numVertices;
    G->numArestas = numArestas;
    G->root = root;
    G->end = end;
    G->distMaxBombeiros = distMaxBombeiros;
    G->numBombeiros = numBombeiros;

    //Inicializa um vetor de lista onde cada listaAdj[pos] é a lista de vertices adijacentes ao vertice pos
    G->listaAdj = malloc(numVertices * sizeof(lista));

    //Aloca memoria para Vetores
    G->cor = malloc(numVertices * sizeof(int));
    G->anterior = malloc(numVertices * sizeof(int));
    G->probs = malloc(numVertices * sizeof(float));

    //Listas de adjacencia de cada aresta, suas cores e seus predecessores setados
    int cont;
    for(cont=0; cont<numVertices; cont++)
    {
        G->listaAdj[cont] = NULL;
        G->cor[cont] = Preto;
        G->anterior[cont] = -1;
        G->probs[cont] = 1;
    }
    return G;
}

//Libera Memoria aolocada pelo grafo
void liberaGrafo(grafo G)
{
    //libera Lista de Adjacencia
    int cont;
    for(cont=0; cont < G->numVertices; cont++)
    {
        liberaLista(G->listaAdj[cont]);//Cada Posição do Vetor da Lista de Adj
    }
    free(G->listaAdj);

    //Libera outros vetores
    free(G->cor);
    free(G->anterior);
    free(G->probs);

    //Finalmente Libera apontador do grafo
    free(G);
}

//Add aresta bidemensional
void addAresta(grafo G, int vertice1, int vertice2, float fireProbs)
{
    //Grafo bidirecional
    G->listaAdj[vertice1] = addNode(G->listaAdj[vertice1], vertice2, fireProbs);
    G->listaAdj[vertice2] = addNode(G->listaAdj[vertice2], vertice1, fireProbs);
}

//Imprime caminho por meio de antecessores
int printCaminho(grafo G)
{

    //Caso Vertice de entrada ou Vertice de saída não estejam dentro da distância maxima permitida do corpo de bombeiros
    if(G->cor[G->root] != Vermelho || G->cor[G->end] != Vermelho)
    {
        printf("-1\n");
        return -1;
    }

//Como é feito por meio de antecessores colocamos tudo em um queue
    fila F = initFila();
    float probs = 1;

    //Guarda caminho em um queue
    int vertice = G->end;
    do
    {
        Queue(F,vertice);
        probs = probs * G->probs[vertice];
        vertice = G->anterior[vertice];

    }
    while(vertice != -1);

    //Impressão dos Resultados
    printf("%.2f",1.0-probs);
    while(!isEmpty(F))
    {
        printf(" %d",deQueue(F));
    }
    printf("\n");

    liberaFila(F);

    return 1;
}
