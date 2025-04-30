#include <stdlib.h>
#include <stdio.h>

typedef struct lligada {
        int valor;
        struct lligada *prox;
    } *LInt;

LInt reverse(LInt l){
    LInt t = NULL;
    LInt temp;
    
    while(l != NULL){
        temp = l->prox;
        l->prox = t;
        t = l;
        l = temp;

    }
    return t;
}