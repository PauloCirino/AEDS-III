#include <stdio.h>
#include <stdlib.h>

#define Vertex int

typedef struct {
   Vertex v, w;
} Arc;

/*Matriz de Adjacência*/
struct digraph {
   int V;
   int A;
   int **adj;
};

/*Aloca matriz de adjacencia*/
int **MATRIXint( int r, int c, int val) {
   Vertex i, j;
   int **m = malloc( r * sizeof (int *));
   for (i = 0; i < r; i++)
      m[i] = malloc( c * sizeof (int));
   for (i = 0; i < r; i++)
      for (j = 0; j < c; j++)
         m[i][j] = val;
   return m;
}


typedef struct digraph *Digraph;
/*Retorna um diagrafo com todos os vertices e sem nenhum aresta*/
Digraph DIGRAPHinit( int V) {
   Digraph G = malloc( sizeof *G);
   G->V = V;
   G->A = 0;
   G->adj = MATRIXint( V, V, 0);
   return G;
}


/*Insere Aresta entre v e w */
void DIGRAPHinsertA( Digraph G, Vertex v, Vertex w) {
    if (G->adj[v][w] == 0) {
      G->adj[v][w] = 1;
      G->A++;
   }
}


/*Remove aresta entre v e W*/
void DIGRAPHremoveA( Digraph G, Vertex v, Vertex w) {
    if (G->adj[v][w] == 1) {
      G->adj[v][w] = 0;
      G->A--;
   }
}

/*Imprime o diagrafo*/
void DIGRAPHshow( Digraph Grafo) {
   Vertex v, w;
   for (v = 0; v < Grafo->V; v++) {
      printf( "%2d:", v);
      for (w = 0; w < Grafo->V; w++)
         if (Grafo->adj[v][w] == 1)
            printf( " %2d", w);
      printf( "\n");
   }
}


int CalcRespota(Digraph Grafo){
    int cont = 0;
    int v, w;
    for (v = 0; v < Grafo->V; v++) {
      for (w = 0; w < Grafo->V; w++)
         if (Grafo->adj[v][w] == 1)
            cont++;
    }

    return cont;
}

int main(){


    int numInputs;
    scanf("%d", &numInputs);

    int * Respostas;
    Respostas = malloc((int) numInputs*sizeof(int));

    int cont;
    for(cont = 0 ; cont < numInputs ; cont++){
        int initPos;
        scanf( "%d",&initPos);

        int numArestas, numGraphs;
        scanf( "%d %d", &numGraphs, &numArestas);

        Digraph Grafo = DIGRAPHinit( numGraphs);
        int cont_2;
        for(cont_2 = 0; cont_2<numArestas; cont_2++){
            int val_1, val_2;
            scanf( "%d %d", &val_1, &val_2);
            DIGRAPHinsertA(Grafo, val_1, val_2);
            DIGRAPHinsertA(Grafo, val_2, val_1);
        }

        Respostas[cont] = CalcRespota(Grafo);

    }

    for(cont = 0; cont < numInputs; cont++){
        printf("%d\n",Respostas[cont]);
    }

    return 0;
}
