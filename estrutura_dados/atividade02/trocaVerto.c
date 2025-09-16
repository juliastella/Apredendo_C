#include <stdio.h>

int main() {
    int vertor_int[] = {7, 3, 5, 8};
    int tamanho = sizeof(vertor_int) / sizeof(vertor_int[0]);
    int i, temp;

    for (i = 0; i < tamanho / 2; i++) {
        temp = vertor_int[i];
        vertor_int[i] = vertor_int[tamanho - 1 - i];
        vertor_int[tamanho - 1 - i] = temp;
    }

    for (i = 0; i < tamanho; i++) {
        printf("%d ", vertor_int[i]);
    }
    printf("\n");

    return 0;
}
