// 50 QUESTÕES


// PARTE 1: LISTAS LIGADAS

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
        free(temp);    // Liberta o nó atual
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

    LInt y = *l;     // Aponta para o início da primeira metade
    LInt p = NULL; // Guarda o último nó da primeira metade

    while(nElem < meio) {
        p = (*l); // ant aponta para o nó atual
        (*l) = (*l)->prox;
        nElem++;
    }
    p->prox = NULL; // Corta a ligação entre as duas metades
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
    LInt ant = NULL;              // Guarda o nó anterior ao nó atual
     LInt p = *l;                 // Avança na lista
    LInt antMaiorV = NULL;        // Guarda o nó anterior ao nó com o maior valor encontrado até o momento
    LInt noMaior = *l;            // Aponta para o nó com o maior valor.

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
    } else {          // Remove no meio ou fim
        antMaiorV->prox = noMaior->prox;
    }
    free(noMaior);

    return maiorValor;
}

// 13

void init(LInt *l) {
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

LInt cloneRev (LInt l){
    LInt clone = cloneL(l);

    return reverse(clone);
}

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
//////////////REVER
int take(int n, LInt *l) {
    LInt p = *l;
    int cont = 0;

    // Percorrer até ao (n-1)-ésimo elemento
    while (p != NULL && cont < n - 1) {
        p = p->prox;
        cont++;
    }

    // Se lista tinha menos de n elementos
    if (p == NULL)
        return cont;

    // Libertar a partir do n-ésimo
    LInt libert = p->prox;
    p->prox = NULL;  // cortar a lista aqui
    while (libert != NULL) {
        LInt temp = libert->prox;
        free(libert);
        libert = temp;
    }

    return n;
}


// 20

int drop(int n, LInt *l) {
    int cont = 0;

    while (*l != NULL && cont < n) {
        LInt temp = *l;       // Guarda o nó atual
        *l = (*l)->prox;      // Avança a cabeça da lista
        free(temp);           // Liberta o nó antigo
        cont++;
    }

    return cont;
}


// 21

LInt Nforward (LInt l, int N){
    while(N > 0){
        l = l->prox;
        N--;
    }
    return l;
}

// 22

int listToArray (LInt l, int v[], int N){
    int i;
    
    for(i = 0; i < N && l != NULL; i++, l = l->prox){
        v[i] = l->valor;
    }
    
    return i;
}

// 23
LInt new(int h, LInt t){
    LInt r = malloc(sizeof(struct lligada));
    r -> valor = h;
    r -> prox = t;
    return r;
}

LInt arrayToList(int v[], int N) {
    LInt r = NULL;
    int i;
    for (i = N - 1; i >= 0; i--) {
        r = new(v[i], r);
    }
    return r;
}

// 24


LInt new(int h, LInt t) {
    LInt r = malloc(sizeof(struct lligada));
    r->valor = h;
    r->prox = t;
    return r;
}


LInt somasAcL(LInt l) {
    int soma = 0;
    LInt lista = NULL;

    while (l != NULL) {
        soma += l->valor; 
        lista = new(soma, lista); 
        l = l->prox; 
    }
    
    // Ter cuidado quando a lista é construída ao contrário
    return reverse(lista); 
}

// 25

void remreps(LInt l) {
    if(l != NULL) {
        while(l->prox != NULL) {
            if(l->prox->valor == l->valor) {
                LInt temp = l->prox;
                l->prox = temp->prox;
                free(temp);
            }
            else l = l->prox;
        }
    }
}

// 26

LInt rotateL(LInt l) {
    // Se for vazia ou tiver apenas um elemento, não há qualquer efeito
    if (!l || !(l->prox)) return l;

    LInt p = l;
    // Identificar o último nó
    while (p->prox != NULL) {
        p = p->prox;
    }

    // O último nó agora aponta para o primeiro
    p->prox = l;

    // O primeiro nó agora vai para o fim, então ajustamos o ponteiro 'prox' para NULL
    l = l->prox;
    p->prox->prox = NULL;

    return l;
}

// 27

LInt parte(LInt l) {
    // Vazia ou só um elemento
    if(!l || !l->prox) return NULL;

    // Primeria posição par
    LInt newL = l->prox;

    // Atualiza l
    l->prox = l->prox->prox;

    // Recursividade
    newL->prox = parte(l->prox);

    return newL;
}

// PARTE 2: ÁRVORES BINÁRIAS

typedef struct nodo {
        int valor;
        struct nodo *esq, *dir;
} *ABin;


// 28

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int altura(ABin a) {
    if (!a) return 0;  // Caso base: árvore vazia

    int alturaEsq = altura(a->esq);
    int alturaDir = altura(a->dir);

    
    return (1 + max(alturaEsq, alturaDir));
}

// 29

ABin cloneAB(ABin a) {
    if(a == NULL) return NULL;

    ABin nodo = malloc(sizeof(struct nodo));
    nodo->valor = a->valor;
    nodo->esq = cloneAB(a->esq);
    nodo->dir = cloneAB(a->dir);

    return nodo;
}

// 30

void mirror(ABin * tree) {
    if((*tree) != NULL) {
        ABin temp = (*tree)->esq;
        (*tree)->esq = (*tree)->dir;
        (*tree)->dir = temp;

        mirror(&((*tree)->esq));
        mirror(&((*tree)->dir));
    }
}

// 31

// inorder: esquerda-raiz-direita

// Está a criar a lista ao contrário, portanto, primeiro direita, raiz e esquerda
void inorderaux(ABin a, LInt * l) {
    LInt aux;
    if(a != NULL) {
        // Direita
        inorderaux(a->dir,l);

        // Raíz
        aux = malloc(sizeof(struct lligada));
        aux->valor = a->valor;
        aux->prox = *l;

        *l = aux;

        // Esquerda
        inorderaux(a->esq,l);
    }
}

void inorder (ABin a, LInt * l) {
    *l = NULL;
    inorderaux(a,l);
}

// 32

// pre-order: raíz-esquerda-direita

void preorderaux(ABin a, LInt * l) {
    LInt aux;
    if(a != NULL) {

        // Direita
        inorderaux(a->dir,l);

         // Esquerda
        inorderaux(a->esq,l);

        // Raíz
        aux = malloc(sizeof(struct lligada));
        aux->valor = a->valor;
        aux->prox = *l;

        *l = aux;

    }
}

void preorder (ABin a, LInt * l) {
    *l = NULL;
    preorderaux(a,l);
}

// 33

// post-order: esquerda-direita-raíz

void posorderaux(ABin a, LInt * l) {
    if(a != NULL) {
        LInt aux = malloc(sizeof(struct lligada));
        // Raíz
        aux->valor = a->valor;
        aux->prox = *l;
        *l = aux;

        // Direita
        posorderaux(a->dir,l);

        //Esquerda
        posorderaux(a->esq,l);
    }
}

void posorder(ABin a, LInt * l) {
    *l = NULL;
    posorderaux(a,l);
}

// 34

int depth(ABin a, int x) {
    if (!a) return -1;

    if (a->valor == x) return 1;

    // Procura o x na esquerda e na direita
    int esq = depth(a->esq, x);
    int dir = depth(a->dir, x);

    // Se não foi encontrado em nenhum lado
    if (esq == -1 && dir == -1) {
        return -1;
    }

    // Se só foi encontrado na dir
    if (esq == -1) {
        return 1 + dir;
    }

    if (dir == -1) {
        return 1 + esq;
    }

    // Se foi encontrado nos dois lados, retornamos o menor nível
    if (esq < dir) {
        return 1 + esq;
    } else {
        return 1 + dir;
    }
}

// 35

int freeAB (ABin a){
    if(a != NULL){
        ABin e = a->esq;
        ABin d = a->dir;

        free(a);

        return 1 + freeAB(e) + freeAB(d);
    }
    return 0;
}

// 36

/*
Remove todos os elementos da árvore *a que estão a uma profundidade superior a l, retornando o número de elementos removidos.
*/

int pruneAB (ABin *a, int l){
    if(!*a) return 0;

    if(l == 0){
        int c = freeAB(*a); 
        *a = NULL; 

        return c;
    }
    if(l == 1){
        ABin e = (*a)->esq;
        ABin d = (*a)->dir;
        (*a)->dir = NULL;
        (*a)->esq = NULL;

        return freeAB(e) + freeAB(d);
    }

    int e = pruneAB(&(*a)->esq, l-1);
    int d = pruneAB(&(*a)->dir, l-1);

    return e + d;
}

// 37

/*
Se são nulas ou se uma é nula e a outra não ...
*/

int iguaisAB (ABin a, ABin b){
    return  (!a && !b) || ((a && b) && (a->valor == b->valor) && iguaisAB(a->esq, b->esq) && iguaisAB(a->dir,b->dir));
}

// 38

void nivelLAux(ABin a, LInt *l, int n){
    if(a != NULL && n > 0){
        if(n == 1){
            LInt aux = malloc(sizeof(struct lligada));
            aux->valor = a->valor;
            aux->prox = *l;
            *l = aux;
        }
        nivelLAux(a->dir, l, n-1);
        nivelLAux(a->esq, l, n-1);
    }
}
LInt nivelL (ABin a, int n){
    LInt l = NULL;

    if(n > 0) nivelLAux(a,&l,n);

    return l;
}

// 39

int nivelV (ABin a, int n, int v[]){
    if(!a || n < 1) return 0;

    if(n == 1){
        *v = a->valor;
        return 1;
    }

    int e = nivelV(a->esq, n-1, v);

    // começa a preencher com os valores da direita no sítio onde parou na esquerda
    int d = nivelV(a->dir, n-1, v+e);

    return e+d;
}

// 40

// in-order: esquerda-raiz-direita

int dumpAbin (ABin a, int v[], int N){
    if(!a || N < 1) return 0;

    // Esquerda
    int e = dumpAbin(a->esq, v, N);

    if(e < N){
        // Raíz
        v[e] = a->valor;
        // Direita
        return 1 + e + dumpAbin(a->dir, v+e+1, N-e-1);
    }
    return N;
}

// 41

ABin somasAcA (ABin a){
    // Se a árvore original é vazia
    if(!a) return NULL;


    // Se a esquerda e direita são vazias, só existe a raíz
    if(!a->dir && !a->esq){
        // Copiamos apenas a "bolinha" da raíz
        ABin nova = malloc(sizeof(struct nodo));
        nova->valor = a->valor;
        nova->dir = NULL;
        nova->esq = NULL;
        return nova;
    }

    // Caso contrário, temos uma árvores mais complexa
    ABin nova = malloc(sizeof(struct nodo));
    nova->esq = somasAcA(a->esq);
    nova->dir = somasAcA(a->dir);

    // Se existem os dois lados
    if(nova->esq && nova->dir) {
        nova->valor = a->valor + nova->esq->valor + nova->dir->valor;
    }
    // Se só existe um:
    else if(nova->dir) {
        nova->valor = a->valor + nova->dir->valor;
    }
    else if(nova->esq) {
        nova->valor = a->valor + nova->esq->valor;
    }

    return nova;
}

// 42

int contaFolhas (ABin a){
    // Se a é vazia
    if(!a) return 0;

    // Se só existe a raíz
    if(!a->dir && !a->esq) return 1;

    // Se é maix complexa, não contamos a raiz e fazemos a soma na esq e dir
    return contaFolhas(a->dir) + contaFolhas(a->esq);
}


// 43

ABin cloneMirror (ABin a){
    if(!a) return NULL;
    
    ABin nova = malloc(sizeof(struct nodo));
    nova->valor = a->valor;

    // Copiamos os valores da direita para a esquerda
    nova->esq = cloneMirror(a->dir);

    // Copiamos os valores da esquerda para a direita
    nova->dir = cloneMirror(a->esq);

    return nova;
}

// 44

// 45

int lookupAB (ABin a, int x){
    return (a != NULL) && ((a->valor == x) || lookupAB(a->esq,x) || lookupAB(a->dir,x));
}

// 46

int depthOrd (ABin a, int x) {
    if (!a) return -1;

    if (a->valor == x) return 1;

    int res;
    if (x < a->valor)
        res = depthOrd(a->esq, x);
    else
        res = depthOrd(a->dir, x);

    if (res == -1)
        return -1;
    else
        return 1 + res;
}


// 47

int maiorAB (ABin a){
    // Se a nodo na direita,onde estão os maiores elementos que a raíz é NULL
    if (!a->dir) return a->valor;

    // Vai procurar na direita
    return maiorAB(a->dir);
}

// 48

// 49

int quantosMaiores (ABin a, int x){
    if(!a) return 0;

    return (a->valor > x) + quantosMaiores(a->esq,x) + quantosMaiores(a->dir,x); 
}

// 50

// Como é de procura, na esquerda temos os menores e na direita os maiores

void LTBTAux(LInt l, ABin *a){
    if(l != NULL){
        LInt e = parteAmeio(&l);
        
        *a = malloc(sizeof(struct nodo));
        (*a)->valor = l->valor;
        (*a)->esq = NULL;
        (*a)->dir = NULL;
        
        LInt temp = l->prox; 
        free(l); 
        l = temp;
        
        LTBTAux(e, &(*a)->esq);
        LTBTAux(l, &(*a)->dir);
    }
}

void listToBTree (LInt l, ABin *a){
    *a = NULL;
    LTBTAux(l, a);
}

// 51

int todosMenores (ABin a, int x) {
    if (!a) return 1;
    return (a->valor < x) && todosMenores(a->esq, x) && todosMenores(a->esq, x);
}

int todosMaiores (ABin a, int x) {
    if (!a) return 1;
    return (a->valor > x) && todosMaiores(a->dir, x) && todosMaiores(a->dir, x);
}

int deProcura (ABin a) {
    if (!a) return 1;
    return todosMenores(a->esq, a->valor) &&
           todosMaiores(a->dir, a->valor) &&
           deProcura(a->esq) &&
           deProcura(a->dir);
}




























