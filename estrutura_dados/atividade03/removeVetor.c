#include <stdio.h>

int main() {
    int i, escolhaTamanho, removido;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &escolhaTamanho);

    int vetor[escolhaTamanho];

    printf("Digite os elementos do vetor:\n");
    for (i = 0; i < escolhaTamanho; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("Digite o index do número a ser removido: ");
    scanf("%d", &removido);

    if(removido >= 0 && removido < escolhaTamanho){
        for(i = removido; i < escolhaTamanho - 1; i++){
            vetor[i] = vetor[i + 1];
        }
        escolhaTamanho--;
        
        printf("Vetor atualizado:\n");
        for(i = 0; i < escolhaTamanho; i++){
            printf("%d ", vetor[i]);        
        }
        printf("\n");
    }
    else{
        printf("Indice invalido. Não foi removido do vetor");
    }

    return 0;
}
