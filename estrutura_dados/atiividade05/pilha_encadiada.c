#include <stdio.h>
#include <stdlib.h> 

// AJUSTE: Padronizado para 'No' com 'N' maiúsculo e 'o' minúsculo
struct No {
  int dado;
  struct No* prox; 
};

// AJUSTE: Padronizado para 'No'
struct Pilha {
    // AJUSTE: Corrigida a declaração do ponteiro topo
    struct No* topo; 
};

// --- OPERAÇÕES DA PILHA ---

int vazia(struct Pilha* p) {
    return (p->topo == NULL);
}

void empilha(struct Pilha* p, int M) {
    // AJUSTE: Padronizado para 'No'
    struct No* novo_no = (struct No*)malloc(sizeof(struct No));

    if (novo_no == NULL) {
      printf("Erro: Memoria insuficiente!\n");
      return;
    }
    
    novo_no->dado = M;
    novo_no->prox = p->topo;
    p->topo = novo_no;
}

int desempilha(struct Pilha* p) {
    if (vazia(p)) {
        printf("Erro: A pilha esta vazia!\n");
        return -1;
    } else {
      // AJUSTE: Corrigido o erro de digitação de 'strucut' para 'struct'
      struct No* no_removido = p->topo;
      int valor_removido = no_removido->dado; // Guarda o valor ANTES de perder a referência

      p->topo = p->topo->prox; // Atualiza o topo
      
      free(no_removido); // Libera a memória do nó antigo
      return valor_removido;
    }
}

int topo(struct Pilha* p) {
    if (vazia(p)) {
        printf("Erro: A pilha esta vazia!\n");
        return -1;
    } else {
        return p->topo->dado;
    }
} 

// --- FUNÇÃO MAIN ---

int main() {
    struct Pilha minhaPilha;
    minhaPilha.topo = NULL;

    printf("--- Testando a Pilha Vazia ---\n");
    if (vazia(&minhaPilha)) { // Nao precisa de '== 1', o if já entende
        printf("OK: A pilha esta vazia!\n");
    } else {
        printf("ERRO: A pilha deveria estar vazia!\n");
    }

    printf("\n--- Testando a Operacao EMPILHA ---\n");
    empilha(&minhaPilha, 10);
    empilha(&minhaPilha, 20);
    empilha(&minhaPilha, 30);
    printf("Elementos 10, 20 e 30 empilhados.\n");

    printf("\n--- Testando a Operacao TOPO ---\n");
    int valor_topo = topo(&minhaPilha);
    if (valor_topo != -1) {
        printf("O elemento no topo da pilha eh: %d (Esperado: 30)\n", valor_topo);
    }

    printf("\n--- Testando a Operacao DESEMPILHA ---\n");
    int valor_removido = desempilha(&minhaPilha);
    if (valor_removido != -1) {
        printf("Elemento desempilhado: %d (Esperado: 30)\n", valor_removido);
    }

    valor_topo = topo(&minhaPilha);
    if (valor_topo != -1) {
        printf("O novo elemento no topo da pilha eh: %d (Esperado: 20)\n", valor_topo);
    }
    
    // Testando o resto da pilha
    desempilha(&minhaPilha);
    desempilha(&minhaPilha);
    
    printf("\n--- Verificacao Final ---\n");
    if (vazia(&minhaPilha)) {
        printf("OK: A pilha esta vazia novamente.\n");
    } else {
        printf("ERRO: A pilha deveria estar vazia.\n");
    }

    return 0;
}