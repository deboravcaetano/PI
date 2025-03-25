#include <stdio.h>

float multInt1(int n, float m) {
    float r = 0; // Inicializa r com 0
    for (int i = 0; i < n; i++) { // Loop n vezes
        r += m;
    }
    return r;
}

/* ou:
.
.
while (n > 0){
  r = r + y; x--;
}



*/
int main() {
    int n;
    float m;

    // Solicita entrada do utilizador
    printf("Digite um inteiro n: ");
    scanf("%d", &n);
    printf("Digite um número real m: ");
    scanf("%f", &m);

    // Chama a função e imprime o resultado
    float resultado = multInt1(n, m);
    printf("Resultado de %d * %.2f = %.2f\n", n, m, resultado);

    return 0;
}