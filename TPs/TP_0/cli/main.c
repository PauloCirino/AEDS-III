#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estruturas/Lista.h"
#include "Estruturas/TAD.h"
#include "Auxiliar/Auxiliar.h"
int main ()
{
    int numCases;
    scanf("%d",&numCases);
    //printf("%d \n",numCases);


    int cont;
    for(cont = 0; cont<numCases && EOF; cont++)
    {
        TAD wordList = initTAD();
        char C;
        scanf("%c",&C);

        while(C == '\n')/*Para pular o `/n` entre listas de palavras*/
        {
            scanf("%c",&C);
        }

        while(C != '\n')/*Para Leitura das palavras ate fim da lista*/
        {
            while(C == ' ')/*Para pular o espaco entre palavras*/
            {
                scanf("%c",&C);
            }

            char * Palavra = NULL;
            int sizePalavra = 0;
/*Onde C ja e uma letra diferente de ` ` e `\n` e essa e colocada em uma palavra  todas as letras lidas ate o proximo ` ` ou `\n`*/
            while(C != ' ' && C != '\n')
            {
                sizePalavra++;
                Palavra = (char*)realloc(Palavra, sizePalavra*sizeof(char));
                Palavra[sizePalavra-1] = C;
                scanf("%c",&C);
            }/*Fim da Leitura de uma Palavra*/


/* Onde colocamos um `\0` para terminar a palavra e poder utiliza-la com string.h*/
            sizePalavra++;
            Palavra = realloc(Palavra, sizePalavra*sizeof(char));
            Palavra[sizePalavra-1] = '\0';
            maiuscula(Palavra,sizePalavra);

/*Ordenamos a palavra para fazer o teste se ela e um anagrama na lista*/
            qsort(Palavra, (sizePalavra-1), sizeof(char), comparaChar);
            insereTAD(wordList, Palavra, sizePalavra);
            Palavra = NULL;
            free(Palavra);
        }/*Fim de uma Lista*/

        printResposta(wordList);/*Imprime resposta no formato desejado*/
	liberaTAD(wordList);
        printf("\n");
    }

    return 0;
}
