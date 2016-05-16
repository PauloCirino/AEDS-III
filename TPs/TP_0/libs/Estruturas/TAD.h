#ifndef TAD_H_INCLUDED
#define TAD_H_INCLUDED

#include "Lista.h"


/* Estrutura criada para guardar a cabeca da lista de palavras e englobar essa de forma a facilitar o manuseio geral do programa */

typedef struct tad * TAD;
struct tad{
    int numWords;
    Lista head;
};

/*Metodo Para inicializar a TAD e a Lista*/
TAD initTAD();


/* Funcao que percorre a Lista procurando a palavra 'palavra' e quando a encotra incrementa o contador numRep(da Lista), mas quando nao a encontra, chama a funcao novaPalavraNaLista que coloca essa nova palavra na lista*/
void insereTAD(TAD T, char * palavra, int sizePalavra);


/*Metodo que retorna um vetor de inteiros de tamanho numWords com todos os numero de repeticoes de todos os arranjos de forma ordenada do maior para o menor*/
int * vetorResposta(TAD T);

/*Metodo que utiliza a funcao vetorResposta para imprimir os resultados*/
void printResposta(TAD T);

/*Metodo que libera a estrutura T e sua Lista*/
void liberaTAD(TAD T);
#endif // TAD_H_INCLUDED


