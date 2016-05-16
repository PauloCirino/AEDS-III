#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

/* ESTE ARQUIVO IMPLEMENTE O TIPO LISTA QUE UTILIZADO PARA GUARDAR A LISTA DE PALAVRAS LIDAS E QUANTAS VEZES EXISTIRAM REARRANJOS DESSAS */

/* As variaveis
	palavra = vetor de caracteres alocado dinamicamente para receber palavras de tamanhos diversos
	sizePalavra = variavel inteira para guardar tamanho de palavra, incluso o '\0' para que a variavel palavra possa ser realocada
	numRep = variavel iniciada com valor 1, que mede a quantidade de rearranjos do anagrama da palavra
 */

typedef struct node * Lista;
struct node
{
    char * palavra;
    int sizePalavra;
    int numRep;
    Lista next;
};

/*Retorna uma lista onde um novo nodo e criado e o antigo passa a ser next do novo, de outra forma essa e a funcao que insere uma nova palavra na lista*/
Lista novaPalavraLista(char * palavra, int sizePalavra, Lista next);

/*Auto-explicativa*/
void liberaLista(Lista L);

#endif // LISTA_H_INCLUDED
