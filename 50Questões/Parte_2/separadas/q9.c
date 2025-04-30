#include <stdlib.h>

typedef struct lligada {
        int valor;
        struct lligada *prox;
    } *LInt;

int length (LInt l){
    int comprimento = 0;
    while( l != NULL){
        comprimento ++;
        l = l-> prox;
    }

    return comprimento;
}


LInt parteAmeio (LInt *l){
    int meio = length(*l)/2;
    int p = 0;

    if(meio == 0) return NULL;

    LInt y = (*l);   // // Aponta para o início da primeira metade
    LInt ant = NULL; // Guarda o último nó da primeira metade

    while(p < meio) {
        ant = (*l); // ant aponta para o nó atual
        (*l) = (*l)->prox;
        p++;
    }
    ant->prox = NULL; // Corta a ligação entre as duas metades
    return y;
}