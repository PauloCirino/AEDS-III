#include <stdlib.h>
#include <math.h>

#include "Algoritimos/Guloso.h"
#include "Auxiliar/auxLib.h"


//Algor�timo que utliza uma estrat�gia gulosa para resolver o problema de menor maior subcaminho de um vetor de dist�ncias
int Guloso(int * distVet, int numPlanetas, int numAConquistar, int sumDist)
{
    //Caso n�o haja que fazer conquistas retorna a soma do vetor
    if(numAConquistar == 0 )
    {
        return sumDist;
    }


    //Inicializa Vari�veis de suporte
    int maxDist = -1;
    int numConquistados = 0;
    int totalDistPercorrida = 0;

    //At� que todos os planetas tenha sido conquitados
    int cont=0;
    while(numConquistados < numAConquistar)
    {
        //Calcula e atualiza dist�ncia ideal para um subcaminho do vetor atual
        //(Inicial ou j� exclu�do todos os subcaminhos at� o ultimo planeta escolhido)
        int idealDist = ceil((float)( (1.0 * sumDist-totalDistPercorrida) / (numAConquistar + 1 - numConquistados) ));
        int currentDist = distVet[cont];
        int prevDist = -Inf;

        //aproxima 2 caminhos at� a dist�ncia ideal
        //um dos caminhos � imediatamente menor que ideal e outro imediatamente maior.
        while( currentDist < idealDist )
        {
            cont++;
            prevDist = currentDist;
            currentDist += distVet[cont];
        }

//Escolhe qual dos 2 poss�veis subcaminhos � melhor
        int distPercorrida = -1;

        //Caso onde dist�ncia anterior � valida e a dist�ncia do intervalo superior por s� s� j� viola a dist�ncia ideal
        if(prevDist != (-Inf) &&  ( abs(currentDist-prevDist)  > idealDist) )
        {
            cont--;
            distPercorrida = prevDist;
        }

        //Quando intervalo anterior mais pr�ximo da dist�ncia ideal que o atual
        else if( abs(prevDist - idealDist) < abs(currentDist - idealDist) )
        {
            cont--;
            distPercorrida = prevDist;
        }

        //Quando dist�ncia anterior � inv�lida ou � mais longe da dist�ncia ideal que a atual
        else
        {
            distPercorrida = currentDist;
        }

        //atualiza maior dist�ncia j� percorrida
        totalDistPercorrida += distPercorrida;
        maxDist = maior(maxDist, distPercorrida);

        //Atualiza contadores
        numConquistados++;
        cont++;
    }

    //n�o percorre o ultimo subcaminho s� o computa
    int finalDist = sumDist-totalDistPercorrida;
    maxDist = maior(maxDist, finalDist);
    return maxDist;
}
