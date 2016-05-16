#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Lista.h"

/*
//Implementação das funções base para Modelagem das Arestas entre os vertices
*/

//Adiciona no topo da lista
lista addNode(lista next, int connectedTo, float prob)
{
    lista aux = malloc(sizeof(struct node));
    aux->connectedTo = connectedTo;
    aux->prob = 1.0-prob;
    aux->cost = (-1)*log(1.0 - prob);
    aux->next = next;
    return aux;
}

//Auto Explicativo
void liberaLista(lista L)
{
    //Passa por todas as posições da lista
    lista aux;
    if(L != NULL)
    {
        aux = L;
        L = L->next;
        free(aux);
    }
}
