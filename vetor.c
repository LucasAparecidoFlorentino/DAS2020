#include <stdio.h>

#define N 10

int main ()
{
	int idades[N], qtdeAlunos, i;

	printf("Quantidade de alunos: ");
	scanf("%i", &qtdeAlunos);

	for(i=0; i<qtdeAlunos; i++){
		printf("idade %i: ", i);
		scanf("%i", &idades[i]);
	}

	for(i=0; i<qtdeAlunos; i++)
		printf("idade %i: %i\n", i, idades[i]);
	
	return 0;


}
