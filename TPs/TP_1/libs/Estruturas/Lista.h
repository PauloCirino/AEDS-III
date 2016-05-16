#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

/*
//Estrutura e funções base para Modelagem das Arestas entre os vertices
*/

//apontador tipo lista
typedef struct node * lista;
//Carrega Informações de Cada Aresta(Representa aresta do grafo)
struct node
{
    lista next;
    float prob;// probabilidade de não ter incendio
    float cost;// custo aresta para o dijkstra
    int connectedTo;

};

//Adiciona no topo da lista
lista addNode(lista next, int connectedTo, float prob);

//Libera Memoria alocada pela Lista
void liberaLista(lista L);



#endif // LISTA_H_INCLUDED
