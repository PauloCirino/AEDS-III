#include <stdlib.h>
#include <math.h>

#include "Algoritimos/Guloso.h"
#include "Auxiliar/auxLib.h"


//Algorítimo que utliza uma estratégia gulosa para resolver o problema de menor maior subcaminho de um vetor de distâncias
int Guloso(int * distVet, int numPlanetas, int numAConquistar, int sumDist)
{
    //Caso não haja que fazer conquistas retorna a soma do vetor
    if(numAConquistar == 0 )
    {
        return sumDist;
    }


    //Inicializa Variáveis de suporte
    int maxDist = -1;
    int numConquistados = 0;
    int totalDistPercorrida = 0;

    //Até que todos os planetas tenha sido conquitados
    int cont=0;
    while(numConquistados < numAConquistar)
    {
        //Calcula e atualiza distância ideal para um subcaminho do vetor atual
        //(Inicial ou já excluído todos os subcaminhos até o ultimo planeta escolhido)
        int idealDist = ceil((float)( (1.0 * sumDist-totalDistPercorrida) / (numAConquistar + 1 - numConquistados) ));
        int currentDist = distVet[cont];
        int prevDist = -Inf;

        //aproxima 2 caminhos até a distância ideal
        //um dos caminhos é imediatamente menor que ideal e outro imediatamente maior.
        while( currentDist < idealDist )
        {
            cont++;
            prevDist = currentDist;
            currentDist += distVet[cont];
        }

//Escolhe qual dos 2 possíveis subcaminhos é melhor
        int distPercorrida = -1;

        //Caso onde distância anterior é valida e a distância do intervalo superior por sí só já viola a distância ideal
        if(prevDist != (-Inf) &&  ( abs(currentDist-prevDist)  > idealDist) )
        {
            cont--;
            distPercorrida = prevDist;
        }

        //Quando intervalo anterior mais próximo da distância ideal que o atual
        else if( abs(prevDist - idealDist) < abs(currentDist - idealDist) )
        {
            cont--;
            distPercorrida = prevDist;
        }

        //Quando distância anterior é inválida ou é mais longe da distância ideal que a atual
        else
        {
            distPercorrida = currentDist;
        }

        //atualiza maior distância já percorrida
        totalDistPercorrida += distPercorrida;
        maxDist = maior(maxDist, distPercorrida);

        //Atualiza contadores
        numConquistados++;
        cont++;
    }

    //não percorre o ultimo subcaminho só o computa
    int finalDist = sumDist-totalDistPercorrida;
    maxDist = maior(maxDist, finalDist);
    return maxDist;
}
