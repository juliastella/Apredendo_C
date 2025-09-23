#include <stdlib.h>

// --- Bubble Sort ---
void bubbleSort(int vetor[], int tamanho, int *comparacoes, int *trocas) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            (*comparacoes)++; // Incrementa a comparação
            if (vetor[j] > vetor[j + 1]) {
                (*trocas)++; // Incrementa a troca APENAS se ela ocorrer
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// --- Selection Sort ---
void selectionSort(int vetor[], int tamanho, int *comparacoes, int *trocas) {
    for (int i = 0; i < tamanho - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < tamanho; j++) {
            (*comparacoes)++; // Incrementa a comparação
            if (vetor[j] < vetor[min_idx]) {
                min_idx = j;
            }
        }
        // A troca só ocorre se um novo mínimo for encontrado
        if (min_idx != i) {
            (*trocas)++; // Incrementa a troca APENAS se ela ocorrer
            int temp = vetor[i];
            vetor[i] = vetor[min_idx];
            vetor[min_idx] = temp;
        }
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

    int *vetorOriginal = (int *)malloc(escolhaTamanho * sizeof(int));
    if (vetorOriginal == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < escolhaTamanho; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &vetorOriginal[i]);
    }

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

    int comparacoesBubble = 0, trocasBubble = 0;
    int comparacoesSelection = 0, trocasSelection = 0;

    bubbleSort(vetorBubble, escolhaTamanho, &comparacoesBubble, &trocasBubble);
    selectionSort(vetorSelection, escolhaTamanho, &comparacoesSelection, &trocasSelection);

    printf("\n--- Bubble Sort ---\n");
    printf("Vetor ordenado: ");
    imprimirVetor(vetorBubble, escolhaTamanho);
    printf("Comparações: %d\n", comparacoesBubble);
    printf("Trocas: %d\n", trocasBubble);

    printf("\n--- Selection Sort ---\n");
    printf("Vetor ordenado: ");
    imprimirVetor(vetorSelection, escolhaTamanho);
    printf("Comparações: %d\n", comparacoesSelection);
    printf("Trocas: %d\n", trocasSelection);

    printf("\n--- Resultado Final ---\n");
    if (trocasBubble < trocasSelection) {
        printf("Bubble Sort fez menos trocas.\n");
    } else if (trocasBubble > trocasSelection) {
        printf("Selection Sort fez menos trocas.\n");
    } else {
        printf("Ambos fizeram o mesmo número de trocas.\n");
    }
    printf("O número de comparações foi idêntico para ambos: %d.\n", comparacoesBubble);


    free(vetorOriginal);
    free(vetorBubble);
    free(vetorSelection);

    return 0;
}
