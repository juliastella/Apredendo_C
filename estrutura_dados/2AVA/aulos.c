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

Aluno* inserir_aluno_inicio_lista(Aluno* lista_antiga) {
    // implementar a função de inserção no início da lista circular

    // 1. Alocar a memória
    Aluno* novo_aluno = (Aluno*) malloc(sizeof(Aluno)); /* sizeof(Aluno) que é o tamanho do nosso dado, malloc  pede ao sistema operacional um espaço na memória e (Aluno*) converte o endereço de memória recebido para um ponteiro do tipo Aluno. Aluno* novo_aluno guarda esse novo edenreço na nossa variável*/

    // 2. Preencher os dados do novo aluno

     printf("Digite o a matricula: ");
     scanf("%d", &novo_aluno->matricula); // lê a matricula do aluno e armazena no campo matricula do novo_aluno
     
     // --- LIMPEZA DO BUFFER ---
     // Lê e descarta todos os caracteres até encontrar um '\n' (Enter) ou o fim do arquivo
     int c;
     while ((c = getchar()) != '\n' && c != EOF);
     // --- FIM DA LIMPEZA ---

     // Agora podemos ler o nome com segurança
     printf("Digite o nome: ");
     // Usamos fgets para ler strings, é mais seguro que 'gets'
     // Lê até 100 chars, ou até um 'Enter', do teclado (stdin)
     fgets(novo_aluno->nome, 101, stdin);
     
     // Opcional: fgets guarda o 'Enter' no final da string. Vamos removê-lo.
     // (Isso é só para a impressão ficar mais bonita)
     size_t len = strlen(novo_aluno->nome);
     if (len > 0 && novo_aluno->nome[len - 1] == '\n') {
         novo_aluno->nome[len - 1] = '\0';
     }

     printf("Digite a nota final do aluno: ");
     scanf("%f", &novo_aluno->notaFinal); // lê a nota final do aluno e armazena no campo notaFinal do novo_aluno

     // 3. Ligar o Nó:
    // Fazer o 'prox' do novo_aluno apontar para o início antigo da lista

    novo_aluno->proximo = lista_antiga;

     // 4. Atualizar a Cabeça (Retorna o novo início da lista)
    return novo_aluno;
}






int main() {
    // nossa lista tem que começar vazia
    struct NO* lista = NULL; 
}