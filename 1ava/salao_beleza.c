// Aluna: Júlia Stela - 1ª AVA
#include <stdio.h>

int main() {

    float Corte = 70.00;
    float Escova = 50.00;
    float Hidratacao = 80.00;
    float Coloracao = 110.00;

    int mais_servico, servico;
    float valor_total = 0.0;
    char nome[50];

    printf("----Bem-vindo ao salão Cabeleleila Leila!----\n");

    printf("Nome do cliente:\n");
    scanf("%s", nome);

    do {
        printf("Informe o serviço realizado:\n");
        printf("1 - Corte\n2 - Escova\n3 - Hidratação\n4 - Coloração\n");
        scanf("%d", &servico);

        switch (servico) {
            case 1:
                valor_total += Corte;
                break;
            case 2:
                valor_total += Escova;
                break;
            case 3:
                valor_total += Hidratacao;
                break;
            case 4:
                valor_total += Coloracao;
                break;
            default:
                printf("Serviço inválido!\n");
                break;
        }

        printf("Foi realizado mais algum serviço? Sim (1) / Não (0):\n");
        scanf("%d", &mais_servico);

    } while (mais_servico == 1);

    printf("\n----Cabeleleila Leila - Resultado----\n");
    printf("Cliente: %s\n", nome);
    printf("Valor a ser pago: R$ %.2f\n", valor_total);

    return 0;
}
