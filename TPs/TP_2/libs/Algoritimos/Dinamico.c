#include <stdlib.h>

#include "Algoritimos/Dinamico.h"
#include "Auxiliar/auxLib.h"

//Fun��o que caminha com a posi��o
int CaminhaDinamico(int * planetasEscolhidos, int sizePlanetasEscolhidos, int numPlanetas)
{

    //Percorre vetor at� encontrar planeta que pode andar
    int cont;
    int flag = 1;
    for(cont = 0; cont < sizePlanetasEscolhidos && flag == 1; cont++)
    {
        int maxPos = numPlanetas - 1 - cont;// calcula ultima posi��o que esse planeta pode assumir
        int pos = sizePlanetasEscolhidos- 1 - cont;// calcula posi��o atual do planeta
        if(planetasEscolhidos[pos] < maxPos)// caso esse planeta n�o esjeja em sua �ltima posi��o poss�vel a flag muda
        {
            flag = -1;
        }
    }

    // Anda com o planeta incial
    int pos = sizePlanetasEscolhidos - cont;
    planetasEscolhidos[pos] ++;

    //Todos os planetas que s�o ap�s eles s�o iniciado imediamente apos
    for(pos++; pos<sizePlanetasEscolhidos; pos++)
    {
        planetasEscolhidos[pos] = planetasEscolhidos[pos-1] + 1;
    }

    //retorna posi��o do primeiro que andou
    return (sizePlanetasEscolhidos - cont);
}

//Calcula vetor maxDistUntil a partir da posi��o flag que � a utima posi��o alterada
int maxDistCalcDinamico( int * maxDistUntil, int sizeMaxDistUntil, int flag,
                         int * distUntil, int sizeDistUntil,
                         int * vetPos, int sizeVetPos, int numAConquistar)
{
    //Se � a primeira posi��o que andou
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
        //Dist�ncia de um subcaminho � a dist�ncia total at� o ponto final menos a dist�ncia total at� seu ponto inicial
        int newDist =  distUntil[vetPos[cont]] - distUntil[vetPos[cont-1]];
        maxDist = maior(maxDist,newDist);
        maxDistUntil[cont] = maxDist;
    }

    //Ultima itera��o
    int newDist =  distUntil[sizeDistUntil-1] - distUntil[vetPos[cont-1]];
    maxDist = maior(maxDist,newDist);
    maxDistUntil[cont] = maxDist;

    //Retorna maior subdist�ncia do caminho
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

    //Inicializa��o e Setagem de Parametros para o metodo
    int maxDist = Inf;
    int sizeDistUntil = numPlanetas + 1;

    //Inicializa Vetor VetPos com com 0,1,2 ... Pn que indica todos os planetas que ser�o conquistados
    int sizeVetPos = numAConquistar;
    int * vetPos = malloc(sizeVetPos * sizeof(int));

    //Inicializa e seta parametros iniciais
    int flag = 0;
    int sizeMaxDistUntil = numAConquistar + 1;
    int * maxDistUntil = malloc(sizeMaxDistUntil * sizeof(int));
    int cont;
    for(cont=0; cont < sizeVetPos; cont++)
    {
        maxDistUntil[cont] = -Inf; // Inicializado como -infinito por conta das compara��es
        vetPos[cont] = cont; // caso base inicial do vetor com planetas a serem conquistados
    }


    //Chama a fun��o que calcula distancia m�xima de cada arranjo poss�vel e "anda" com esse arranjo para o pr�ximo arranjo poss�vel
    //Isso � feito at� que o primeiro planeta escolhido seja o ultimo que pode ser escolhido
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



