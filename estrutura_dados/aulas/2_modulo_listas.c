#include <locale.h>
#include <stdio.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int *ponteiro;
    int valor;

    ponteiro = &valor;
    valor = 10;

    printf("endereço de valor: %d\n", &valor);
    printf("endereço para qual p aponta: %d\n", ponteiro);

    printf("Conteudo de valor: %d\n", valor);
    printf("Conteudo de ponteiro: %d\n", *ponteiro);
}
