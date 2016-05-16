#include <stdio.h>
#include <stdlib.h>

void printPalavra(char * Palavra, int sizePalavra)
{
    int cont;
    for(cont=0; cont<sizePalavra; cont++)
    {
        printf("%c",Palavra[cont]);
    }
    printf("\n");
}

void primeiraPassada(char * Palavra, int sizePalavra)
{
    int cont;
    for(cont = 0; cont<sizePalavra; cont++)
    {
        int aux = Palavra[cont];
        if( ((aux>=65) && (aux<=90)) || ( (aux>=97) && (aux<=122)))
        {
            Palavra[cont]+=3;
        }
    }
}

void segundaPassada(char * Palavra, int sizePalavra)
{
    char * auxPalavra = malloc(sizePalavra*sizeof(char));
    int cont;
    for(cont = 0; cont < sizePalavra; cont++)
    {
        auxPalavra[cont] = Palavra[sizePalavra-cont-1];
    }
    for(cont = 0; cont <sizePalavra; cont++)
    {
        Palavra[cont] = auxPalavra[cont];
    }
}

void terceiraPassada(char * Palavra, int sizePalavra)
{
    int meio = sizePalavra/2;
    int cont;
    for(cont=0; meio+cont<sizePalavra; cont++)
    {
        Palavra[cont+meio] -=1;
    }
}

int main ()
{
    int numCases;
    scanf("%d",&numCases);

    int cont;
    for(cont = 0; cont<numCases; cont++)
    {
        char C;
        scanf("%c",&C);

        while(C == '\n')
        {
            scanf("%c",&C);
        }

        while(C != '\n')
        {
            char * Palavra = NULL;
            int sizePalavra = 0;

            while( C != '\n')
            {
                sizePalavra++;
                Palavra = (char*)realloc(Palavra, sizePalavra*sizeof(char));
                Palavra[sizePalavra-1] = C;
                scanf("%c",&C);
            }
            primeiraPassada(Palavra, sizePalavra);
            segundaPassada(Palavra, sizePalavra);
            terceiraPassada(Palavra, sizePalavra);
            printPalavra(Palavra, sizePalavra);

        }

    }

    return 0;
}
