#include <stdio.h>
#include <stdlib.h>

/*Metodo utiliza a tabela ASC para transformar letras em maiusculas*/
void maiuscula(char * palavra, int sizePalavra)
{
    int cont;
    for(cont=0; cont<sizePalavra-1; cont++)
    {
        if(palavra[cont] > 96)
        {
            palavra[cont]-=32;
        }
    }
}


/*Utilizacao para a funcao qsort de stdlib.h para ordenar palavras*/
int comparaChar(const void * a, const void * b)
{
    if ( *(char*)a <  *(char*)b )
    {
            return -1;
    }
    if ( *(char*)a == *(char*)b )
    {
        return 0;
    }
    return 1;
}


/*Utilizacao para a funcao qsort de stdlib.h para ordenar vetor resposta*/
int comparaInt(const void * a, const void * b)
{
    return ( *(int*)b - *(int*)a );
}

