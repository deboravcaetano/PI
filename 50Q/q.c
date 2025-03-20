#include <stdio.h>
 


int triSup(int N, float m[N][N]) {
    int i, j, triangularSuperior = 1; // i representa as linhas e o j as colunas, temos de ter 0s quando j<i
    // percorre as linhas da matriz
    for (i = 1; i < N; i++) { // começa em 1 para ignorar a primeira linha
        for (j = 0; j < i; j++) { // percorre as colunas
            if (m[i][j] != 0) { // se encontrar um elemento diferente de zero
                triangularSuperior = 0; // define a flag como falsa (0)
            }
        }
    }
    return triangularSuperior; 

}


int main() {
    float matriz[3][3] = {
        {1, 2, 3},
        {0, 5, 0},
        {0, 0, 9}
    };
    if (triSup(3, matriz)) {
        printf("A matriz é triangular superior.\n");
    } else {
        printf("A matriz não é triangular superior.\n");
    }
    return 0;
}

