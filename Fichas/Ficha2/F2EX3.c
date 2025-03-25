#include <stdio.h>

int mdc1 (int a, int b) {
    int maior, menor;
    if (a > b) {
        maior = a; menor = b;
    }
    else {
        maior = b; menor = a;
    }

    // Iterar pelos possíveis divisores do menor número
    for (int i = menor; i >= 1; i--) {
        // Verificar se 'i' é um divisor de 'a' e 'b'
        if (a % i == 0 && b % i == 0) {
            // Se for, encontramos o MDC
            return i;
        }
    }

    return 1; // Caso não encontre nenhum divisor comum além de 1
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
    int resultado = mdc1(a, b);
    printf("O resultado é: %.d\n", resultado);

    return 0;
}