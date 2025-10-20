#include <stdio.h>

#define TAM_MAX 100

struct Fila {
    int inicio;
    int fim;
    int vetor[TAM_MAX];
};

int vazia(struct Fila* p) {
  if (p->inicio == p->fim)
  {
    return 1; // se estiver vazia, retorno verdadeiro 
  }  
  else
  {
    return 0; // se nao estiver vazia, retorno falso
  }
}

void insere(struct Fila* p, int M) {
    if (vazia(p)) {
        printf("Fila cheia!\n");
    } else {
        // 1. Coloca o valor M no vetor, na posição 'fim'
        p->vetor[p->fim] = M;
        
        // 2. Avança o 'fim' para a próxima posição
        p->fim = (p->fim + 1) % TAM_MAX;
    }
}

int remover(struct Fila* p) {
    // 1. Verificação de segurança
    if (vazia(p)) {
        printf("Fila vazia!\n");
        return -1; // Retorna um código de erro
    } else {
        // 2. Guarda o valor que está no 'inicio'
        int valor_removido = p->vetor[p->inicio];

        // 3. Avança o 'inicio' para a próxima posição (com a mágica do círculo)
        p->inicio = (p->inicio + 1) % TAM_MAX;
        
        // 4. Retorna o valor que guardamos
        return valor_removido;
    }
}

int main() {
    struct Fila minhaFila;
    minhaFila.inicio = 0;
    minhaFila.fim = 0;

    printf("--- Teste de Fila (Vetor Circular) ---\n");
    printf("Inserindo 10, 20, 30...\n");
    insere(&minhaFila, 10);
    insere(&minhaFila, 20);
    insere(&minhaFila, 30);

    printf("Removendo: %d (Esperado: 10)\n", remover(&minhaFila));
    printf("Removendo: %d (Esperado: 20)\n", remover(&minhaFila));

    printf("\nInserindo 40, 50...\n");
    insere(&minhaFila, 40);
    insere(&minhaFila, 50);

    printf("Removendo: %d (Esperado: 30)\n", remover(&minhaFila));
    printf("Removendo: %d (Esperado: 40)\n", remover(&minhaFila));
    printf("Removendo: %d (Esperado: 50)\n", remover(&minhaFila));

    printf("\nTestando fila vazia:\n");
    if(vazia(&minhaFila)) {
        printf("OK: Fila esta vazia.\n");
    }
    remover(&minhaFila); // Deve imprimir erro

    return 0;
}