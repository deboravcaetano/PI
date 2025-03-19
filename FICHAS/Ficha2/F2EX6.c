#include <stdio.h>


int fib1(int n) {
    if (n < 2) {
        return 1;
    } else {
        return fib1(n - 1) + fib1(n - 2);
    }
}


int main() {
    int n;
    // Solicita entrada do utilizador
    printf("Digite um inteiro n: ");
    scanf("%d", &n);

    // Chama a função e imprime o resultado
    int resultado = fib1(n);
    printf("O resultado é: %.d\n", resultado);

    return 0;
}