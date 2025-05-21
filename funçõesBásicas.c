// fatorial

int fatorial(int x){

    if(x == 0) return 1;
    
    return x * fatorial (x-1);
}

int factorial (int x){
    int i;
    int r = 1;
    for(i = 1; i <= x; i++){
        r = r * i;
    }
    return r;
}


// sequência fib

int fib (int x){
    if ( x < 2) return 1;
    return (fib(x-1) + fib(x-2));
}

int fibb (int x){
    int t[x + 1];
    int i;
    t[0] = 1;
    t[1] = 1;

    // Preenche as células
    for (i = 2 ; i <= x; i++){
        t[i] = t[i-1] + t[i-2];
    }

    return t[x];
}


// Soma elementos de um array
int somaElem(int v[], int n){
    int r = 0;
    for(int i = 0 ; i < n; i++){
        r = r + v[i];
    }

    return r;
}

// Procura num array devolvendo o índice
int procura (int x, int v[], int n){
    for(int i = 0; i < n; i++){
        if (x == v[i]) return i;
    }
    return (-1);
}


// Procura num array em ordenado
int procuraE(int x, int v[], int n) {
    if (n == 0) return -1;

    int meio = n / 2;
    if (x == v[meio]) return meio;
    if (x < v[meio]) return procuraE(x, v, meio);

    // Procura na direita
    int res = procuraE(x, v + meio + 1, n - meio - 1);
    // Se não encontrou
    if (res == -1) return -1;
    // Se encontrou temos de ajustar o índice
    else return res + meio + 1;
}

// De outra forma em que não é preciso ajustar os índices, é usar limite inferior e superior
int procuraO(int x, int v[], int n){
    return procuraB(x,v,0,n-1);
}

int procuraB(int x, int v[], int i, int s){
    if (i > s) return (-1);
    int m = (i+1)/2;
    if(x == v[m]) return m;
    if(x < v[m]) return procuraB (x, v, i, m-1);
    else return procuraB(x,v,m+1,s);
}

void inverteArray(int v[], int n) {
    int i = 0;
    int j = n - 1;
    int temp;

    while (i < j) {
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++;
        j--;
    }
}

// Remove elementos específicos
int remove(char s[]){
    int i;
    int j = 0;
    for(i = 0; s[i] != '\0';i++){
        if(s[i] == 'condição'){
        }else{
            s[j]=s[i];
            j++;
        }
    }
    s[j] = '\0'; // apenas se for char
}


//---- STRINGS -----------------------------------------------------------------------------------------------------------------------

// Comprimento de uma string
int comprimento(char s[]) {
    int i = 0;
    int comp = 0;
    while (s[i] != '\0') {
        comp++;
        i++;
    }
    return comp;
}


// Conta os dígitos
int isDigit(char c){
    return (c >= '0' && c <= '9');
}

int contaDig( char s[]){
    int i = 0;
    int cont = 0;
    while(s[i]!= '\0'){
        if (isDigit(s[i])) cont ++;
        i++;
    }
    return cont;
}

// Com for
int contaDig(char s[]) {
    int cont = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (isDigit(s[i])) cont++;
    return cont;
}


// Copiar string
char* copiaS(char dest[], char orig[]){
    int i;
    for(i = 0; i != '\0'; i++){
        dest[i] = orig[i];
    }
    dest[i] = '\0';

    return dest;
}

// Concatenar strings
char* concatena (char a[], char b[]){
    int i,j;
    for(i=0; a[i] != '\0';i++){}
    for(j=0,b[j] != '\0';j++){
        a[i]=b[j];
        i++;
    }
    a[i] = '\0';
    return a;
}

// --------- STACKS ----------------------------------------------------------------------------------------------------------------------------------------
typedef struct stack{
    int cap;
    int *valores;
    int sp;
} STACK;

void initS (STACK *s){
    s->cap = 7;
    s->valores = malloc (7 * sizeof(int));
    s->sp=0;
}

int push(int x, STACK *s){
    int *t;
    if(s->sp == s->cap){
        t = s->valores;
        s->valores = malloc (2 * s->cap * sizeof(int));
        for(int i = 0; i < s->cap;i++) s->valores[i] = t[i];
        free(t);
        s->cap = s->cap * 2;
    }
    s->valores[s->sp ++] = x;

    return 0;
}


typedef struct lista{
    int valor;
    struct lista *prox;
} * Lista;

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;


LInt insertOrd(LInt *l, int e) {

    LInt novo = malloc(sizeof(struct lligada));
    novo->valor = e;
    novo->prox = NULL;

    LInt *atual;
    atual = l;
    
    LInt ant = NULL;

    while (*atual != NULL && (*atual)->valor < e) {
        ant = *atual;
        atual = &((*atual)->prox);
    }

    if (ant == NULL) {
        novo->prox = *l;
        *l = novo;
    } else {
        novo->prox = *atual;
        *atual = novo;
    }

    return *l; // Retorna o início da lista
}
