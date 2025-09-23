#include <stdio.h>

// int main(void){
    
//     int x; // estou pedindo separar um espaço de memoria
    
//     x = 10; // aquele espaço de memoria coloquei 10
    
//     printf("%i\n", &x); //o & mostrar o edereço de memoria, temos que colocar antes da variavel
    
//     getchar();
//     return 0;
// }
  

// #include <stdio.h>

// int main(void){
    
//     int x; // estou pedindo separar um espaço de memoria
    
//     x = 10; // aquele espaço de memoria coloquei 10
    
//     int *ponteiro; // o * serve para pegar o valorr amazernado no endereço
//     ponteiro = &x; // o ponteiro esta recebendo o valor de memoria o endereço
    
//     printf("%i\n", *ponteiro);  // que é 10. Se tiro o * mostra o endereço de memoria
    
//     return 0;
// }


#include <stdio.h>

int main(void){
    
    int x = 10; // aquele espaço de memoria coloquei 10
    int *ponteiro; 
    ponteiro = &x;
    
    int y = 20;
    *ponteiro = y;
    
    printf("%i\n", x, y);  // vai imprimir 20,20
    
    return 0;
}
  
  