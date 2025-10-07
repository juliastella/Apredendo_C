#include <locale.h>
#include <stdio.h>

// int main()
// {
//     setlocale(LC_ALL, "Portuguese");

//     int *ponteiro;
//     int valor;

//     ponteiro = &valor;
//     valor = 10;

//     printf("endereço de valor: %d\n", &valor);
//     printf("endereço para qual p aponta: %d\n", ponteiro);

//     printf("Conteudo de valor: %d\n", valor);
//     printf("Conteudo de ponteiro: %d\n", *ponteiro);
// }
 int main()
 {
     setlocale(LC_ALL, "Portuguese");
    int i;
    int *ponteiro;
    int vet[5];

    //um verto em linguagem C é tratado com um ponteiro, então se você colocar apenas vet, você já está passando o endereço do primeiro elemento do vetor

    ponteiro = vet; //ou ponteiro = &vet[0];

    // o ponteiro pode armazenar o vetor vert todos os elementos do vetor, printando todos os elementos do vetor

    vet[0] = 10;
    vet[1] = 20;
    vet[2] = 30;
    vet[3] = 40;
    vet[4] = 50;

    for (i = 0; i < 5; i++){
        printf("%d ", ponteiro[i]); 
    }
    printf("\n");

 }
 