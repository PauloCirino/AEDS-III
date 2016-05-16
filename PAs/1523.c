#include <stdio.h>
#include <stdlib.h>

void printVet(int * V, int sizeV)
{
    int cont;
    for(cont=0; cont<sizeV; cont++)
    {
        printf("%d ", V[cont]);
    }
    printf("\n");
}


void popPile( int * V, int sizeV, int * numInV, int untilValue)
{

    int startingPos = sizeV - *numInV;
    //printf("numInV = %d \n", *numInV);
    //printf("StartingPos = %d \n", startingPos);

    int cont;
    int flag=0;
    for(cont = startingPos; cont<sizeV && flag == 0; cont++)
    {
        if(V[cont] <= untilValue)
        {
            //printf("Poping %d \n", V[cont]);
            V[cont] = 0;
            *numInV = *numInV - 1;
        }
        else
        {
            flag = 1;
        }
    }
}

int stockPile(int * V, int sizeV, int * numInV, int addValue)
{
    int pos = sizeV - *numInV - 1;
    int previousPos = sizeV - *numInV;
    if(pos < 0 )
    {
        //printf("PASSEI FLAG -1\n");
        return -1;
    }

    //printf("Pos = %d \t PreviousPos = %d\n", pos, previousPos);

    if(previousPos < sizeV && previousPos >= 0)
    {
        if(V[previousPos] <= addValue && V[previousPos] != 0 )
        {
            //printf("PASSEI FLAG -2\n");
            return -2;
        }
    }
    V[pos] = addValue;
    *numInV = *numInV + 1;
    return 1;
}

int main()
{

    int numMotoristas, numCarrosGuarda;
    scanf( "%d %d", &numMotoristas, &numCarrosGuarda);
    while(numCarrosGuarda != 0 || numMotoristas != 0)
    {

        int * Saida = ( int * )calloc(numCarrosGuarda, sizeof(int));
        int numInPark = 0;
        int horaAtual = 0;
        int flag = 0;

        int cont;
        for(cont=0; cont<numMotoristas; cont++)
        {
            int horaEntrada, horaSaida;
            scanf("%d %d", &horaEntrada, &horaSaida);
            if(horaEntrada > horaAtual)
            {
                horaAtual = horaEntrada;
            }

            //printf("HORARIO ATUAL = %d \n", horaAtual);

            //printf("POPPING \n");
            popPile(Saida, numCarrosGuarda, &numInPark, horaAtual);
            //printVet(Saida, numCarrosGuarda);


            //printf("ADDING \n");

            if(numInPark == numCarrosGuarda)
            {
                //printf("PASSEI FLAG 2\n");
                flag = 2;
            }

            if( stockPile(Saida, numCarrosGuarda, &numInPark, horaSaida) < 0 )
            {
                //printf("PASSEI FLAG 1\n");
                flag = 1;
            }

            //printVet(Saida, numCarrosGuarda);
           // printf("\n");

        }

        if (flag == 0) printf("Sim\n");
        else printf("Nao\n");

        free(Saida);

        //Le Novo Caso
        scanf("%d %d", &numMotoristas, &numCarrosGuarda);
    }

    return 0;
}
