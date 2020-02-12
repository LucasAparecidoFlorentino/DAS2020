#include <stdio.h>

int main()
{
	int idade;
	char *msgs[] = {"menor de idade \n", "maior de idade \n"};
	
	scanf("%i", &idade);
	
	printf("%s", msgs[idade >= 18] );
	
	return 0;
}
