#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NO {
    int codigo;
    char nome[10];
} NO;

// Função para limpar o buffer de entrada de forma segura e portável
// void limpar_buffer() {
//     int c;
//     while ((c = getchar()) != '\n' && c != EOF);
// }

// int main() {
//     setlocale(LC_ALL, "Portuguese");

//     NO *ponteiro = (NO *)malloc(sizeof(NO));

//     if (ponteiro == NULL) {
//         printf("Erro ao alocar memória\n");
//         // É mais comum retornar 1 em 'main' para indicar um erro
//         return 1;
//     }

//     printf("Insira o código: ");
//     scanf("%d", &ponteiro->codigo);
    
//     // CORREÇÃO: Limpa o buffer APÓS o scanf de número, antes de ler a string
//     limpar_buffer(); 

//     printf("Insira o nome: ");
//     // CORREÇÃO: Usando fgets para ler a string de forma segura
//     // Lê até 9 caracteres para deixar espaço para o '\0' final
//     fgets(ponteiro->nome, sizeof(ponteiro->nome), stdin);

//     // O fgets inclui o '\n' (Enter) no final da string, vamos removê-lo
//     ponteiro->nome[strcspn(ponteiro->nome, "\n")] = '\0';

//     printf("\nPressione Enter para continuar...");
//     getchar(); // Agora a pausa funciona corretamente

// #ifdef _WIN32
//     system("cls"); // Comando para Windows
// #else
//     system("clear"); // Comando para Linux/macOS
// #endif

//     printf("Código: %d\n", ponteiro->codigo);
//     printf("Nome: %s\n", ponteiro->nome);

//     // CORREÇÃO: Liberando a memória alocada para evitar vazamentos
//     free(ponteiro);
//     ponteiro = NULL; // Boa prática para evitar usar o ponteiro depois de liberado

//     return 0; // Retorna 0 para indicar que o programa terminou com sucesso
// }

int init int main(){
  setlocale(LC_ALL, "Portuguese");
  
  NO *ponteiro;
  ponteiro = (NO *)malloc(sizeof(NO)); 

  if (ponteiro == NULL)   
  {
    /* code */
  }
  
}
