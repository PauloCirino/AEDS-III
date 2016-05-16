#include <stdio.h>
#include <stdlib.h>

int main(){

	long long int numHabitantes;
	scanf("%lld", &numHabitantes);
	while(numHabitantes != 0)
	{
		long long int totalWork = 0;
		long long int totalWineTile = 0;

		long long int cont;
		for(cont=0; cont<numHabitantes; cont++)
		{
			long long int quantWine;
			scanf("%lld", &quantWine);
			totalWineTile += quantWine ;
			totalWork += abs(totalWineTile);
		}
		printf("%lld\n",totalWork);
		scanf("%lld", &numHabitantes);
	}

	return 0;
}

