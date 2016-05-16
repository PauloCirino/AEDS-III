#include <stdlib.h>
#include <stdio.h>
#include "TAD.h"
#include "Lista.h"
#include "Auxiliar/Auxiliar.h"

/*Inicializa a cabeca da Lista e inicializa a tad*/
TAD initTAD()
{
    TAD T = malloc(sizeof(*T));
    T->numWords = 0;
    T->head = NULL;
    return T;
}


/*Percorre Lista procurando a palvra que tenta ser inserida na Lista, caso a encontre essa tera seu contador incrementado, caso nao ela sera inserida na lista. */
void insereTAD(TAD T, char * palavra, int sizePalavra)
{
    Lista aux = T->head;
    while(aux != NULL)/*Percorre Lista*/
    {
        if(!strcmp(palavra,aux->palavra))/*Econtrou a Palavra*/
        {
            aux->numRep++;
            return; /*Se econtrou a palavra sai da funcao*/
        }
        else /*Procura no proximo node*/
        {
            aux = aux->next;
        }
    }
/*Como nao encontrou a palavra na Lista essa e inserida*/
    T->head = novaPalavraLista(palavra, sizePalavra, T->head);
    T->numWords += 1;
}


/*Aloca um vetor de inteiros do tamanho de numWords da estrutura T, e coloca nesse vetor a quantidade de repeticoes de cada arranjo e depois ordena de forma decrescente este vetor*/
int * vetorResposta(TAD T)
{
    int * aux = malloc(T->numWords * sizeof(int));

    int cont;
    Lista L = T->head;
    for(cont = 0; cont < T->numWords; cont ++)
    {
        aux[cont] = L->numRep;
        L = L->next;
    }/*Fim setagem de valores do vetor*/

    qsort(aux, T->numWords, sizeof(int), comparaInt);/*Ordenacao*/

    return aux;
}


void printResposta(TAD T)
{
    int * resposta = vetorResposta(T);

    int cont;
    for(cont = 0; cont < T->numWords; cont++)
    {
        printf("%d ", resposta[cont]);
    }
    free(resposta);
}

void liberaTAD(TAD T)
{
    liberaLista(T->head);
    free(T);
}
