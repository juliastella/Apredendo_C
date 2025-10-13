#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;
    struct No* prox;
};

struct No* unir_listas(struct No* listaA, struct No* listaB) {
    if (listaA == NULL) {
        return listaB;
    }

   
    struct No* ponteiro_atual = listaA;
    while (ponteiro_atual->prox != NULL) {
        ponteiro_atual = ponteiro_atual->prox;
    }

   
    ponteiro_atual->prox = listaB;

    return listaA;
}


void inserir_no_final(struct No** lista, int dado) {
    struct No* novo_no = (struct No*)malloc(sizeof(struct No));
    novo_no->dado = dado;
    novo_no->prox = NULL;

    if (*lista == NULL) {
        *lista = novo_no;
        return;
    }

    struct No* ultimo = *lista;
    while (ultimo->prox != NULL) {
        ultimo = ultimo->prox;
    }
    ultimo->prox = novo_no;
}

// Função para imprimir a lista
void imprimir_lista(struct No* lista) {
    struct No* ponteiro_atual = lista;
    while (ponteiro_atual != NULL) {
        printf("%d -> ", ponteiro_atual->dado);
        ponteiro_atual = ponteiro_atual->prox;
    }
    printf("NULL\n");
}

int main() {
    struct No* listaA = NULL;
    inserir_no_final(&listaA, 10);
    inserir_no_final(&listaA, 20);

    struct No* listaB = NULL;
    inserir_no_final(&listaB, 30);
    inserir_no_final(&listaB, 40);

    printf("Lista A original: ");
    imprimir_lista(listaA);

    printf("Lista B original: ");
    imprimir_lista(listaB);

    struct No* lista_unida = unir_listas(listaA, listaB);

    printf("Lista Unida: ");
    imprimir_lista(lista_unida);

    struct No* temp;
    while (lista_unida != NULL) {
        temp = lista_unida;
        lista_unida = lista_unida->prox;
        free(temp);
    }

    return 0;
}