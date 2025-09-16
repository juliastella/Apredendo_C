#include <stdio.h>

int somaRecursiva(int vetor[], int tamanho) {
    if (tamanho == 0) {
        return 0;
    } else {
        return vetor[0] + somaRecursiva(vetor + 1, tamanho - 1);
    }
}

int main(){

    int vertor_int[] = {7,3,5,8}; 
    
    int tamanho = sizeof(vertor_int) / sizeof(vertor_int[0]);

    int resultado = somaRecursiva(vertor_int, tamanho);
    printf("Soma dos elementos: %d\n", resultado);

    return 0;
}