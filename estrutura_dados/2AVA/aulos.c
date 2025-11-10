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

        // *** CORREÇÃO AQUI ***
        // Se a criação for um sucesso, devemos retornar o NOVO começo da lista
        return novo_aluno; 
    }

    // Se criar_aluno() falhou (retornou NULL), retorna a lista antiga
    return lista_antiga; 
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

// Função auxiliar para exibir os dados de um único aluno
void exibir_aluno(Aluno* aluno) {
    if (aluno == NULL) return; // Segurança

    printf("-----------------------------------\n");
    printf("Matricula: %d\n", aluno->matricula);
    printf("Nome: %s\n", aluno->nome);
    printf("Nota Final: %.1f\n", aluno->notaFinal);
    printf("-----------------------------------\n");
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

// *** MÚLTIPLAS CORREÇÕES NESTA FUNÇÃO ***
void remover_aluno(Aluno** lista, int matricula_remover) {
    // 1. Verificar se a lista está vazia
    if (*lista == NULL) {
        printf("A lista de alunos está vazia. Nenhum aluno para remover.\n");
        return;
    }

    // Restante da implementação virá aqui

    // *** CORREÇÃO AQUI ***
    // 'lista' é Aluno** (ponteiro duplo). Para pegar o 1º nó, usamos *lista
    Aluno* atual = *lista; 
    // 'noAnterior' deve começar como NULL, pois 'atual' é o primeiro nó
    Aluno* noAnterior = NULL; 

    // --- PASSO LÓGICO 3: O Loop (Sua lógica!) ---
    // A condição do loop é simplesmente "enquanto não chegamos ao fim"
    while (atual != NULL) {

        // Se encontramos a matrícula
        if (atual->matricula == matricula_remover) {
            
            // Caso 1: Removendo o primeiro nó
            // (Se 'noAnterior' ainda é NULL, 'atual' é o primeiro)
            if (noAnterior == NULL) { 
                // *** CORREÇÃO AQUI ***
                // O nome do parâmetro é 'lista', não 'lista_cabeca'
                *lista = atual->proximo; // A cabeça da lista muda
            } 
            // Caso 2: Removendo um nó do meio ou fim
            else { 
                noAnterior->proximo = atual->proximo; // "Pula" o nó 'atual'
            }
            
            // Libera a memória do nó removido
            free(atual); 
            printf("\nAluno com matricula %d removido com sucesso.\n", matricula_remover);
            return; // Importante! Já removemos, saia da função.
        }
        
        // Se não encontrou, avança os ponteiros para a próxima checagem
        noAnterior = atual;
        atual = atual->proximo;
    }
    // --- PASSO LÓGICO 4: Se o loop terminar, não encontrou ---
    printf("\nAluno com matricula %d NAO encontrado na lista.\n", matricula_remover);
}

// 4. Buscar um(a) aluno(a) pelo número de matrícula
void buscar_aluno(Aluno* lista, int matricula_buscar) {
    // 1. Verificar se a lista está vazia
    if (lista == NULL) {
        printf("\nA lista de alunos esta vazia. Nenhum aluno para buscar\n");
        return;
    }

    // 2. Criar ponteiro de percurso
    Aluno* atual = lista; // (Usamos a 'lista' direto aqui)

    // 3. Loop
    while (atual != NULL) {
        // Se encontramos a matrícula
        if (atual->matricula == matricula_buscar) {
            printf("\nAluno encontrado:\n");
            exibir_aluno(atual); // Exibe o aluno encontrado
            return; // Importante! Já encontramos, saia da função.
        }
        
        // Se não encontrou, avança o ponteiro
        atual = atual->proximo;
    }

    // 4. Se o loop terminar, não encontrou
    printf("\nAluno com matricula %d NAO encontrado na lista.\n", matricula_buscar);
}


void calcular_exibir_media(Aluno* lista){
    // 1. Verificar se a lista está vazia
    if (lista == NULL) {
        printf("\nA lista de alunos esta vazia. Nenhum aluno para buscar\n");
        return;
    }

    float soma_total = 0.0;
    int contador_alunos = 0;    
    media = soma_total / contador_alunos;


    // 2. Criar ponteiro de percurso
    Aluno* atual = lista; // (Usamos a 'lista' direto aqui)

    // 3. Loop
    while (atual != NULL) {       
        soma_total += atual->notaFinal; // Soma a nota final do aluno atual
        contador_alunos++; // Incrementa o contador de alunos
        
        // Avança o ponteiro
        atual = atual->proximo; // andar para o próximo nó
    }
    // O loop termina quando 'atual' se torna NULL.

    // PASSO 5: O Cálculo (A "Boca do Caixa")
    // SÓ AGORA, DEPOIS que o loop terminou, nós temos os totais.
    // Agora podemos calcular a média.
    float media = soma_total / (float)contador_alunos; // (float) garante a divisão com casas decimais

    // PASSO 6: Exibir os resultados
    printf("\n---------- MEDIA DA TURMA ----------\n");
    printf("Numero total de alunos: %d\n", contador_alunos);
    printf("Soma total das notas: %.1f\n", soma_total);
    printf("Media geral da turma: %.1f\n", media);
    printf("------------------------------------\n");
}

/// FUNÇÃO AUXILIAR: Troca os dados entre dois nós
// (Necessária para a ordenação)
void trocar_dados(Aluno* noA, Aluno* noB) {
    // 1. Cria variáveis temporárias para guardar os dados do 'noA'
    int temp_matricula = noA->matricula;
    float temp_nota = noA->notaFinal;
    char temp_nome[101];
    strcpy(temp_nome, noA->nome); // Copia a string

    // 2. Copia os dados do 'noB' para dentro do 'noA'
    noA->matricula = noB->matricula;
    noA->notaFinal = noB->notaFinal;
    strcpy(noA->nome, noB->nome);

    // 3. Copia os dados temporários (que eram do 'noA') para dentro do 'noB'
    noB->matricula = temp_matricula;
    noB->notaFinal = temp_nota;
    strcpy(noB->nome, temp_nome);
}

// 7. Ordenar a lista de aluno(a)s
void ordenar_lista(Aluno* lista) {
    
    // 1. Checar se a lista está vazia ou tem só 1 item
    if (lista == NULL || lista->proximo == NULL) {
        printf("\nLista vazia ou com um unico aluno. Nao ha o que ordenar.\n");
        return;
    }

    // 2. Perguntar ao usuário como ordenar
    int escolha = 0;
    printf("\n--- Opcoes de Ordenacao ---\n");
    printf("1. Ordenar por Nome (A-Z)\n");
    printf("2. Ordenar por Nota (Menor para Maior)\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);

    // 3. Criar os ponteiros de percurso
    Aluno* atual;
    Aluno* proximo_no;
    
    // --- O LOOP EXTERNO (O "Dedo 1" travado) ---
    // 'atual' começa na cabeça da lista e vai até o PENÚLTIMO nó
    for (atual = lista; atual->proximo != NULL; atual = atual->proximo) {
        
        // --- O LOOP INTERNO (O "Dedo 2" viajante) ---
        // 'proximo_no' começa SEMPRE à frente do 'atual' e vai até o FIM
        for (proximo_no = atual->proximo; proximo_no != NULL; proximo_no = proximo_no->proximo) {
                        
            // Se a escolha foi NOME
            if (escolha == 1) {
                // strcmp compara strings:
                // > 0 significa que 'atual->nome' vem DEPOIS de 'proximo_no->nome'
                if (strcmp(atual->nome, proximo_no->nome) > 0) {
                    // Troca os dados
                    trocar_dados(atual, proximo_no);
                }
            } 
            // Se a escolha foi NOTA
            else if (escolha == 2) {
                // Se a nota do 'atual' for MAIOR que a do 'proximo_no'
                if (atual->notaFinal > proximo_no->notaFinal) {
                    // Troca os dados
                    trocar_dados(atual, proximo_no);
                }
            }
        } // Fim do loop interno (proximo_no)
    } // Fim do loop externo (atual)

    // 5. Feedback
    if (escolha == 1) {
        printf("\nLista ordenada por NOME com sucesso!\n");
    } else if (escolha == 2) {
        printf("\nLista ordenada por NOTA com sucesso!\n");
    } else {
        printf("\nOpcao invalida. Nenhuma ordenacao foi feita.\n");
    }
    
    // Mostra o resultado
    exibir_lista(lista);
}

// --- FUNÇÃO PRINCIPAL ---

int main() {
    // nossa lista tem que começar vazia
    Aluno* lista = NULL; 
    int opcao = 0;
    int matricula_temp; // Variável para ler matrículas

    do {
        // 26. O programa deve apresentar um menu interativo
        printf("\n\n===== SISTEMA DE CADASTRO DE ALUNOS (UFRPE) =====\n");
        printf("1. Inserir aluno no INICIO\n");
        printf("2. Inserir aluno no FINAL\n");
        printf("3. Remover aluno (por Matricula)\n");
        printf("4. Buscar aluno (por Matricula)\n");
        printf("5. Exibir lista completa\n");
        printf("6. Calcular media da turma\n");
        printf("7. Ordenar lista (por Nome ou Nota)\n");
        printf("0. Sair do programa\n");
        printf("===================================================\n");
        printf("Escolha uma opcao: ");
        
        scanf("%d", &opcao);

        // Limpa o buffer do 'Enter' após o scanf da opção
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        switch (opcao) {
            case 1:
                // Atualiza o ponteiro 'lista' com o novo começo
                lista = inserir_aluno_inicio_lista(lista);
                break;
            
            case 2:
                // Atualiza 'lista' (pode mudar se estava vazia)
                lista = inserir_aluno_final_lista(lista);
                break;

            case 3:
                printf("Digite a matricula a ser REMOVIDA: ");
                scanf("%d", &matricula_temp);
                // Passamos o ENDEREÇO da 'lista' (&lista)
                remover_aluno(&lista, matricula_temp);
                break;

            case 4:
                printf("Digite a matricula a ser BUSCADA: ");
                scanf("%d", &matricula_temp);
                buscar_aluno(lista, matricula_temp);
                break;

            case 5:
                exibir_lista(lista);
                break;
            
            case 6:
                calcular_media(lista);
                break;

            case 7:
                ordenar_lista(lista);
                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;
            
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    // --- LIBERAÇÃO DE MEMÓRIA (MUITO IMPORTANTE) ---
    // Antes de sair, devemos liberar toda a memória alocada
    printf("Liberando memoria...\n");
    Aluno* atual = lista;
    Aluno* proximo_no_liberar;
    
    while (atual != NULL) {
        proximo_no_liberar = atual->proximo; // Guarda o próximo
        free(atual); // Libera o atual
        atual = proximo_no_liberar; // Pula para o próximo
    }
    printf("Memoria liberada. Ate logo!\n");

    return 0;
}