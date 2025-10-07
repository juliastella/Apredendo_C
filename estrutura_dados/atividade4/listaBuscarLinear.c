#include <stdio.h>
#include <stdlib.h> 

struct No {
    int dado;
    struct No* prox;
};

struct No* buscar_em_lista_ordenada(struct No* lista, int numero_procurado) {
    struct No* ponteiro_atual = lista;

    while (ponteiro_atual != NULL) {
        if (ponteiro_atual->dado == numero_procurado) {
            return ponteiro_atual;
        }
        else if (ponteiro_atual->dado > numero_procurado) {
            return NULL;
        }
        ponteiro_atual = ponteiro_atual->prox;
    }

   
    return NULL;
}

int main() {
    struct No* lista = NULL;
    
    struct No* primeiro_no = (struct No*)malloc(sizeof(struct No));
    primeiro_no->dado = 10;
    lista = primeiro_no;

    struct No* segundo_no = (struct No*)malloc(sizeof(struct No));
    segundo_no->dado = 20;
    primeiro_no->prox = segundo_no;

    struct No* terceiro_no = (struct No*)malloc(sizeof(struct No));
    terceiro_no->dado = 55;
    segundo_no->prox = terceiro_no;
    terceiro_no->prox = NULL; 

    printf("Buscando pelo numero 20...\n");
    struct No* no_encontrado = buscar_em_lista_ordenada(lista, 20);

    if (no_encontrado != NULL) {
        printf("Encontrado! O valor e: %d\n", no_encontrado->dado);
    } else {
        printf("Numero nao encontrado na lista.\n");
    }

    free(primeiro_no);
    free(segundo_no);
    free(terceiro_no);

    return 0;
}