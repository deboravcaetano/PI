#include <stdlib.h>

typedef struct lligada {
        int valor;
        struct lligada *prox;
    } *LInt;


void insertOrd(LInt *l, int e) {
    LInt p = *l;
    LInt ant = NULL;

    LInt celula = malloc(sizeof(struct lligada));
    celula->valor = e;
    celula->prox = NULL;


    // Encontra a posição correta para inserir
    while (p != NULL && p->valor < e) {
        ant = p;
        p = p->prox;
    }


    if (ant == NULL) {
        // --- Caso 1: Inserir no início 
        celula->prox = *l;
        *l = celula;  
    } else {
        // --- Caso 2: Inserir no meio ou no final
        celula->prox = p;
        ant->prox = celula;
    }
}