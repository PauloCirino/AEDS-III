#include <stdio.h>
#include <stdlib.h>



void putInFront(char * L, int sizeL, int posNewTop)
{
   char * L2 = malloc(sizeL * sizeof(char));
   L2[0] = L[posNewTop];
   //printf("%c ",L2[0]);

   int cont;
   for(cont=0; cont<posNewTop; cont++)
   {
       L2[cont+1] = L[cont];
       //printf("%c ",L2[cont+1]);
   }
   for(cont=posNewTop+1; cont<sizeL; cont++)
   {
       L2[cont] = L[cont];
       //printf("%c ",L2[cont]);
   }

   for(cont=0;cont<sizeL; cont++)
   {
       L[cont] = L2[cont];
   }
}

void printVetChar(char *V, int sizeV)
{
    int cont;
    for(cont=0; cont<sizeV; cont++)
    {
        printf("%c ",V[cont]);
    }
    printf("\n");
}


int main()
{
    //FILE * arq = fopen("Input.txt", "r");

    int numVal;
    //fscanf(arq, "%d", &numVal);
    scanf("%d", &numVal);
    int Inst = 0;
    while(numVal != 0)
    {
        Inst++;
        int cont;
        char * Lista = malloc(26 * sizeof(char));
        for(cont=0; cont<26; cont++)
        {
           Lista[cont] = (char)(65+cont);
        }

        //printf("NumVal = %d\n\n",numVal);

        printf("Instancia %d\n", Inst);
        for(cont=0; cont<numVal; cont++)
        {
            //printVetChar(Lista, 26);
            int pos;
            //fscanf(arq,"%d",&pos);
            scanf("%d",&pos);
            printf("%c",Lista[pos-1]);
            putInFront(Lista, 26,pos-1);
            //printf("\n\n\n");
        }

        free(Lista);

        printf("\n\n");
        //fscanf(arq,"%d", &numVal);
        scanf("%d", &numVal);
    }

    return 0;
}
