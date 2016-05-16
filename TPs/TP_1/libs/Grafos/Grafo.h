#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include "Estruturas/Lista.h"
#include <limits.h>
#include <float.h>

#define InfI INT_MAX //Valor Máximo de números inteiros
#define InfF FLT_MAX //Valor Máximo de números ponto flutuante

#define Preto -10 // Nao pode passar pela aresta, marca assim ao fim do dijkstra e apos todos as marcações de bombeiros
#define Vermelho -1 // Nao sabe se pode ou nao passar pela aresta, necessita saber dist do bombeiro
#define Branco 1 //Aresta pode ser caminhada no dijikstra
#define Azul 10


/*
//Definição da TAD dos grafos e das funções que os gerenciam
*/

//Apontador Tipo Grafo
typedef struct grafo_aux * grafo;
struct grafo_aux
{
    //Variaveis Lidas Inicialmente
    int numVertices;//Quarteirões
    int numArestas;//Ruas
    int root;//Id saída
    int end;//Id chegada
    int distMaxBombeiros;
    int numBombeiros;

    //Lista de Adjacencia
    lista * listaAdj;

    //Marcação Para saber arestas que podem ser passadas
    int * cor; //Iniciar como Preto

    //Para rastreabalidade do caminho
    int * anterior;

    //Custo até vertice(não é a probabilidade)
    float * probs;
};

//Inicializa o grafo com os vetores nos tamanhos definidos pelos parametros
grafo initGrafo(int numVertices, int numArestas, int root, int end, int distMaxBombeiros, int numBombeiros);

//Libera Memoria aolocada pelo grafo
void liberaGrafo(grafo G);

//Add aresta bidemensional
void addAresta(grafo G, int vertice1, int vertice2, float fireProbs);

//Imprime caminho por meio de antecessores
int printCaminho(grafo G);

#endif // GRAFO_H_INCLUDED
