#include <stdio.h>

#include "teste.h"


int main()
{
	int a, b, *c, g;
	
	int abobrinha[10];
	
	c = &a;
	c = 100;
	a = 5;
	b = 10;
	
	scanf("%i", &g);
	
	printf("Olá mundo ! %i %i %i %p %p\n", a, b, g, &abobrinha[0], &abobrinha[1]);
	
	printf("%p %p\n", abobrinha, abobrinha+1);

	return 0;
}
