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

void selectionSort(int vetor[], int tamanho, int *comparacoes) {
    for (int i = 0; i < tamanho - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < tamanho; j++) {
            (*comparacoes)++;
            if (vetor[j] < vetor[min_idx]) {
                min_idx = j;
            }
        }
        int temp = vetor[i];
        vetor[i] = vetor[min_idx];
        vetor[min_idx] = temp;
    }
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

    // Aloca dinamicamente o vetor original
    int *vetorOriginal = (int *)malloc(escolhaTamanho * sizeof(int));
    if (vetorOriginal == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Preenche o vetor com os elementos digitados
    for (int i = 0; i < escolhaTamanho; i++) {
        printf("Digite o elemento %d: ", i);
        scanf("%d", &vetorOriginal[i]);
    }

    // Cria cópias para os dois algoritmos
    int *vetorBubble = (int *)malloc(escolhaTamanho * sizeof(int));
    int *vetorSelection = (int *)malloc(escolhaTamanho * sizeof(int));
    if (vetorBubble == NULL || vetorSelection == NULL) {
        printf("Erro ao alocar memória para os vetores de ordenação.\n");
        free(vetorOriginal);
        return 1;
    }

    for (int i = 0; i < escolhaTamanho; i++) {
        vetorBubble[i] = vetorOriginal[i];
        vetorSelection[i] = vetorOriginal[i];
    }

    int comparacoesBubble = 0, comparacoesSelection = 0;

    bubbleSort(vetorBubble, escolhaTamanho, &comparacoesBubble);
    selectionSort(vetorSelection, escolhaTamanho, &comparacoesSelection);

    printf("\nBubble Sort:\n");
    imprimirVetor(vetorBubble, escolhaTamanho);
    printf("Comparações: %d\n", comparacoesBubble);

    printf("\nSelection Sort:\n");
    imprimirVetor(vetorSelection, escolhaTamanho);
    printf("Comparações: %d\n", comparacoesSelection);

    printf("\nResultado da comparação:\n");
    if (comparacoesBubble < comparacoesSelection) {
        printf("Bubble Sort fez menos comparações.\n");
    } else if (comparacoesBubble > comparacoesSelection) {
        printf("Selection Sort fez menos comparações.\n");
    } else {
        printf("Ambos fizeram o mesmo número de comparações.\n");
    }

    // Libera memória
    free(vetorOriginal);
    free(vetorBubble);
    free(vetorSelection);

    return 0;
}
