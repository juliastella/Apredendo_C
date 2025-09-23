#include <stdio.h>

int main()
{
    int i, escolhaTamanho, chave;
    int busca = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &escolhaTamanho);

    int vertorN[escolhaTamanho];

    for (i = 0; i < escolhaTamanho; i++)
    {
        printf("Digite o elemento %d: ", i);
        scanf("%d", &vertorN[i]);
    }

    printf("\nDigite o valor que deseja buscar: ");
    scanf("%d", &chave);

    while (busca < escolhaTamanho && vertorN[busca] != chave)
    {
        busca++;
    }

    if (busca == escolhaTamanho)
    {
        printf("Índice retornado: -1 (elemento não encontrado)\n");
    }
    else
    {
        printf("Elemento encontrado no índice: %d\n", busca);
    }

    return 0;
}
