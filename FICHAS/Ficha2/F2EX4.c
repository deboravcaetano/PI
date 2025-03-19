#include <stdio.h>

int mdc2 (int a, int b) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    if (a > b) {
        return mdc2(a - b, b);
    } 
    else 
    if (a < b) {
        return mdc2(a, b - a);
    }
    else
    if (a==b){
        return a;
    }
}


int main() {
    int a;
    int b;
    // Solicita entrada do utilizador
    printf("Digite um inteiro a: ");
    scanf("%d", &a);
    printf("Digite um número inteiro b: ");
    scanf("%d", &b);

    // Chama a função e imprime o resultado
    int resultado = mdc2(a, b);
    printf("O resultado é: %.d\n", resultado);

    return 0;
}