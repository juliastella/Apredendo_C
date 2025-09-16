#include <stdio.h>

int main() {
    int i, j, escolhaTamanho, repetidos = 0, maiorRepeticao = 1;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &escolhaTamanho);

    int vertor_int[escolhaTamanho];

    for (i = 0; i < escolhaTamanho; i++) {
        printf("Digite o elemento %d: ", i);
        scanf("%d", &vertor_int[i]);
    }

    for (i = 0; i < escolhaTamanho; i++) {
        int contador = 1;
        for (j = i + 1; j < escolhaTamanho; j++) {
            if (vertor_int[i] == vertor_int[j]) {
                contador++;
                if (repetidos == 0) {
                    printf("Elemento repetido encontrado no índice %d\n", j);
                    repetidos = 1;
                }
            }
        }
        if (contador > maiorRepeticao) {
            maiorRepeticao = contador;
        }
    }

    if (repetidos == 0) {
        printf("Nenhum elemento se repete.\n");
    }

    printf("Maior número de repetições: %d\n", maiorRepeticao);

    return 0;
}
