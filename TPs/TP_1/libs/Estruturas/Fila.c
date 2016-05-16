#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

/*
//Código baseado na implementação do livro do Nilson Ziviani
*/

// Inicializa com Head e Tail apontando para o mesmo endereço(vazia)
fila initFila()
{
    fila F = malloc(sizeof (*F));
    F->head = malloc(sizeof(struct cell_aux));
    F->tail = F->head;
    F->head->next=NULL;
    F->size = 0;
    return F;
}

//Retorna 1 se vazio
int isEmpty(fila F)
{
    int flag = F->head == F->tail;
    return flag;
}

//Empilha no Inicio da Fila
void Empilha(fila F, int vertice)
{
    cell Aux;
    Aux = (cell) malloc(sizeof(struct cell_aux));
    F->head->vertice = vertice;
    Aux->next = F->head;
    F->head = Aux;
    F->size++;
}

//Entra no Fim da Fila
void Queue(fila F, int vertice)
{
    F->tail->next = malloc(sizeof(struct cell_aux));
    F->tail = F->tail->next;
    F->tail->vertice = vertice;
    F->tail->next = NULL;
    F->size++;
}

//Retira da primeira posição
int deQueue(fila F)
{
    if(F->size <= 0)
    {
        return-1;
    }

    cell aux = F->head;
    F->head = F->head->next;
    int val = F->head->vertice;
    free(aux);
    F->size--;
    return val;
}


//Libera Memoria da fila
void liberaFila(fila F)
{
    cell aux;
    if(F->head != NULL)
    {
        aux = F->head;
        F->head = F->head->next;
        free(aux);
    }
    free(F);
}
