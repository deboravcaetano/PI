// 2.

void reverse(int a[], int i, int j) {
    while (i < j) {
        int tmp = a[i];
        a[i] = a[j];
        a[i] = tmp;
        i++;
        j--;
    }
}

void rodaEsq(int a[], int N, int r) {
    if (r <= 0 || r >= N) return; // Nada a fazer

    // 1. Inverte os primeiros r elementos
    reverse(a, 0, r-1);

    // 2. Inverte os restantes N-r elementos
    reverse(a, r, N-1);

    // Inverte o array inteiro
    reverse(a, 0, N-1);
}

/*

{1,2,3,4,5,6} -> {3,4,5,6,1,2}

1. {2,1,3,4,5,6}
2. {2,1,6,5,4,3}
3. {3,4,5,6,1,2}

*/


// 3.

typedef struct lint_nodo {
    int valor;
    struct lint_nodo *prox;
} *LInt;


int delete(int n, LInt *l) {
    if (*l == NULL) return 1; 

    LInt p = *l;
    LInt ant = NULL;

    // Remover o primeiro elemento
    if (n == 0) {
        *l = p->prox;
        free(p);
        return 0;
    }

    for (int i = 0; i < n && p != NULL; i++) {
        ant = p;
        p = p->prox;
    }

    // Se não existe o n-ésimo elemento, erro
    if (p == NULL) return 1;

    // Remove o elemento
    ant->prox = p->prox;
    free(p);
    return 0;
}


// 4.

int maxCresc(LInt l) {
    if (l == NULL) return 0;

    int max = 1, consec = 1;
    int ant = l->valor;
    l = l->prox;

    while (l != NULL) {
        if (l->valor > ant) {
            consec++;
            if (consec > max) max = consec;
        } else {
            consec = 1;
        }
        ant = l->valor;
        l = l->prox;
    }
    return max;
}


// 5.

typedef struct abin_nodo {
    int valor;
    struct abin_nodo *esq, *dir;
} *ABin;


ABin folhaEsq(ABin a) {
    if (a == NULL) return NULL;

    while (a != NULL) {
        if (a->esq == NULL && a->dir == NULL) return a;
        if (a->esq != NULL) a = a->esq;
        else a = a->dir;
    }
    return NULL; 
}

// 6.

int parentesisOk(char exp[]) {
    char parentesis[100];
    int top = -1;

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        // Se for abertura empilha
        if (c == '(' || c == '[' || c == '{') {
            parentesis[++top] = c;
        }
        // Se for fechamento
        else if (c == ')' || c == ']' || c == '}') {
            if (top < 0) return 0; // Se não há topo não há correspondente de abertura

            // Verifica se combina com o topo da pilha
            char abre = parentesis[top--];
            if (( c == ')' && abre != '(' ) || ( c == ']' && abre != '[' ) || ( c == '}' && abre != '{' )) {
                return 0; 
            }
        }
    }

    return (top == -1);
}






