#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno_t {
	
	char nome[50], email[50];
	int idade;
};

int main ()
{

	int c = 0;

	aluno_t aluno[2];

	for(;c < 2; c++){
		printf("Nome do aluno: ");
		scanf("%s", aluno[c].nome);
		printf("Email do aluno: ");
		scanf("%s", aluno[c].email);		
		printf("Idade do aluno: ");
		scanf("%i", &aluno[c].idade);
	}

	for(c = 0; c < 2; c++){
		printf("Nome do aluno: %s", aluno[c].nome);
		printf("Email do aluno: %s", aluno[c].email);
		printf("Idade do aluno: %d", aluno[c].idade);
	}
}
