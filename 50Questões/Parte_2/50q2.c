// PARTE 2 : 50 QUESTÕES


#include <stdlib.h>

typedef struct lligada {
        int valor;
        struct lligada *prox;
    } *LInt;

// 1

int length (LInt l){
    int comprimento = 0;
    while( l != NULL){
        comprimento ++;
        l = l-> prox;
    }

    return comprimento;
}

// 2

void freeL(LInt l){
    LInt temp;
    while(l != NULL){
        temp = l;      // Guarda o nó atual
        l = l->prox;   // Avança
        free(temp);       // Liberta o nó atual
    } 
}

// 3

void imprimeL(LInt l) {
    while(l != NULL) {
        printf("%d\n",l->valor);
        l = l->prox;
    }
}

// 4

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

// 5

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
        ant->prox = celula;
        celula->prox = p;
    }
}

// 6

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

// 7

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

// 8

void splitQS(LInt l, int x, LInt *mx, LInt *Mx) {

    while (l != NULL) {
        if (l->valor < x) {
            *mx = l; // Adiciona o nó à lista dos menores
            l = l->prox;
            mx = &((*mx)->prox);
        } else {
            *Mx = l; // Adiciona o nó à lista dos maiores
            l = l->prox;
            Mx = &((*Mx)->prox);
        }
    }

    // Termina as duas listas
    *mx = NULL;
    *Mx = NULL;
}

// 9

LInt parteAmeio (LInt *l){
    int meio = length(*l)/2;
    int nElem = 0;

    if(meio == 0) return NULL;

    LInt y = *l;   // // Aponta para o início da primeira metade
    LInt ant = NULL; // Guarda o último nó da primeira metade

    while(nElem < meio) {
        ant = (*l); // ant aponta para o nó atual
        (*l) = (*l)->prox;
        nElem++;
    }
    ant->prox = NULL; // Corta a ligação entre as duas metades
    return y;
}

// 10

int removeAll(LInt *l, int e) {
    int celulasRem = 0;
    LInt p = *l;
    LInt ant = NULL;
    LInt temp;

    while (p != NULL) {
        if (p->valor == e) {
            temp = p; 
            if (ant == NULL) { // Remover o primeiro nó
                *l = p->prox;
                p = *l;
            } else {           // Remover nó do meio/fim
                ant->prox = p->prox;
                p = p->prox;
            }
            free(temp);
            celulasRem++;
        } else {
            ant = p;
            p = p->prox;
        }
    }
    return celulasRem;
}

// 11

int removeDups (LInt *l) {
    int removidas = 0;
    LInt p = *l;
    LInt temp;

    while (p != NULL && p->prox != NULL) {
        if (p->valor == p->prox->valor) {
            temp = p->prox;
            p->prox = temp->prox; // ou: p->prox = p->prox->prox;
            free(temp);
            removidas++;
        } else {
            p = p->prox;
        }
    }

    return removidas;
}

// 12

int removeMaiorL(LInt *l) {
    int maiorValor = (*l)->valor; // Armazena o maior valor encontrado.
    LInt ant = NULL; // Guarda o nó anterior ao nó atual
    LInt antMaiorV = NULL; // Guarda o nó anterior ao nó com o maior valor encontrado até o momento
    LInt noMaior = *l; // Aponta para o nó com o maior valor.
    LInt p = *l;

    // Encontrar o maior elemento
    while (p != NULL) {
        if (p->valor > maiorValor) {
            antMaiorV = ant;
            noMaior = p;
            maiorValor = p->valor;
        }
        ant = p;
        p = p->prox;
    }

    // Remover o nó do maior elemento
    if (!antMaiorV) { // Remove no início
        *l = (*l)->prox;
    } else {          // Remove no fim
        antMaiorV->prox = noMaior->prox;
    }
    free(noMaior);

    return maiorValor;
}

// 13

void init(LInt *l) {
    if (*l == NULL) return; // Lista vazia, não faz nada

    LInt p = *l;
    LInt ant = NULL;

    // Percorre até ao último nó
    while (p->prox != NULL) {
        ant = p;
        p = p->prox;
    }

    if (ant == NULL) {
        // Só existe um elemento na lista
        free(*l);
        *l = NULL;
    } else {
        // Remove o último nó
        ant->prox = NULL;
        free(p);
    }
}


// 14

void appendL (LInt *l, int e){

    LInt celula = malloc(sizeof(struct lligada));
    celula->valor = e;
    celula->prox=NULL;

    if((*l) == NULL) (*l) = celula;

    while((*l)->prox != NULL){
        l = &((*l)->prox);
    }
    (*l)->prox = celula;
}

/*
ter cuidado, se fosse lInt appendL (LInt *l, int e) iria devolver a nova lista, logo nunca poderiamos perder o início da lista:abort

LInt appendL (LInt *l, int e){
     LInt in = *l;

    LInt celula = malloc(sizeof(struct lligada));
    celula->valor = e;
    celula->prox=NULL;

    if(*l == NULL) {
       *l = celula;
       return *l;
    }

    while((*l)->prox != NULL){
        l = &((*l)->prox);
    }
    (*l)->prox = celula;

    return in;
}
*/

// 15

void concatL(LInt *a, LInt b) {
    // Se a lista *a está vazia, basta apontá-la para b
    if (*a == NULL) {
        *a = b;
    } else {
        LInt p = *a;
        // Percorre até o último nó
        while (p->prox != NULL) {
            p = p->prox;
        }
        // Liga o último nó de *a ao início de b
        p->prox = b;
    }
}


// 16

LInt cloneL(LInt l) {
    if (l == NULL) return NULL;

    LInt celula = malloc(sizeof(struct lligada));
    LInt in = celula; // Guarda o início da nova lista

    celula->valor = l->valor;
    l = l->prox;

    while (l != NULL) {
        // Cria uma célula para a qual prox aponta
        celula->prox = malloc(sizeof(struct lligada));
        // Atualizamos celula para apontar para essa nova celula
        celula = celula->prox;
        // Copiamos o valor para a nova celula
        celula->valor = l->valor;
        // Avançamos
        l = l->prox;
    }

    celula->prox = NULL; // Fim da lista
    return in;
}

// 17

// 18

int maximo(LInt l) {
    // Inicializa com o primeiro valor da lista
    int maior = l->valor;

    l = l->prox;

    while (l != NULL) {
        if (l->valor > maior) {
            maior = l->valor;
        }
        l = l->prox;
    }

    return maior;
}

// 19

















