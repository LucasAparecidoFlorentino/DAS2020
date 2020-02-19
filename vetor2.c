#include <stdio.h>

#define N 10

int main ()
{
	int idades[N], qtdeAlunos, i, *p;

	printf("Quantidade de alunos: ");
	scanf("%i", &qtdeAlunos);

	p = idades;
	for(i=0; i<qtdeAlunos; i++){
		printf("idade %i: ", i);
		scanf("%i", p);
		p++;
	}
	
	
	p = idades;
	for(i=0; i<qtdeAlunos; i++)
		printf("idade %i: %i\n", i, *p);
		p++;
	
	return 0;

}
