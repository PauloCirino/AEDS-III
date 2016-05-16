#ifndef DINAMICO_H_INCLUDED
#define DINAMICO_H_INCLUDED

int CaminhaDinamico(int * planetasEscolhidos, int sizePlanetasEscolhidos, int numPlanetas);

int maxDistCalcDinamico( int * maxDistUntil, int sizeMaxDistUntil, int flag,
                         int * distUntil, int sizeDistUntil,
                         int * vetPos, int sizeVetPos, int numAConquistar);

int Dinamico(int * distUntil, int numPlanetas, int numAConquistar, int sumDist);


#endif // DINAMICO_H_INCLUDED
