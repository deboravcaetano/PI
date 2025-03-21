#include <stdio.h>

void addTo(int N, int M, int a[N][M], int b[N][M]) {
    int i, j;
    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            a[i][j] += b[i][j];
        }
    }
}

int main(){
    int a[3][4] = { {3,4,5,1}, {6, 7,8,1} ,{9,10,11,1}};
    int b[3][4] = { {0,1, 2,1}, {3, 1,1,1},{1,1,1,1} };
    addTo(3,4,a,b);
    for (int i = 0; i < 3; i++) {
        for(int j=0;j<4;j++){
            printf("%d ", a[i][j]);
        }
    }
    printf("\n");
}
