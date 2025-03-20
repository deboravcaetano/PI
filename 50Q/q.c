#include <stdio.h>
 


void transposta (int N, float m[N][N]) {
    int i, j;
    float armz;
    for(i = 0; i < N; i++) {
        for(j = 0; j < i; j++) {
            armz = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = armz;
        }
    }
}


int main() {
    float matriz[3][3] = {
        {4, 5, 6},
        {1, 2, 3},
        {7, 8, 9}
    };

    transposta(3, matriz);
    
    // Imprime a matriz transposta
    printf("\nMatriz transposta:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.1f ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
    
}

