#include <stdio.h>

float multInt2 (int n, float m){
      float r = 0; // acumula os resultados
      while (n>=1){
        if ( n% 2 != 0){
           r+=m;
        }
        n/=2;
        m*= 2;
      }
      return r;
}


int main() {
    int n;
    float m;
    // Solicita entrada do utilizador
    printf("Digite um inteiro n: ");
    scanf("%d", &n);
    printf("Digite um número inteiro m: ");
    scanf("%f", &m);

    // Chama a função e imprime o resultado
    float resultado = multInt2(n, m);
    printf("O resultado é: %.2f\n", resultado);

    return 0;
}