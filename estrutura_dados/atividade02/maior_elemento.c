#include <stdio.h>

int main() {
    int linhas, colunas;
    int i, j;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &colunas);

    int matriz[linhas][colunas];

    printf("\nDigite os elementos da matriz:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    int maior = matriz[0][0];

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
        }
    }

    printf("\nO maior elemento da matriz é: %d\n", maior);

    return 0;
}
