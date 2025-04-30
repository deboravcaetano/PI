#include <stdio.h>
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



int main() {
    // Criar uma lista ligada de exemplo: 4 -> 1 -> 2 -> 3 -> NULL
    LInt l = NULL;
    LInt temp;
    
    temp = malloc(sizeof(struct lligada));
    temp->valor = 3;
    temp->prox = NULL;
    l = temp;
    
    temp = malloc(sizeof(struct lligada));
    temp->valor = 2;
    temp->prox = l;
    l = temp;
    
    temp = malloc(sizeof(struct lligada));
    temp->valor = 1;
    temp->prox = l;
    l = temp;

    temp = malloc(sizeof(struct lligada));
    temp->valor = 4;
    temp->prox = l;
    l = temp;
    
    // Testar a função length
    printf("Comprimento da lista: %d\n", length(l)); 
   
    while(l != NULL) {
        temp = l;
        l = l->prox;
        free(temp);
    }
    
    return 0;
}