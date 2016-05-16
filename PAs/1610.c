#include <stdio.h>
#include <stdlib.h>

#define BRANCO 0
#define CINZA -10
#define PRETO 10
#define Vermelho 20

int cycle = 0;

typedef struct node * lista;
struct node
{
    int info;
    lista next;
};

typedef struct grafo_aux *grafo;
struct grafo_aux
{
    int numVertices;
    int numArestas;
    int * grau;
    int * cor;
    lista * listaAdj;
};


//Insere no Fim da Lista
lista newNode(int newInfo, lista next)
{
    lista aux = malloc(sizeof(struct node));
    aux->info = newInfo;
    aux->next = next;
    return aux;
}


grafo grafoInit(int numVertices)
{
    grafo G = malloc(sizeof(*G));
    G->numVertices = numVertices;
    G->numArestas = 0;
    G->listaAdj = malloc(numVertices * sizeof(lista));
    G->cor = malloc(numVertices * sizeof(int));
    G->grau = malloc(numVertices * sizeof(int));

    int cont;
    for(cont = 0; cont < numVertices ; cont++)
    {
        G->cor[cont] = BRANCO;
        G->grau[cont] = 0;
        G->listaAdj[cont] = NULL;
    }
    return G;
}

void grafoInsert(grafo G, int inputVertice, int outputVertice)
{
    int posInputVertice = inputVertice-1;
    lista aux = G->listaAdj[posInputVertice];
    while(aux != NULL)
    {
        if(aux->info == outputVertice)
        {
            return;
        }
        else
        {
            aux = aux->next;
        }
    }
    G->numArestas++;
    G->grau[posInputVertice]++;
    G->listaAdj[posInputVertice] = newNode(outputVertice - 1 , G->listaAdj[posInputVertice]);
}

void printElemList(lista L)
{
    lista aux = L;
    while(aux != NULL)
    {
        printf("%d  ", aux->info+1);
        aux = aux->next;
    }
}

void printGrafo(grafo G)
{
    printf("\n\n\n");
    int cont;
    for(cont = 0 ; cont<G->numVertices; cont++)
    {
        printf("%d : ", cont+1);
        printElemList(G->listaAdj[cont]);
        printf("\n");
    }
    printf("\n");
}


int cicloAux(grafo G, int pos)
{
    lista aux;
    G->cor[pos] = CINZA;
    for(aux = G->listaAdj[pos]; aux != NULL; aux=aux->next)
    {
        if(G->cor[aux->info] == BRANCO)
        {
            cicloAux(G,aux->info);
        }
        else if(G->cor[aux->info] == CINZA)
        {
            cycle = 10;
            return 10;
        }
    }
    G->cor[pos]=PRETO;
    return 0;
}


int Ciclo( grafo G)
{
    cycle = 0;
    int pos;
    for(pos = 0; pos < G->numVertices; pos++)
    {
        if(G->cor[pos] == BRANCO)
        {
            int helper = cicloAux(G,pos);
           if(helper == 1)
            {
                return 1;
            }
        }
    }
    return 0;
}


void Resposta(grafo G)
{
    Ciclo(G);
    if(cycle)
    {
        printf("SIM\n");
    }
    else
    {
        printf("NAO\n");
    }
}

int main()
{
    int numCases;
    scanf("%d",&numCases);

    int cont_0;
    for(cont_0=0; cont_0<numCases; cont_0++)
    {
        //printf("passei cont = %d \t",cont_0);
        int numDoc, numDep;
        scanf("%d %d", &numDoc, &numDep);
        //printf("%d %d\n",numDoc, numDep);

        grafo G = grafoInit(numDoc);
        //printGrafo(G);
        int cont_1;
        for(cont_1=0; cont_1<numDep; cont_1++)
        {
            //printf("Interno cont = %d\t", cont_1);
            int valFrom, valTo;
            scanf("%d %d", &valFrom, &valTo);
            //printf("%d %d \n",valFrom,valTo);
            grafoInsert(G,valFrom,valTo);
        }
        Resposta(G);
        //printf("\n\n\n\n");
        //printGrafo(G);
    }
    return 0;
}

