#include <stdlib.h>
#include <stdio.h>

typedef struct lligada {
        int valor;
        struct lligada *prox;
    } *LInt;

void freeL(LInt l){
    LInt temp;
    while(l != NULL){
        temp = l; // Guarda o nó atual
        l = l->prox;   // Avança
        free(l);       // Liberta o nó atual
    } 
}
