#include <stdio.h>

int main()
{
    const int LINHA=10;
    const int COLUNA=60;
    char nomeVendedores[LINHA][COLUNA];
    int l;

    for(int l=0; l<LINHA; l++)
    {
        printf("Digite o nome do %d vendedor: ", (l+1));
        std::cin >> nomeVendedores[l];
        printf("\n");
    }

    for(int l=0; l<LINHA; l++)
    {
        printf("%s\n", nomeVendedores[l]);
    }
}
