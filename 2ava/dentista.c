#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int identificador_paciente;
    char nome_completo_paciente[16];
    int genero_paciente;
    int tipo_procedimento_odontologico;
    int status_convenio_paciente;
    float valor_final_tratamento;
} RegistroPaciente;

FILE *ponteiro_arquivo_pacientes;
RegistroPaciente registro_paciente_temp;
RegistroPaciente registro_paciente_removido;

void limpar_console_terminal() {
    system("clear");
}

void imprimir_linha_separadora() {
    int contador_caractere;
    for (contador_caractere = 0; contador_caractere < 80; contador_caractere++) {
        printf("-");
    }
    printf("\n");
}

void exibir_cabecalho_aplicacao() {
    limpar_console_terminal();
    printf("Clinica Odontologica Sorriso\n");
    imprimir_linha_separadora();
    printf("\n");
}

void pausar_execucao_e_aguardar_enter() {
    printf("Pressione ENTER para continuar...");
    while (getchar() != '\n' && getchar() != EOF); 
    getchar();
}

const char* obter_descricao_genero(int codigo_genero) {
    if (codigo_genero == 1) {
        return "Feminino";
    } else if (codigo_genero == 2) {
        return "Masculino";
    } else {
        return "N/A";
    }
}

const char* obter_descricao_tratamento(int codigo_tratamento) {
    switch (codigo_tratamento) {
        case 1: return "Extracao";
        case 2: return "Restauracao";
        case 3: return "Canal";
        case 4: return "Limpeza";
        default: return "N/A";
    }
}

const char* obter_descricao_convenio(int status_convenio) {
    if (status_convenio == 1) {
        return "Sim";
    } else if (status_convenio == 0) {
        return "Nao";
    } else {
        return "N/A";
    }
}

void abrir_ou_criar_arquivo_dados() {
    ponteiro_arquivo_pacientes = fopen("pacientes.dat", "r+b");

    if (ponteiro_arquivo_pacientes == NULL) {
        ponteiro_arquivo_pacientes = fopen("pacientes.dat", "w+b");
        if (ponteiro_arquivo_pacientes == NULL) {
            printf("Erro critico ao criar o arquivo 'pacientes.dat'!\n");
            pausar_execucao_e_aguardar_enter();
            exit(1);
        }
        registro_paciente_removido.identificador_paciente = 0;
        strcpy(registro_paciente_removido.nome_completo_paciente, "");
        registro_paciente_removido.genero_paciente = 0;
        registro_paciente_removido.tipo_procedimento_odontologico = 0;
        registro_paciente_removido.status_convenio_paciente = 0;
        registro_paciente_removido.valor_final_tratamento = 0.0;
    }
}

float calcular_custo_procedimento_odontologico(int tipo_procedimento, int status_convenio, int genero_paciente) {
    float valor_base_procedimento = 0.0;

    switch (tipo_procedimento) {
        case 1:
            valor_base_procedimento = (status_convenio == 1) ? 65.00 : 110.00;
            break;
        case 2:
            valor_base_procedimento = (status_convenio == 1) ? 107.00 : 135.00;
            break;
        case 3:
            valor_base_procedimento = (status_convenio == 1) ? 280.00 : 460.00;
            break;
        case 4:
            valor_base_procedimento = (status_convenio == 1) ? 210.00 : 290.00;
            break;
        default:
            valor_base_procedimento = 0.0;
            break;
    }

    if (genero_paciente == 1) {
        valor_base_procedimento *= 0.85;
    }

    return valor_base_procedimento;
}

int buscar_paciente_por_identificador(int identificador_alvo) {
    int posicao_atual_registro = 0;
    rewind(ponteiro_arquivo_pacientes);

    fread(&registro_paciente_temp, sizeof(RegistroPaciente), 1, ponteiro_arquivo_pacientes);

    while (!feof(ponteiro_arquivo_pacientes)) {
        if (registro_paciente_temp.identificador_paciente == identificador_alvo) {
            return posicao_atual_registro;
        }
        fread(&registro_paciente_temp, sizeof(RegistroPaciente), 1, ponteiro_arquivo_pacientes); 
        posicao_atual_registro++;
    }
    return -1;
}

void realizar_cadastro_novo_paciente() {
    int resposta_continuar_cadastro;
    int proximo_identificador_disponivel = 0;

    rewind(ponteiro_arquivo_pacientes);
    
    fread(&registro_paciente_temp, sizeof(RegistroPaciente), 1, ponteiro_arquivo_pacientes);
    while (!feof(ponteiro_arquivo_pacientes)) {
        if (registro_paciente_temp.identificador_paciente > proximo_identificador_disponivel) {
            proximo_identificador_disponivel = registro_paciente_temp.identificador_paciente;
        }
        fread(&registro_paciente_temp, sizeof(RegistroPaciente), 1, ponteiro_arquivo_pacientes);
    }

    do {
        exibir_cabecalho_aplicacao();
        printf("Cadastro de Paciente\n");
        imprimir_linha_separadora();
        printf("\n");

        registro_paciente_temp.identificador_paciente = ++proximo_identificador_disponivel;
        printf("Codigo.......: %d\n", registro_paciente_temp.identificador_paciente);

        while (getchar() != '\n' && getchar() != EOF);

        printf("Nome.........: ");
        fgets(registro_paciente_temp.nome_completo_paciente, sizeof(registro_paciente_temp.nome_completo_paciente), stdin);
        registro_paciente_temp.nome_completo_paciente[strcspn(registro_paciente_temp.nome_completo_paciente, "\n")] = 0; 

        printf("Sexo (1-fem/2-mas): ");
        scanf("%d", &registro_paciente_temp.genero_paciente);
        while (registro_paciente_temp.genero_paciente != 1 && registro_paciente_temp.genero_paciente != 2) {
            printf("Opcao invalida. Digite 1 para feminino ou 2 para masculino: ");
            scanf("%d", &registro_paciente_temp.genero_paciente);
        }

        printf("Tratamento (1-extracao/2-restauracao/3-canal/4-limpeza): ");
        scanf("%d", &registro_paciente_temp.tipo_procedimento_odontologico);
        while (registro_paciente_temp.tipo_procedimento_odontologico < 1 || registro_paciente_temp.tipo_procedimento_odontologico > 4) {
            printf("Opcao invalida. Digite um numero entre 1 e 4: ");
            scanf("%d", &registro_paciente_temp.tipo_procedimento_odontologico);
        }

        printf("Trabalha em empresa conveniada (1-sim/0-nao): ");
        scanf("%d", &registro_paciente_temp.status_convenio_paciente);
        while (registro_paciente_temp.status_convenio_paciente != 0 && registro_paciente_temp.status_convenio_paciente != 1) {
            printf("Opcao invalida. Digite 1 para sim ou 0 para nao: ");
            scanf("%d", &registro_paciente_temp.status_convenio_paciente);
        }

        registro_paciente_temp.valor_final_tratamento = calcular_custo_procedimento_odontologico(
            registro_paciente_temp.tipo_procedimento_odontologico,
            registro_paciente_temp.status_convenio_paciente,
            registro_paciente_temp.genero_paciente
        );

        fseek(ponteiro_arquivo_pacientes, 0, SEEK_END);
        fwrite(&registro_paciente_temp, sizeof(RegistroPaciente), 1, ponteiro_arquivo_pacientes);

        printf("\nPaciente cadastrado com sucesso!\n");
        printf("Valor do tratamento: R$%.2f\n", registro_paciente_temp.valor_final_tratamento);

        printf("\nCadastrar outro (1-sim/0-nao)? ");
        scanf("%d", &resposta_continuar_cadastro);

    } while (resposta_continuar_cadastro == 1);
}

void gerar_listagem_completa_pacientes() {
    int total_registros_exibidos = 0;
    int numero_pagina_atual = 1;
    exibir_cabecalho_aplicacao();
    printf("Listagem Geral de Pacientes\n");
    imprimir_linha_separadora();
    printf("\n");

    printf("%-5s %-15s %-10s %-12s %-10s %-10s\n",
           "Cod", "Nome", "Genero", "Tratamento", "Convenio", "Valor");
    imprimir_linha_separadora();

    rewind(ponteiro_arquivo_pacientes);

    fread(&registro_paciente_temp, sizeof(RegistroPaciente), 1, ponteiro_arquivo_pacientes);

    while (!feof(ponteiro_arquivo_pacientes)) {
        if (registro_paciente_temp.identificador_paciente != 0) {
            printf("%-5d %-15s %-10s %-12s %-10s %-10.2f\n",
                   registro_paciente_temp.identificador_paciente,
                   registro_paciente_temp.nome_completo_paciente,
                   obter_descricao_genero(registro_paciente_temp.genero_paciente),
                   obter_descricao_tratamento(registro_paciente_temp.tipo_procedimento_odontologico),
                   obter_descricao_convenio(registro_paciente_temp.status_convenio_paciente),
                   registro_paciente_temp.valor_final_tratamento);
            total_registros_exibidos++;

            if (total_registros_exibidos % 10 == 0) {
                printf("\nPagina %d de X... ", numero_pagina_atual);
                pausar_execucao_e_aguardar_enter();
                numero_pagina_atual++;
                exibir_cabecalho_aplicacao();
                printf("Listagem Geral de Pacientes (Pagina %d)\n", numero_pagina_atual);
                imprimir_linha_separadora();
                printf("\n");
                printf("%-5s %-15s %-10s %-12s %-10s %-10s\n",
                       "Cod", "Nome", "Genero", "Tratamento", "Convenio", "Valor");
                imprimir_linha_separadora();
            }
        }
        fread(&registro_paciente_temp, sizeof(RegistroPaciente), 1, ponteiro_arquivo_pacientes);
    }

    if (total_registros_exibidos == 0) {
        printf("\nNenhum paciente valido cadastrado no sistema.\n");
    }

    printf("\n");
    imprimir_linha_separadora();
    printf("Pressione qualquer tecla para voltar ao menu principal...");
    pausar_execucao_e_aguardar_enter();
}

void gerar_relatorio_estatistico_clinica() {
    int contagem_mulheres_canal = 0;
    int contagem_total_pacientes_validos = 0;
    int contagem_homens_convenio = 0;
    float soma_valor_tratamento_masculino = 0.0;
    int contagem_pacientes_masculinos = 0;
    float valor_total_arrecadado_extracao = 0.0;

    exibir_cabecalho_aplicacao();
    printf("Relatorio Estatistico da Clinica\n");
    imprimir_linha_separadora();
    printf("\n");

    rewind(ponteiro_arquivo_pacientes);
    fread(&registro_paciente_temp, sizeof(RegistroPaciente), 1, ponteiro_arquivo_pacientes);

    while (!feof(ponteiro_arquivo_pacientes)) {
        if (registro_paciente_temp.identificador_paciente != 0) {
            contagem_total_pacientes_validos++;

            if (registro_paciente_temp.genero_paciente == 1 && registro_paciente_temp.tipo_procedimento_odontologico == 3) {
                contagem_mulheres_canal++;
            }

            if (registro_paciente_temp.genero_paciente == 2 && registro_paciente_temp.status_convenio_paciente == 1) {
                contagem_homens_convenio++;
            }

            if (registro_paciente_temp.genero_paciente == 2) {
                soma_valor_tratamento_masculino += registro_paciente_temp.valor_final_tratamento;
                contagem_pacientes_masculinos++;
            }

            if (registro_paciente_temp.tipo_procedimento_odontologico == 1) {
                valor_total_arrecadado_extracao += registro_paciente_temp.valor_final_tratamento;
            }
        }
        fread(&registro_paciente_temp, sizeof(RegistroPaciente), 1, ponteiro_arquivo_pacientes);
    }

    printf("Percentual de mulheres que fizeram canal.....: %.2f%%\n",
           (contagem_total_pacientes_validos > 0) ? ((float)contagem_mulheres_canal / contagem_total_pacientes_validos) * 100.0 : 0.0);
    printf("Quantidade de homens que trabalham em empresas conveniadas.: %d\n", contagem_homens_convenio);
    printf("Media do valor dos tratamentos dos homens....: R$%.2f\n",
           (contagem_pacientes_masculinos > 0) ? soma_valor_tratamento_masculino / contagem_pacientes_masculinos : 0.0);
    printf("Valor arrecadado com extracao................: R$%.2f\n", valor_total_arrecadado_extracao);

    printf("\n");
    imprimir_linha_separadora();
    printf("Pressione qualquer tecla para voltar ao menu principal...");
    pausar_execucao_e_aguardar_enter();
}

void exibir_menu_principal_aplicacao() {
    int opcao_menu_principal;

    do {
        exibir_cabecalho_aplicacao();
        printf("Opcoes:\n\n");
        printf("1- Cadastrar Paciente\n");
        printf("2- Listagem Geral\n");
        printf("3- Relatorio Estatistico\n");
        printf("0- Sair\n");
        imprimir_linha_separadora();
        printf("Opcao desejada: ");
        scanf("%d", &opcao_menu_principal);

        while (getchar() != '\n' && getchar() != EOF);

        switch (opcao_menu_principal) {
            case 1:
                realizar_cadastro_novo_paciente();
                break;
            case 2:
                gerar_listagem_completa_pacientes();
                break;
            case 3:
                gerar_relatorio_estatistico_clinica();
                break;
            case 0:
                printf("\nSaindo do programa. Ate mais!\n");
                break;
            default:
                printf("\nOpcao invalida! ");
                pausar_execucao_e_aguardar_enter();
                break;
        }
    } while (opcao_menu_principal != 0);
}

int main() {
    abrir_ou_criar_arquivo_dados();
    exibir_menu_principal_aplicacao();
    fclose(ponteiro_arquivo_pacientes);
    return 0;
}
