#include <stdio.h>

void escrever_triangulo(int n) {
    // Parte crescente do triângulo
    for (int lc = 1; lc <= n; lc++) {
        for (int cc = 0; cc < lc; cc++) {
            printf("#");
        }
        printf("\n");
    }

    // Parte decrescente do triângulo
    for (int ld = n - 1; ld > 0; ld--) {
        for (int cd = 0; cd < ld; cd++) {
            printf("#");
        }
        printf("\n");
    }
}

int main() {
    int numero;

    printf("Digite um número: ");
    scanf("%d", &numero);

    escrever_triangulo(numero);

    return 0;
}
