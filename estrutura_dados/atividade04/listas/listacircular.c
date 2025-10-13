#include <stdio.h>
#include <stdlib.h> // para usar malloc e free

struct NO{
  int dado; // nosso dado
  struct NO* prox; // ponteiro para o nosso próximo nó que é onde está o próximo dado
};

int encontrar_minimo_circular(struct NO* no_inicial) {
    if (no_inicial == NULL) {
        return -1; // Lista vazia
    }
    int menor = no_inicial->dado; // inicializa o menor valor com o dado do primeiro nó
    struct NO* ponteiro_atual = no_inicial;
    
    do {  // Percorre a lista circular
        if (ponteiro_atual->dado < menor) {
            menor = ponteiro_atual->dado;
        }
        ponteiro_atual = ponteiro_atual->prox;
    } while (ponteiro_atual != no_inicial);
    return menor;
}



int main() {
    // Padronizado para 'No'
    struct NO* lista = NULL;
    
    // --- Criando o primeiro nó ---
    struct NO* primeiro_no = (struct NO*)malloc(sizeof(struct NO));
    primeiro_no->dado = 2;
    primeiro_no->prox = NULL;
    lista = primeiro_no; // A lista começa aqui

    // --- Adicionando mais nós para um teste melhor ---
    struct NO* segundo_no = (struct NO*)malloc(sizeof(struct NO));
    segundo_no->dado = 10;
    segundo_no->prox = NULL;
    primeiro_no->prox = segundo_no; // Conecta o primeiro ao segundo

    struct NO* terceiro_no = (struct NO*)malloc(sizeof(struct NO));
    terceiro_no->dado = 55;
    terceiro_no->prox = primeiro_no; // Conecta o terceiro ao primeiro, fechando o ciclo
    segundo_no->prox = terceiro_no; // Conecta o segundo ao terceiro

    // --- Chamando a função e exibindo o resultado ---
    printf("Procurando o menor valor na lista...\n");
    int resultado = encontrar_minimo_circular(lista);
    
    if (resultado != -1) {
        printf("O menor valor encontrado foi: %d\n", resultado);
    }

    // --- Liberando a memória alocada (boa prática) ---
    free(primeiro_no);
    free(segundo_no);
    free(terceiro_no);

    return 0;
}