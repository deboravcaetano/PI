#include <stdio.h>

void desenhaTabuleiro(int dimensao) {
    for (int l = 0; l < dimensao; l++) { // Loop para as linhas
        for (int c = 0; c < dimensao; c++) { // Loop para as colunas
            if ((l + c) % 2 == 0) { // Alterna entre '#' e '_'
                printf("#");
            } else {
                printf("_");
            }
        }
        printf("\n"); // Move para a próxima linha após cada linha completa
    }
}

/*
A soma dos índices l e c determina se a posição é par ou ímpar:

    Se (l + c) for par, imprime '#'.
    Se (l + c) for ímpar, imprime '_'.

*/

int main() {
    int tamanho;

    printf("Insira o tamanho do tabuleiro: ");
    scanf("%d", &tamanho);

    if (tamanho > 0) {
        desenhaTabuleiro(tamanho);
    } else {
        printf("Insira um número positivo.\n");
    }

    return 0;
}

