#include <stdlib.h>

typedef struct lligada {
        int valor;
        struct lligada *prox;
    } *LInt;


int removeOneOrd(LInt *l, int e) {
    LInt p = *l;
    LInt ant = NULL;

    // Percorre a lista até encontrar o elemento ou chegar ao fim
    while (p != NULL && p->valor < e) {
        ant = p;
        p = p->prox;
    }

    // Se o elemento não existir ou a lista estiver vazia
    if (p == NULL || p->valor != e) {
        return 1; // Elemento não encontrado
    }

    // Remove o elemento
    if (ant == NULL) {
        *l = p->prox; // Remove o primeiro nó
    } else {
        ant->prox = p->prox; // Remove um nó do meio ou final
    }

    free(p); // Liberta a memória do nó a remover
    return 0; 
}