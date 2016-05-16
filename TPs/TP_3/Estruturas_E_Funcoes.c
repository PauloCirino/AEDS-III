#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "Estruturas_E_Funcoes.h"

// Função que aloca e inicializa uma nova folha da arvore T
leaf addNode(int val, int prevSum, int posVet, tree T)
{
    leaf L = malloc( sizeof(struct node) ); // Aloca espaço na memória

    //Seta Parametros
    L->prevSum = prevSum;
    L->val = val;
    L->posVet = posVet;
    L->T = T;// Aponta para árvore que pertence

    //ainda não se sabe se as novas posições existirão, por isso apontam pra NULL
    L->sim = NULL;
    L->nao = NULL;

    return L;
}

// Função que chama addNode alocando as 2 folhas que podem sair da folha mãe
void growTree(leaf L)
{
    //Cresce com a árvore para a possibilidade de adicionar a comida atual na dieta
    L->sim = addNode(   L->T->vetCalories[L->posVet+1],
                        L->prevSum + L->val,
                        L->posVet + 1,
                        L->T);

    //Cresce com a árvore sem a possibilidade de adicionar a comida atual na dieta
    L->nao = addNode(   0,
                        L->prevSum + L->val,
                        L->posVet + 1,
                        L->T);
}

// Função seta todos os parametros iniciais de uma nova árvore, incluindo os mutex e o máximo de threads
tree initTree(int idealDist, int * Vet, int sizeVet, int maxNumThreads)
{
    tree T = malloc( sizeof (*T) ); // Aloca espaço da árvore
    T->vetCalories = malloc(sizeVet * sizeof(int)); // Aloca Espaço das folhas da árvore

    //Seta parametros
    T->sizeVetCalories = sizeVet;
    T->idealDist = idealDist;
    T->FLAG = TRUE;
    T->numThreads = 0;
    T->maxNumThreads = maxNumThreads;

    //Inicializa os Mutex
    pthread_mutex_init(&T->flagLock, NULL);
    pthread_mutex_init(&T->numThreadsLock, NULL);

    //Seta valores do vetor de calorias
    int cont;
    for(cont=0; cont<sizeVet; cont++)
    {
        T->vetCalories[cont] = Vet[cont];
    }

    //Aloca e seta parametros no topo da árvore
    T->topo = malloc(sizeof(struct node));
    T->topo->prevSum = 0;
    T->topo->val = 0;
    T->topo->posVet = -1;
    T->topo->sim = NULL;
    T->topo->nao = NULL;
    T->topo->T = T;

    //Aloca 2 novas folhas (Sim e Não) para crescimento da árvore
    growTree(T->topo);

    return T; // retorna essa árvore
}


//Função recurssiva que constroi árvore e cria novas threads, de forma a calcular o resultado
void * NewSpawnTree (void * l)
{
    leaf L = (leaf) l; // Faz casting

    //Confere se pode e/ou nescessita crescimento da árvore
    if( ( L->posVet < L->T->sizeVetCalories) &&
            ( L->prevSum < L->T->idealDist ) &&
            ( L->T->FLAG == TRUE ) )
    {
        growTree(L); // Aloca novas posições
        int flag = 0;

        //Inicio seção crítica
        pthread_mutex_lock(&L->T->numThreadsLock); // Tranca mutex
        if(L->T->numThreads < L->T->maxNumThreads)
        {
            L->T->numThreads ++;
            flag = 1;
        }
        pthread_mutex_unlock(&L->T->numThreadsLock); // Libera mutex

        if(flag)// Confere possibilidade de criar nova thread
        {
            pthread_t NAO;
            (void) pthread_create(&NAO, NULL, NewSpawnTree, (void *) L->nao);
            (*NewSpawnTree)((void *) L->sim); // Utilizando o ponteiro da função HAHA
            pthread_join(NAO, NULL);
        }

        else // Caso Nova thread não possa ser criada, faz de maneira funcional mesmo
        {
            NewSpawnTree(L->sim);
            NewSpawnTree(L->nao);
        }

        //Seção crítica
        pthread_mutex_lock(&L->T->numThreadsLock); // Tranca Mutex
        L->T->numThreads -= (1+flag);
        pthread_mutex_unlock(&L->T->numThreadsLock); // Libera Mutex
    }

    else if( L->prevSum  == L->T->idealDist ) // Confere se resultado já foi encontrado
    {
        //Seção crítica
        pthread_mutex_lock(&L->T->flagLock);// Tranca Mutex
        L->T->FLAG = 0;
        pthread_mutex_unlock(&L->T->flagLock); // Libera Mutex
    }
    return 0;
}


// Função que libera a memoria de todas as folhas da árvore
void LiberaFolhas(leaf F)
{
    //Passa por todos os elementos da árvore excluindo todos
    if(F != NULL)
    {
        leaf Sim = F->sim;
        leaf Nao = F->nao;

        free(F);
        LiberaFolhas(Sim);
        LiberaFolhas(Nao);
    }
}

// Função que libera memória da árvore assim como destroi os mutex e threads da arvore T
void liberaArvore(tree T)
{
    free(T->vetCalories);//Libera vetor de calorias
    LiberaFolhas(T->topo);//Libera folhas

    //Destroi os Mutex
    pthread_mutex_destroy(&T->flagLock);
    pthread_mutex_destroy(&T->numThreadsLock);
    free(T);
}

