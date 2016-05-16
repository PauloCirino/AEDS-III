#ifndef FORCABRUTA_H_INCLUDED
#define FORCABRUTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define Inf INT_MAX

void Caminha(int * planetasEscolhidos, int sizePlanetasEscolhidos, int numPlanetas);

int maxDistCalc(int * distVet, int sizeDistVet, int * vetPos, int sizeVetPost, int numAConquistar);

int ForcaBruta(int * distVet, int numPlanetas, int numAConquistar, int sumDist);

#endif // FORCABRUTA_H_INCLUDED
