#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include "Estruturas/Lista.h"
#include <limits.h>
#include <float.h>

#define InfI INT_MAX //Valor M�ximo de n�meros inteiros
#define InfF FLT_MAX //Valor M�ximo de n�meros ponto flutuante

#define Preto -10 // Nao pode passar pela aresta, marca assim ao fim do dijkstra e apos todos as marca��es de bombeiros
#define Vermelho -1 // Nao sabe se pode ou nao passar pela aresta, necessita saber dist do bombeiro
#define Branco 1 //Aresta pode ser caminhada no dijikstra
#define Azul 10


/*
//Defini��o da TAD dos grafos e das fun��es que os gerenciam
*/

//Apontador Tipo Grafo
typedef struct grafo_aux * grafo;
struct grafo_aux
{
    //Variaveis Lidas Inicialmente
    int numVertices;//Quarteir�es
    int numArestas;//Ruas
    int root;//Id sa�da
    int end;//Id chegada
    int distMaxBombeiros;
    int numBombeiros;

    //Lista de Adjacencia
    lista * listaAdj;

    //Marca��o Para saber arestas que podem ser passadas
    int * cor; //Iniciar como Preto

    //Para rastreabalidade do caminho
    int * anterior;

    //Custo at� vertice(n�o � a probabilidade)
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
