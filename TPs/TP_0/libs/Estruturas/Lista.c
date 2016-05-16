#include "Lista.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*Adiciona nova palavra na lista*/
Lista novaPalavraLista(char * palavra, int sizePalavra, Lista next)
{
/*Aloca memoria para nova palavra*/
    Lista aux = malloc(sizeof(struct node));
    aux->palavra = malloc(sizePalavra*sizeof(char));

/*seta as variaveis da nova palavra*/
    strcpy(aux->palavra, palavra);
    aux->sizePalavra = sizePalavra;
    aux->numRep = 1;
    aux->next = next;

/*Retorna o nodo da nova Palavra*/
    return aux;
}

/*Percorre a lista liberando todos os nodes*/
void liberaLista(Lista L)
{
    Lista aux;
    if(L != NULL)
    {
        aux = L;
        L = L->next;
        free(aux->palavra);
        free(aux);
    }
}
