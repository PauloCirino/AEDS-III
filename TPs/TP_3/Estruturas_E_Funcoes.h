#include <stdlib.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0

typedef struct tree_aux * tree;
typedef struct node * leaf;

//Estrutura auxiliar de uma folha da árvore
struct node
{
    int val; // Valor Atural em calorias da árvore
    int prevSum;//Valor total de Calorias
    int posVet; // posição do Vetor de Calorias
    leaf sim; // Aponta para caminho onde escolhe esse valor
    leaf nao; // Aponta para o caminho onde não escolhe esse valor
    tree T; // Aponta para árvore a qual pertence
};

//Estrutura auxiliar de uma árvore
struct tree_aux
{
    int * vetCalories;//Vetor com as calorias
    int sizeVetCalories; // Tamanho do Vetor
    int idealDist; // Quantidade ideal de calorias
    leaf topo; // aponta para o topo da árvore

    int numThreads; // número atual de threads
    int maxNumThreads; // número máximo de threads
    int FLAG; // flag de se já encontrou um resultado

    pthread_mutex_t flagLock; // mutex que tranca variável FLAG
    pthread_mutex_t numThreadsLock; // mutex que tranca a variável numThreads
};

// Função que aloca e inicializa uma nova folha da arvore T
leaf addNode(int val, int prevSum, int posVet, tree T);

// Função que chama addNode alocando as 2 folhas que podem sair da folha mãe
void growTree(leaf L);

// Função seta todos os parametros iniciais de uma nova árvore, incluindo os mutex e o máximo de threads
tree initTree(int idealDist, int * Vet, int sizeVet, int maxNumThreads);

//Função recurssiva que constroi árvore e cria novas threads, de forma a calcular o resultado
void * NewSpawnTree (void * l);

// Função que libera a memoria de todas as folhas da árvore
void LiberaFolhas(leaf F);

// Função que libera memória da árvore assim como destroi os mutex e threads da arvore T
void liberaArvore(tree T);


