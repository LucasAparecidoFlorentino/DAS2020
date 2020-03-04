#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <list>

using namespace std;

struct aluno_t {
	char nome[50];
	int idade;
};

int main ()
{
	list<aluno_t> lalunos;
	aluno_t a;

	strcpy(a.nome, "lucas");
	a.idade = 19;

	lalunos.push_back(a);

	return 0;
}
