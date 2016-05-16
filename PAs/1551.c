#include <stdio.h>
#include <stdlib.h>


int Analise(int * vetorLetras, char letra){
    int aux = letra-97;
    if(aux>=0 && aux <=25){
            if(vetorLetras[aux] == 0){
                vetorLetras[aux] = 1;
                return 1;
            }
    }
    return 0;
}

int main()
{
    int numFrases;
    scanf("%d",&numFrases);


    int cont;
    for(cont=0; cont<numFrases; cont++){
        fflush(stdout);
        int letrasUtilizadas[26];
        int cont_1;
        for(cont_1=0; cont_1<26; cont_1++){
            letrasUtilizadas[cont_1] = 0;
        }

        int flag = 0;
        char C;
        scanf("%c",&C);

        while(C == '\n')
        {
            scanf("%c",&C);
        }

        while(C != '\n')
        {
            while(C == ' ')
            {
                scanf("%c",&C);
            }

            while(C != '\n')
            {
                flag += Analise(letrasUtilizadas,C);
                scanf("%c",&C);
            }
        }


        if(flag == 26){
            printf("frase completa\n");
        }
        else if(flag >= 13){
            printf("frase quase completa\n");
        }
        else{
            printf("frase mal elaborada\n");
        }

    }


    return 0;
}



