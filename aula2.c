// inserir dados na maquina 

// é possivel colocar mais de uma variavel em um scanf()

// fazer um programa que coleta a idade

#include <stdio.h>

int main(){
    int idade = 0;

    printf("Valor inicial da idade: %d.\n", idade);

    printf("Digite uma idade: \n");
    scanf("%d", &idade); // especificador de formato + variavel

    printf("Idade informada: %d.\n", idade);
}