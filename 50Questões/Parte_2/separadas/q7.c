#include <stdlib.h>

typedef struct lligada {
        int valor;
        struct lligada *prox;
    } *LInt;

void merge (LInt *r, LInt a, LInt b){
    if ( a == NULL) r = b;
    if ( b == NULL) r = a;

    while( a!= NULL && b!=NULL){
        if( a->valor <= b-> valor){
            (*r)->valor = a->valor;
            a = a->prox;
        }
        else{
            (*r)->valor = b->valor;
            b = b->prox;
        }

        (*r) = (*r)->prox;

    }

    if(a == NULL){
        (*r) = b;
    }
    else{
        (*r) = a;
    }
    
}
void merge(LInt *r, LInt a, LInt b) {
    LInt *ult = r;

    if ( a == NULL) r = b;
    if ( b == NULL) r = a;

    while (a != NULL && b != NULL) {
        if (a->valor <= b->valor) {
            *ult = a;
            a = a->prox;
        } else {
            *ult = b;
            b = b->prox;
        }
        ult = &((*ult)->prox);
    }
    // Liga o restante da lista não vazia
    if (a == NULL) {
       *ult = b;
    }
    if (b == NULL) {
       *ult = a;
    }

}


void merge(LInt *r, LInt a, LInt b) {
    while (a != NULL && b != NULL) {
        if (a->valor < b->valor) {
            *r = a;
            a = a->prox;
            r = &((*r)->prox);
        } else {
            *r = b;
            b = b->prox;
            r = &((*r)->prox);
        }
    }
    if (a == NULL) *r = b;
    if (b == NULL) *r = a;
}
