#include <stdlib.h>

#include "Algoritimos/ForcaBruta.h"
#include "Auxiliar/auxLib.h"

//Função que caminha com a posição
void CaminhaFb(int * planetasEscolhidos, int sizePlanetasEscolhidos, int numPlanetas)
{
    //Percorre vetor até encontrar planeta que pode andar
    int cont;
    int flag = 1;
    for(cont = 0; cont < sizePlanetasEscolhidos && flag == 1; cont++)
    {
        int maxPos = numPlanetas - 1 - cont; // calcula ultima posição que esse planeta pode assumir
        int pos = sizePlanetasEscolhidos- 1 - cont; // calcula posição atual do planeta
        if(planetasEscolhidos[pos] < maxPos)// caso esse planeta não esjeja em sua última posição possível a flag muda
        {
            flag = -1;
        }
    }


    // Anda com o planeta incial
    int pos = sizePlanetasEscolhidos - cont;
    planetasEscolhidos[pos] ++;

    //Todos os planetas que são após eles são iniciado imediamente apos
    for(pos++; pos<sizePlanetasEscolhidos; pos++)
    {
        planetasEscolhidos[pos] = planetasEscolhidos[pos-1] + 1;
    }
}

int maxDistCalcFb(int * distVet, int sizeDistVet, int * vetPos, int sizeVetPost, int numAConquistar)
{
    int maxDist = -Inf;
    int initPos = 0;

    //Passa por todos os sub-caminhos
    int cont;
    for(cont=0; cont< numAConquistar; cont++)
    {
        int dist = 0;
        int endPos = vetPos[cont];

        //Soma todas as distâncias pertecentes a esse sub-caminho
        int cont_Aux;
        for(cont_Aux=initPos; cont_Aux <= endPos; cont_Aux++ )
        {
            dist += distVet[cont_Aux];
        }

        //Escolhe o maior distância entre maior sub-caminho até o momento e o atual
        maxDist = maior(maxDist,dist);
        initPos = endPos+1;
    }

    //Ultima iteração
    int dist  = 0;
    int endPos = sizeDistVet - 1;
    int cont_Aux;
    for(cont_Aux=initPos; cont_Aux <= endPos; cont_Aux++ )
    {
        dist += distVet[cont_Aux];
    }
    maxDist = maior(dist,maxDist);

    //Retorna maior sub-distância do caminho todos
    return maxDist;

}

//Metodo principal
int ForcaBruta(int * distVet, int numPlanetas, int numAConquistar, int sumDist)
{
    //Caso não haja planetas para conquistar retor o tamanho do caminho todo
    if(numPlanetas == 0)
    {
        return sumDist;
    }

    //Inicializa parametros
    int maxVal = Inf;
    int sizeDistVet = numPlanetas+1;

    int sizeVetPos = numAConquistar;
    int * vetPos = malloc(sizeVetPos * sizeof(int));

    //Inicializa caminho básico inicial {0,1,2,3 ,..., M}
    int cont;
    for(cont=0; cont < sizeVetPos; cont++)
    {
        vetPos[cont] = cont;
    }

    while( vetPos[0] < (numPlanetas-numAConquistar))
    {
        //Retorna maior sub-caminho da disposição atual dos planetas a conquistar
        int dist = maxDistCalcFb(distVet, sizeDistVet, vetPos, sizeVetPos, numAConquistar);

        maxVal = menor(maxVal, dist);//Escolhe menor maior subcaminho
        CaminhaFb(vetPos,sizeVetPos,numPlanetas);//Caminha com o vetor de planetas a conquistar
    }

    //Ultima iteração
    int dist = maxDistCalcFb(distVet, sizeDistVet, vetPos, sizeVetPos, numAConquistar);
    maxVal = menor(maxVal, dist);

    free(vetPos);

    return maxVal;
}

