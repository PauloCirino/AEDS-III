#ifndef ALGORITIMOS_H_INCLUDED
#define ALGORITIMOS_H_INCLUDED

#include "Grafos/Grafo.h"

//Tem a função de marcar os vertices que são permitidos
void marcaDentroRaio(grafo G, int quartBombeiro);

//Algorítimo baseados na implementação do pseudo-código presente
//no https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
//T~em funçao de encontrar o caminho minimo
void Dijkstra(grafo G);

//Algorítimo que simula o Queue de prioridade para uso no Dijkstra
void addToPriorityQueue(int vertice, int * frindge, int * sizeFrindge);

//Algorítimo que simulando o queue de prioridade retira desse queue o vertice com menor costSum
int popMinCostSum(int * frindge, float * costSum, int *sizeFrindge);

#endif // ALGORITIMOS_H_INCLUDED
