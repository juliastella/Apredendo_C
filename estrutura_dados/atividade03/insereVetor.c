#include <stdio.h>

int main() {
    int i, pos, escolhaTamanho, novo;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &escolhaTamanho);

    int vetor[escolhaTamanho + 1]; 

    printf("Digite os elementos do vetor ordenado:\n");
    for (i = 0; i < escolhaTamanho; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("Digite o número a ser inserido: ");
    scanf("%d", &novo);

    pos = 0;
    while (pos < escolhaTamanho && vetor[pos] < novo) {
        pos++;
    }

    for (i = escolhaTamanho; i > pos; i--) {
        vetor[i] = vetor[i - 1];
    }

    vetor[pos] = novo;

    printf("Vetor após inserção:\n");
    for (i = 0; i <= escolhaTamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
