#include<stdio.h>
#include<stdlib.h>
#include "Algoritimos/Algoritimos.h"
#include "Grafos/Grafo.h"

/*
//Rotina principal dos algorítimos
*/

int main()
{
    int NumInstancias;
    scanf("%d",&NumInstancias);

    //Enquanto houver instancias
    int cont;
    for(cont=0; cont<NumInstancias; cont++)
    {
        //Inicializadores do Grafo
        int numVertices;//Quarteirões
        int numArestas;//Ruas
        int root;//Id saída
        int end;//Id chegada
        int distMaxBombeiros;
        int numBombeiros;

        //Leitura dos parametros inicializadores
        scanf("%d %d %d %d %d %d",
              &numVertices, &numArestas, &root, &end, &distMaxBombeiros, &numBombeiros);

        //Inicialização do Grafo
        grafo G = initGrafo(numVertices, numArestas, end, root, distMaxBombeiros, numBombeiros);

        //Leitura de todas as Arestas
        int cont_1;
        for(cont_1=0; cont_1<numArestas; cont_1++)
        {
            int IdFrom, IdTo;
            float fireProb;
            scanf("%d %d %f", &IdFrom, &IdTo, &fireProb);
            addAresta(G,IdFrom, IdTo, fireProb);
        }

	
        //Leitura de Todos os Corpos de Bombeiros
        for(cont_1=0; cont_1<numBombeiros; cont_1++)
        {
            int quarteiraoBombeiro;
            scanf("%d",&quarteiraoBombeiro);
            marcaDentroRaio(G,quarteiraoBombeiro);
	 }

        Dijkstra(G);
        printCaminho(G);
        liberaGrafo(G);
    }

    return 0;
}
