#include <stdio.h>
#include <stdlib.h>

int valido(int val)
{
    int * FLAGS = calloc(10, sizeof(int));

    while(val > 0)
    {
        int aux = val%10;
        if(FLAGS[aux] == 1)
        {
            //printf("Passei aqui");
            return -1;
        }
        FLAGS[aux] = 1;
        val = val/10;
    }

    free(FLAGS);
    return 1;
}

int main()
{
    int lowerBound, upperBound;
    while( scanf("%d %d", &lowerBound, &upperBound) != EOF )
    {
        int total=0;

        int val;
        for(val=lowerBound; val <= upperBound ; val++)
        {
            if(valido(val) == 1)
            {
                //printf("VAL = %d \n", val);
                total++;
            }
        }
        printf("%d\n", total);
    }
    return 0;
}