#ifndef ALGORITIMOS_H_INCLUDED
#define ALGORITIMOS_H_INCLUDED

#include "Grafos/Grafo.h"

//Tem a fun��o de marcar os vertices que s�o permitidos
void marcaDentroRaio(grafo G, int quartBombeiro);

//Algor�timo baseados na implementa��o do pseudo-c�digo presente
//no https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
//T~em fun�ao de encontrar o caminho minimo
void Dijkstra(grafo G);

//Algor�timo que simula o Queue de prioridade para uso no Dijkstra
void addToPriorityQueue(int vertice, int * frindge, int * sizeFrindge);

//Algor�timo que simulando o queue de prioridade retira desse queue o vertice com menor costSum
int popMinCostSum(int * frindge, float * costSum, int *sizeFrindge);

#endif // ALGORITIMOS_H_INCLUDED
