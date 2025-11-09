#include <stdio.h>
#include <stdlib.h> 
#include <string.h>// para usar malloc e free, strlen

// vamos definir os nossos dados
typedef struct NO{
  int matricula; // matricula do aluno
  char nome[101]; // 100 caracteres para o nome + 1 para o '\0' (fim da string)
  float notaFinal; // nota final do aluno
  struct NO* proximo; // ponteiro para o nosso próximo nó que é onde está o próximo dado
}Aluno;

// FUNÇÃO AUXILIAR: Cria um novo nó de aluno
// Aloca memória e preenche os dados.
Aluno* criar_aluno() {
    // 1. Alocar a memória
    Aluno* novo_aluno = (Aluno*) malloc(sizeof(Aluno));/* sizeof(Aluno) que é o tamanho do nosso dado, malloc  pede ao sistema operacional um espaço na memória e (Aluno*) converte o endereço de memória recebido para um ponteiro do tipo Aluno. Aluno* novo_aluno guarda esse novo edenreço na nossa variável*/
    if (novo_aluno == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return NULL; // Retorna NULL se o malloc falhar
    }

    // 2. Preencher os dados
    printf("Digite a matricula: ");
    scanf("%d", &novo_aluno->matricula);
    
    // --- LIMPEZA DO BUFFER ---
    // Lê e descarta todos os caracteres até encontrar um '\n' (Enter) ou o fim do arquivo
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    // --- FIM DA LIMPEZA ---

    // Agora podemos ler o nome com segurança
    printf("Digite o nome: ");
    fgets(novo_aluno->nome, 101, stdin);
    
    // Opcional: fgets guarda o 'Enter' no final da string. Vamos removê-lo.
    // (Isso é só para a impressão ficar mais bonita)
    size_t len = strlen(novo_aluno->nome);
    if (len > 0 && novo_aluno->nome[len - 1] == '\n') {
        novo_aluno->nome[len - 1] = '\0';
    }

    printf("Digite a nota final do aluno: ");
    scanf("%f", &novo_aluno->notaFinal);// lê a nota final do aluno e armazena no campo notaFinal do novo_aluno

    // 3. Garantir que o 'proximo' comece como NULL
    novo_aluno->proximo = NULL;

    // 4. Retorna o nó pronto
    return novo_aluno;
}


Aluno* inserir_aluno_inicio_lista(Aluno* lista_antiga) {
    // implementar a função de inserção no início da lista circular

    // Chama a função auxiliar para criar e preencher o nó
    Aluno* novo_aluno = criar_aluno();


    // Se a criação deu certo (não é NULL)
    if (novo_aluno != NULL) {
        // 3. Ligar o Nó
        novo_aluno->proximo = lista_antiga; // Fazer o 'prox' do novo_aluno apontar para o início antigo da lista

    // 4. Atualizar a Cabeça
        printf("\nAluno %s inserido no INICIO com sucesso!\n", novo_aluno->nome);

        // Se criar_aluno() falhou (retornou NULL)
        return lista_antiga; // Retorna a lista como estava, sem mudar
    }

     // 4. Atualizar a Cabeça (Retorna o novo início da lista)
    return novo_aluno;
}

void exibir_lista(Aluno* lista){
     // 1: Checkar se a lista está vazia
     if (lista == NULL) {

         printf("\n-----------------------------------\n");
         printf("A lista de alunos esta vazia!\n");
         printf("-----------------------------------\n");

         // 'return' para a execução da função imediatamente.
         return;
     }

     // Se a lista NÃO for NULL

     Aluno* atual = lista; // ponteiro auxiliar para percorrer a lista
     
    // PASSO 3: O Loop (Continue ENQUANTO 'atual' não for NULL)
    while (atual != NULL) {
        
        // (Seu bloco de printf, que estava perfeito!)
         printf("-----------------------------------\n");
         printf("Matricula: %d\n", atual->matricula);
         printf("Nome: %s\n", atual->nome);
         printf("Nota Final: %.1f\n", atual->notaFinal); // (Mudei para .1f como no projeto)
         printf("-----------------------------------\n");

         // PASSO 4: Mover para o próximo nó
         atual = atual->proximo;
    }
    // Quando 'atual' se torna NULL, o loop para sozinho.
}

// 2. Inserir um(a) novo(a) aluno(a) no final da lista
    Aluno* inserir_aluno_final_lista(Aluno* lista_atual) {

        // 1. Cria o novo aluno (usando nossa função auxiliar)
        Aluno* novo_aluno = criar_aluno();
        if (novo_aluno == NULL) {
            return lista_atual; // Se a criação falhou, não faz nada
        }
        // (Lembre-se: novo_aluno->proximo já é NULL, pois 'criar_aluno' faz isso)

        // 2. Caso 1: A lista está vazia
        if (lista_atual == NULL) {
            printf("\nAluno %s inserido no FINAL (lista estava vazia)!\n", novo_aluno->nome);
            return novo_aluno; // O novo aluno é o único, então ele é o começo
        }

        // 3. Caso 2: A lista NÃO está vazia. Vamos até o fim.
        Aluno* atual = lista_atual;

        // Loop para "caminhar" até o último nó
        // O loop para QUANDO 'atual->proximo' for NULL
        while (atual->proximo != NULL) {
            atual = atual->proximo; // Avança o ponteiro
        }

        // 4. Ligar o Nó
        // Neste ponto, 'atual' é o último nó da lista.
        // Ligamos o 'novo_aluno' depois dele.
        atual->proximo = novo_aluno;

        printf("\nAluno inserido com sucesso!\n");
        exibir_aluno(novo_aluno); // Passa o próprio novo_aluno para ser exibido
        // 5. Retornar
        // O começo da lista (lista_atual) NÃO MUDOU, então retornamos ele.
        return lista_atual;
    }
    



int main() {
    // nossa lista tem que começar vazia
    struct NO* lista = NULL; 
}