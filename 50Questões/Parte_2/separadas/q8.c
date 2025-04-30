#include <stdlib.h>

typedef struct lligada {
        int valor;
        struct lligada *prox;
    } *LInt;

void splitQS(LInt l, int x, LInt *mx, LInt *Mx) {

    while (l != NULL) {
        if (l->valor < x) {
            *mx = l; // Adiciona o nó à lista dos menores
            mx = &((*mx)->prox);
            l = l->prox;
        } else {
            *Mx = l; // Adiciona o nó à lista dos maiores
            Mx = &((*Mx)->prox);
            l = l->prox;
        }
    }

    // Termina as duas listas
    *mx = NULL;
    *Mx = NULL;
}

