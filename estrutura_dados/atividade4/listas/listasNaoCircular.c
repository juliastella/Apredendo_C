#include <stdio.h>
#include <stdlib.h> // para usar malloc e free

struct NO{
  int dado; // nosso dado
  struct NO* prox; // ponteiro para o nosso próximo nó que é onde está o próximo dado
};

int encontrarMenovalor(struct NO* lista) {
    //checa se a lista está vazia
    if (lista == NULL){
      printf("A lista está vazia.\n");
      return -1; // retorna um valor especial indicando que a lista está vazia
    } 

    int menor = lista->dado; // inicializa o menor valor com o dado do primeiro nó

    // Ponteiro temporario para percorrer a lista e adicionamos um novo nó
    struct NO* ponteiro_atual = lista;

    while(ponteiro_atual != NULL){
      if (ponteiro_atual->dado < menor){
        menor = ponteiro_atual->dado;
        }
        ponteiro_atual = ponteiro_atual->prox; // avança para o próximo nó

      }
      
      return menor; // retorna o menor valor encontrado
}



int main() {
    // Padronizado para 'No'
    struct NO* lista = NULL;
    
    // --- Criando o primeiro nó ---
    struct NO* primeiro_no = (struct NO*)malloc(sizeof(struct NO));
    primeiro_no->dado = 20;
    primeiro_no->prox = NULL;
    lista = primeiro_no; // A lista começa aqui

    // --- Adicionando mais nós para um teste melhor ---
    struct NO* segundo_no = (struct NO*)malloc(sizeof(struct NO));
    segundo_no->dado = 10;
    segundo_no->prox = NULL;
    primeiro_no->prox = segundo_no; // Conecta o primeiro ao segundo

    struct NO* terceiro_no = (struct NO*)malloc(sizeof(struct NO));
    terceiro_no->dado = 55;
    terceiro_no->prox = NULL;
    segundo_no->prox = terceiro_no; // Conecta o segundo ao terceiro

    // --- Chamando a função e exibindo o resultado ---
    printf("Procurando o menor valor na lista...\n");
    int resultado = encontrarMenovalor(lista);
    
    if (resultado != -1) {
        printf("O menor valor encontrado foi: %d\n", resultado);
    }

    // --- Liberando a memória alocada (boa prática) ---
    free(primeiro_no);
    free(segundo_no);
    free(terceiro_no);

    return 0;
}