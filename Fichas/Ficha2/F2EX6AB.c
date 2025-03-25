#include <stdio.h>

int fib2(int n) {
    if (n < 2) {
        return 1;
    }

    int a = 1; // Valor de fib(n-2)
    int b = 1; // Valor de fib(n-1)
    int fibn;

    for (int i = 2; i <= n; i++) {
        fibn = a + b; // Calcula fib(n)
        a = b;       // Atualiza fib(n-2)
        b = fibn;      // Atualiza fib(n-1)
    }

    return b; // Retorna fib(n)
}

int main() {
    int n;
    // Solicita entrada do utilizador
    printf("Digite um inteiro n: ");
    scanf("%d", &n);

    // Chama a função e imprime o resultado
    int resultado = fib2(n);
    printf("O resultado é: %.d\n", resultado);

    return 0;
}
