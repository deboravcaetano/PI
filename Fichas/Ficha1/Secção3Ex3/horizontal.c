#include <stdio.h>

void escrever_horizontal(int n) {
    for (int l = 1; l <= n; l++) {
        // Imprimir espaços vazios antes do #
        for (int j = 0; j < n - l; j++) {
            printf(" ");
        }

        // Imprimir os #
        for (int k = 0; k < (2 * l - 1); k++) {
            printf("#");
        }
        printf("\n");
    }
}

int main() {
    int numero;

    printf("Digite um número: ");
    scanf("%d", &numero);

    escrever_horizontal(numero);

    return 0;
}

/* ou (sem fórmulas):

void rep (int n, char c){
     int i;
     for (i=0;i < n; i++)
     putChar (c);
}

void escreve_horizontal(int n){
     int i, e=n-1,c=1; // na primeira linha, temos n-1 espaços e 1#, na segunda linha temos n-2 espaços e mais 2# que a anterior
     for (i=1; i<= n;i++){
          rep(e,' ');
          rep(c,'#');
          putChar('\n');
          e=e-1;
          c=c+2;
     }


}

*/