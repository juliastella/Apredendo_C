// Aluna: Júlia Stela - 1ª AVA
#include <stdio.h>

int main() {
    int adicionar_novo_pesquisado;
    int idade, sexo, gosto_junino, participar_da_festa;

    // Contadores e acumuladores
    int totalTudo = 0, totalMulheresMusica = 0;
    int somaIdadeHomensFogos = 0, totalHomensFogos = 0;
    int somaIdadeBrincadeiras = 0, totalBrincadeiras = 0;
    int totalNada = 0, totalEntrevistados = 0;
    int mulheresVao = 0;
    int totalMusica = 0, totalComidas = 0, totalBrincadeirasGeral = 0, totalFogos = 0;

    printf("----Bem-vindo à pesquisa Junina!----\n");

    printf("Você deseja adicionar um entrevistado? Sim (1) / Não (0):\n");
    scanf("%d", &adicionar_novo_pesquisado);

    while (adicionar_novo_pesquisado == 1) {
        printf("Qual a sua idade?\n");
        scanf("%d", &idade);

        printf("Qual o seu sexo? (1 - Feminino / 2 - Masculino)\n");
        scanf("%d", &sexo);

        printf("O que você mais gosta nas festas juninas?\n");
        printf("1 - Música, 2 - Comidas típicas, 3 - Brincadeiras, 4 - Fogos, 5 - Tudo, 6 - Nada\n");
        scanf("%d", &gosto_junino);

        printf("Vai participar de alguma festa junina este ano? (1 - Sim / 0 - Não)\n");
        scanf("%d", &participar_da_festa);

        // Atualiza contadores
        totalEntrevistados++;

        if (gosto_junino == 5) totalTudo++;
        if (sexo == 1 && gosto_junino == 1) totalMulheresMusica++;
        if (sexo == 2 && gosto_junino == 4) {
            somaIdadeHomensFogos += idade;
            totalHomensFogos++;
        }
        if (gosto_junino == 3) {
            somaIdadeBrincadeiras += idade;
            totalBrincadeiras++;
        }
        if (gosto_junino == 6) totalNada++;
        if (sexo == 1 && participar_da_festa == 1) mulheresVao++;

        // Preferência geral
        if (gosto_junino == 1) totalMusica++;
        if (gosto_junino == 2) totalComidas++;
        if (gosto_junino == 3) totalBrincadeirasGeral++;
        if (gosto_junino == 4) totalFogos++;

        printf("\nDeseja adicionar outro entrevistado? Sim (1) / Não (0):\n");
        scanf("%d", &adicionar_novo_pesquisado);
    }

    // Resultados
    printf("\n--- Resultados da pesquisa ---\n");

    printf("Quantidade de pessoas que gostam de tudo: %d\n", totalTudo);
    printf("Quantidade de mulheres que gostam mais de música: %d\n", totalMulheresMusica);

    if (totalHomensFogos > 0) {
        printf("Média da idade dos homens que gostam de fogos: %.2f\n", (float)somaIdadeHomensFogos / totalHomensFogos);
    } else {
        printf("Nenhum homem respondeu que gosta de fogos.\n");
    }

    if (totalBrincadeiras > 0) {
        printf("Média da idade das pessoas que preferem brincadeiras: %.2f\n", (float)somaIdadeBrincadeiras / totalBrincadeiras);
    } else {
        printf("Ninguém respondeu que prefere brincadeiras.\n");
    }

    if (totalEntrevistados > 0) {
        float percNada = (float)totalNada / totalEntrevistados * 100;
        float percMulheresFesta = (float)mulheresVao / totalEntrevistados * 100;

        printf("Percentual de pessoas que não gostam de nada: %.2f%%\n", percNada);
        printf("Percentual de mulheres que vão participar de festa: %.2f%%\n", percMulheresFesta);
    }

    // Preferência geral
    if (totalMusica >= totalComidas && totalMusica >= totalBrincadeirasGeral && totalMusica >= totalFogos) {
        printf("A preferência geral foi: Música\n");
    } else if (totalComidas >= totalMusica && totalComidas >= totalBrincadeirasGeral && totalComidas >= totalFogos) {
        printf("A preferência geral foi: Comidas típicas\n");
    } else if (totalBrincadeirasGeral >= totalMusica && totalBrincadeirasGeral >= totalComidas && totalBrincadeirasGeral >= totalFogos) {
        printf("A preferência geral foi: Brincadeiras\n");
    } else {
        printf("A preferência geral foi: Fogos\n");
    }

    return 0;
}
