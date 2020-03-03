#include <stdio.h>
#include <stdlib.h>


int main ()
{

	int qtdeAlunos, i, *p, *idades;

	idades = malloc(sizeof(int));

	if (p == NULL) {
		printf("Deu pau ! ");
		exit(1);
	}

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
