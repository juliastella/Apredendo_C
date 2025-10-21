#include <stdio.h>

#define TAM_MAX 100

struct Fila {
    int inicio;
    int fim;
    int vetor[TAM_MAX];
};

int vazia(struct Fila* p) {
    return (p->inicio == p->fim);
}

int cheia(struct Fila* p) {
    return ((p->fim + 1) % TAM_MAX == p->inicio);
}

void insere(struct Fila* p, int M) {
    if (cheia(p)) {
        printf("Erro: Fila cheia!\n");
    } else {
        p->vetor[p->fim] = M;
        p->fim = (p->fim + 1) % TAM_MAX;
    }
}

int remove_fila(struct Fila* p) {
    if (vazia(p)) {
        printf("Erro: Fila vazia!\n");
        return -1;
    } else {
        int valor_removido = p->vetor[p->inicio];
        p->inicio = (p->inicio + 1) % TAM_MAX;
        return valor_removido;
    }
}

void inicializa_fila(struct Fila* p) {
    p->inicio = 0;
    p->fim = 0;
}

void transfere_e_restaura(struct Fila* Origem, struct Fila* DestinoC, struct Fila* Aux) {
    int item_temporario;
    
    while (vazia(Origem) == 0) {
        item_temporario = remove_fila(Origem);
        insere(Aux, item_temporario);
    }
    
    while (vazia(Aux) == 0) {
        item_temporario = remove_fila(Aux);
        insere(Origem, item_temporario);
        insere(DestinoC, item_temporario);
    }
}

void concatenar_filas(struct Fila* A, struct Fila* B, struct Fila* C) {
    struct Fila filaAux;
    inicializa_fila(&filaAux);
    
    printf("Processando Fila A...\n");
    transfere_e_restaura(A, C, &filaAux);
    
    printf("Processando Fila B...\n");
    transfere_e_restaura(B, C, &filaAux);
}

int main() {
    struct Fila filaA, filaB, filaC;
    inicializa_fila(&filaA);
    inicializa_fila(&filaB);
    inicializa_fila(&filaC);

    printf("--- Preenchendo Filas Originais ---\n");
    insere(&filaA, 10);
    insere(&filaA, 20);
    printf("Fila A original: 10 -> 20\n");

    insere(&filaB, 30);
    insere(&filaB, 40);
    printf("Fila B original: 30 -> 40\n\n");

    printf("--- Concatenando Filas ---\n");
    concatenar_filas(&filaA, &filaB, &filaC);
    printf("--- Operacao Concluida ---\n\n");

    printf("Verificando Fila C (Resultado): ");
    while (!vazia(&filaC)) {
        printf("%d ", remove_fila(&filaC));
    }
    printf("\n(Esperado: 10 20 30 40)\n");

    printf("\nVerificando Fila A (Preservada): ");
    while (!vazia(&filaA)) {
        printf("%d ", remove_fila(&filaA));
    }
    printf("\n(Esperado: 10 20)\n");
    
    printf("\nVerificando Fila B (Preservada): ");
    while (!vazia(&filaB)) {
        printf("%d ", remove_fila(&filaB));
    }
    printf("\n(Esperado: 30 40)\n");

    return 0;
}