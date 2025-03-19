#include <stdio.h>


void desenhaQuadrado(int dimensao) {
    for (int l = 0; l < dimensao; l=l+1) {           // l controla as linhas
        for (int c = 0; c < dimensao; c=c+1) {       // c controla as colunas
            printf("#");
        }
        printf("\n");
    }
}


int main() {
    int tamanho;    
    printf("Insira o tamanho do quadrado: ");
    scanf("%d", &tamanho);
    
    if (tamanho > 0) {
        desenhaQuadrado(tamanho);
    } else {
        printf("Insira um número positivo.\n");
    }
    
    return 0;
}
