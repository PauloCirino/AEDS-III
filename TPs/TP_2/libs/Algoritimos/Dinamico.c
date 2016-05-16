#include <stdlib.h>

#include "Algoritimos/Dinamico.h"
#include "Auxiliar/auxLib.h"

//Função que caminha com a posição
int CaminhaDinamico(int * planetasEscolhidos, int sizePlanetasEscolhidos, int numPlanetas)
{

    //Percorre vetor até encontrar planeta que pode andar
    int cont;
    int flag = 1;
    for(cont = 0; cont < sizePlanetasEscolhidos && flag == 1; cont++)
    {
        int maxPos = numPlanetas - 1 - cont;// calcula ultima posição que esse planeta pode assumir
        int pos = sizePlanetasEscolhidos- 1 - cont;// calcula posição atual do planeta
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

    //retorna posição do primeiro que andou
    return (sizePlanetasEscolhidos - cont);
}

//Calcula vetor maxDistUntil a partir da posição flag que é a utima posição alterada
int maxDistCalcDinamico( int * maxDistUntil, int sizeMaxDistUntil, int flag,
                         int * distUntil, int sizeDistUntil,
                         int * vetPos, int sizeVetPos, int numAConquistar)
{
    //Se é a primeira posição que andou
    int maxDist;
    if(flag == 0)
    {
        maxDist = distUntil[vetPos[0]];
        maxDistUntil[0] = maxDist;
        flag ++;
    }
    else
    {
        maxDist = maxDistUntil[flag - 1];
    }

    //Passa por todos os subcaminhos a partir de onde foi alterado comparada a ultima vez que andou
    int cont;
    for(cont=flag; cont< (sizeMaxDistUntil-1); cont++)
    {
        //Distância de um subcaminho é a distância total até o ponto final menos a distância total até seu ponto inicial
        int newDist =  distUntil[vetPos[cont]] - distUntil[vetPos[cont-1]];
        maxDist = maior(maxDist,newDist);
        maxDistUntil[cont] = maxDist;
    }

    //Ultima iteração
    int newDist =  distUntil[sizeDistUntil-1] - distUntil[vetPos[cont-1]];
    maxDist = maior(maxDist,newDist);
    maxDistUntil[cont] = maxDist;

    //Retorna maior subdistância do caminho
    return maxDistUntil[sizeMaxDistUntil-1];
}


//Metodo principal
int Dinamico(int * distUntil, int numPlanetas, int numAConquistar, int sumDist)
{
    //Flags que iniciliza com termino
    if(numAConquistar == 0)
    {
        return sumDist;
    }
    if(numPlanetas == 0)
    {
        return 0;
    }

    //Inicialização e Setagem de Parametros para o metodo
    int maxDist = Inf;
    int sizeDistUntil = numPlanetas + 1;

    //Inicializa Vetor VetPos com com 0,1,2 ... Pn que indica todos os planetas que serão conquistados
    int sizeVetPos = numAConquistar;
    int * vetPos = malloc(sizeVetPos * sizeof(int));

    //Inicializa e seta parametros iniciais
    int flag = 0;
    int sizeMaxDistUntil = numAConquistar + 1;
    int * maxDistUntil = malloc(sizeMaxDistUntil * sizeof(int));
    int cont;
    for(cont=0; cont < sizeVetPos; cont++)
    {
        maxDistUntil[cont] = -Inf; // Inicializado como -infinito por conta das comparações
        vetPos[cont] = cont; // caso base inicial do vetor com planetas a serem conquistados
    }


    //Chama a função que calcula distancia máxima de cada arranjo possível e "anda" com esse arranjo para o próximo arranjo possível
    //Isso é feito até que o primeiro planeta escolhido seja o ultimo que pode ser escolhido
    while( vetPos[0] <= (numPlanetas-numAConquistar))
    {
        //Calcula distancia, se menor que anterior muda para a nova calculada
        int newDist = maxDistCalcDinamico(  maxDistUntil, sizeMaxDistUntil, flag,
                                            distUntil, sizeDistUntil,
                                            vetPos, sizeVetPos, numAConquistar);

        maxDist = menor(maxDist,newDist);
        flag = CaminhaDinamico(vetPos,sizeVetPos,numPlanetas);
    }

    free(vetPos);
    free(maxDistUntil);

    return maxDist;
}



