#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int vetor[], int tamanho, int *comparacoes) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            (*comparacoes)++;
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int quickSort(int vetor[], int inicio, int fim, int *comparacoes) {
    if (inicio < fim) {
        int pivo = vetor[fim];
        int i = inicio - 1;

        for (int j = inicio; j < fim; j++) {
            (*comparacoes)++;
            if (vetor[j] < pivo) {
                i++;
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }

        int temp = vetor[i + 1];
        vetor[i + 1] = vetor[fim];
        vetor[fim] = temp;

        int indicePivo = i + 1;

        quickSort(vetor, inicio, indicePivo - 1, comparacoes);
        quickSort(vetor, indicePivo + 1, fim, comparacoes);
    }
    return *comparacoes;
}

void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int escolhaTamanho;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &escolhaTamanho);

    int *vetorOriginal = (int *)malloc(escolhaTamanho * sizeof(int));
    if (vetorOriginal == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < escolhaTamanho; i++) {
        printf("Digite o elemento %d: ", i);
        scanf("%d", &vetorOriginal[i]);
    }

    int *vetorBubble = (int *)malloc(escolhaTamanho * sizeof(int));
    int *vetorQuick = (int *)malloc(escolhaTamanho * sizeof(int));
    if (vetorBubble == NULL || vetorQuick == NULL) {
        printf("Erro ao alocar memória.\n");
        free(vetorOriginal);
        return 1;
    }

    for (int i = 0; i < escolhaTamanho; i++) {
        vetorBubble[i] = vetorOriginal[i];
        vetorQuick[i] = vetorOriginal[i];
    }

    int comparacoesBubble = 0, comparacoesQuick = 0;

    bubbleSort(vetorBubble, escolhaTamanho, &comparacoesBubble);
    quickSort(vetorQuick, 0, escolhaTamanho - 1, &comparacoesQuick);

    printf("\nBubble Sort:\n");
    imprimirVetor(vetorBubble, escolhaTamanho);
    printf("Comparações: %d\n", comparacoesBubble);

    printf("\nQuick Sort:\n");
    imprimirVetor(vetorQuick, escolhaTamanho);
    printf("Comparações: %d\n", comparacoesQuick);

    printf("\nResultado da comparação:\n");
    if (comparacoesBubble < comparacoesQuick) {
        printf("Bubble Sort fez menos comparações.\n");
    } else if (comparacoesBubble > comparacoesQuick) {
        printf("Quick Sort fez menos comparações.\n");
    } else {
        printf("Ambos fizeram o mesmo número de comparações.\n");
    }

    free(vetorOriginal);
    free(vetorBubble);
    free(vetorQuick);

    return 0;
}
