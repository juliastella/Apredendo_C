#include <stdio.h>
#include <stdlib.h> 


typedef struct No {
    int valor;
    struct No* prox;
} No;


void inserir_fila(No** frente, int numero) {
    // 1.  memória para o 'novo' nó (Corrigido)
    No *novo = malloc(sizeof(No));
    
    if (novo) {
        novo->valor = numero;
        novo->prox = NULL; // O novo nó é sempre o último

        // 3. Verifica se a fila está vazia
        if (*frente == NULL) {
            *frente = novo; // Se vazia, o novo nó é o primeiro
        } else {
            // 4. Se não está vazia, percorre até o fim
            No* aux = *frente;
            while (aux->prox != NULL) {
                aux = aux->prox;
            }
            aux->prox = novo; // Insere no final
        }
    } else {
        printf("Erro ao alocar memoria para inserir\n");
    }
}


int remover_fila(No** frente) {
    if (*frente == NULL) {
        printf("Erro: Fila vazia, nao e possivel remover.\n");
        return -1; 
    }
    
    No* no_para_remover = *frente;
    
    int valor_removido = no_para_remover->valor;
    
    
    *frente = no_para_remover->prox; /
    
    free(no_para_remover);
    
    
    return valor_removido;
}


int main() {
    No* minhaFila = NULL;

    printf("--- Teste de Fila (FIFO - First-In, First-Out) ---\n");

    printf("Inserindo 10...\n");
    inserir_fila(&minhaFila, 10);
    printf("Inserindo 20...\n");
    inserir_fila(&minhaFila, 20);
    printf("Inserindo 30...\n");
    inserir_fila(&minhaFila, 30);

    printf("\nRemovendo da fila...\n");
    printf("Valor removido: %d (Esperado: 10)\n", remover_fila(&minhaFila));
    printf("Valor removido: %d (Esperado: 20)\n", remover_fila(&minhaFila));

    printf("\nInserindo 40...\n");
    inserir_fila(&minhaFila, 40);

    printf("Valor removido: %d (Esperado: 30)\n", remover_fila(&minhaFila));
    printf("Valor removido: %d (Esperado: 40)\n", remover_fila(&minhaFila));

    printf("\nTestando remocao de fila vazia:\n");
    remover_fila(&minhaFila); 

    return 0;
}