#include <stdio.h>
#include <stdlib.h> // Essencial para malloc, free e NULL

// --- DEFINIÇÃO DA ESTRUTURA ---
// (Como você já tinha definido, é o nó padrão da lista)
typedef struct No {
    int valor;
    struct No* prox;
} No;

// --- OPERAÇÃO DE INSERÇÃO ---
// Insere um elemento no FIM da fila
// (Esta é a sua versão corrigida, que funciona, mas é O(n))
void inserir_fila(No** frente, int numero) {
    // 1. Aloca memória para o 'novo' nó (Corrigido)
    No *novo = malloc(sizeof(No));
    
    // 2. Verifica se a alocação deu certo
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

// --- OPERAÇÃO DE REMOÇÃO ---
// Remove um elemento do INÍCIO da fila e retorna seu valor
// (Esta é a versão que corrige todos os erros da sua tentativa)
int remover_fila(No** frente) {
    // 1. VERIFICAÇÃO DE SEGURANÇA: (Corrigido)
    //    Primeiro checamos se a fila está vazia.
    if (*frente == NULL) {
        printf("Erro: Fila vazia, nao e possivel remover.\n");
        return -1; // Retorna um código de erro
    }
    
    // 2. LÓGICA DE REMOÇÃO (se não estiver vazia)
    
    // Guarda o nó que será removido (o primeiro)
    No* no_para_remover = *frente;
    
    // Guarda o valor que vamos retornar
    int valor_removido = no_para_remover->valor;
    
    // Atualiza o ponteiro 'frente' para apontar para o segundo nó
    *frente = no_para_remover->prox; // ou (*frente)->prox
    
    // 3. LIMPEZA DE MEMÓRIA: (Corrigido)
    //    Libera a memória do nó que foi removido
    free(no_para_remover);
    
    // 4. RETORNO: (Corrigido)
    //    Retorna o valor inteiro que estava no nó
    return valor_removido;
}

// --- FUNÇÃO MAIN PARA TESTAR ---
int main() {
    // A nossa fila é representada apenas por um ponteiro para o início
    No* minhaFila = NULL;

    printf("--- Teste de Fila (FIFO - First-In, First-Out) ---\n");

    // Inserindo 10, 20, 30
    printf("Inserindo 10...\n");
    inserir_fila(&minhaFila, 10);
    printf("Inserindo 20...\n");
    inserir_fila(&minhaFila, 20);
    printf("Inserindo 30...\n");
    inserir_fila(&minhaFila, 30);

    // Removendo (deve sair na ordem em que entrou)
    printf("\nRemovendo da fila...\n");
    printf("Valor removido: %d (Esperado: 10)\n", remover_fila(&minhaFila));
    printf("Valor removido: %d (Esperado: 20)\n", remover_fila(&minhaFila));

    // Teste de mistura (inserir no meio das remoções)
    printf("\nInserindo 40...\n");
    inserir_fila(&minhaFila, 40);

    printf("Valor removido: %d (Esperado: 30)\n", remover_fila(&minhaFila));
    printf("Valor removido: %d (Esperado: 40)\n", remover_fila(&minhaFila));

    // Teste de fila vazia
    printf("\nTestando remocao de fila vazia:\n");
    remover_fila(&minhaFila); // Deve imprimir a mensagem de erro

    return 0;
}