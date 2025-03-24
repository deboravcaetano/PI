#include <stdio.h>
#include <stdlib.h>

typedef enum movimento {
    Norte, 
    Oeste, 
    Sul, 
    Este
    } Movimento;

typedef struct posicao {
        int x, y;
        } Posicao;

int vizinho(Posicao a, Posicao b) {
    int dx = abs(a.x - b.x); 
    int dy = abs(a.y - b.y); 
    return (dx + dy == 1); // 1 = adjacente
}

int vizinhos(Posicao p, Posicao pos[], int N) {
    int cont = 0; 
    for (int i = 0; i < N; i++) {
        if (vizinho(p, pos[i])) {
            cont++;
        }
    }
    return cont;
}

int main() {
    Posicao p = { 2,2 };
    Posicao pos[4] = { {2,3}, {0,2}, {1,2}, {3,3} };

    int num_vizinhos = vizinhos(p, pos, 4);
    printf("Número de vizinhos: %d\n", num_vizinhos); 

    return 0;
}