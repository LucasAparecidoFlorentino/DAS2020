#include <stdio.h>

int main()
{
	int idade, *i;
	
	i = &idade;
	
	printf("Digite sua idade: \n");
	
	scanf("%i", i);
	
	if(idade>=18)
	{
		printf("Acesso permitido \n");
	}
	else
	{
		printf("Acesso negado \n");
	}
	
	return 0;
}
