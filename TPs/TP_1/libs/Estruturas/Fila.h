#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

/*
//Essa estrtura funciona tanto como fila como queue,
//a diferença das 2 estrutura esta na função de inserção dos elemento.
//void Queue() insere no fim da fila e void Empilha() no inicio
*/

//Estrutura tipo apontador Celula
typedef struct cell_aux * cell;
//Estrutura node da lista que funciona como fila e queue
struct cell_aux
{
    int vertice;//Unico dado é o vertice
    cell next;
};

//Estrutura para guardar cabeça e fim da da fila
typedef struct fila_aux * fila;
struct fila_aux
{
    cell head;
    cell tail;
    int size;
};

// Inicializa com Head e Tail apontando para o mesmo endereço(vazia)
fila initFila();

//Retorna 1 se Fila vazio
int isEmpty(fila F);

//Empilha no Inicio da Fila
void Empilha(fila F, int vertice);

//Entra no Fim da Fila
void Queue(fila F, int vertice);

//Retira da primeira posição da fila
int deQueue(fila F);

//Libera Memoria da Fila
void liberaFila(fila F);

#endif // FILA_H_INCLUDED
