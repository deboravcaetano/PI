// 50 QUESTÕES 
#include <stdio.h>

// ex1

int maiorSequencia() {
    int n, maior;

    scanf("%d", &n);
    maior = n;

    while (n != 0) {
        scanf("%d", &n);
        if (n > maior && n != 0) {
            maior = n;
        }
    }

    return maior;
}

// ex2

float mediaSequencia() {
    int n, cont = 0; 
    float media = 0;
    float soma = 0;

    scanf("%d", &n);

    while (n != 0) {
        soma += n;
        cont++;
        scanf("%d", &n); 
    }
    media=soma/cont;

    return media;
}

// ex3

int segundoMaior() {
    int n, maior, smaior;

    scanf("%d", &n);
    if(n==0) return 0;

    maior = n;
    smaior = n; 
    
    scanf("%d", &n);
    if(n==0) return smaior;

    if (n > maior) {
        smaior = maior;
        maior = n;
    } else if (n < maior) {
        smaior = n;
    }

    while (n!=0) {
        scanf("%d", &n);
        if (n > maior) {
            smaior = maior;
            maior = n;
        } else if (n < maior && n > smaior) {
            smaior = n;
        }

    }
    return smaior;
}

// ex4

int bitsUm (unsigned int n){
    int cont=0;
    while (n > 0) {
        if ( n % 2 == 1) {
           cont ++;
        }
        n = n/2;
    }

    return cont;
}

// ex5

int trailingZ(unsigned int n) {
    int cont = 0;
    while (n > 0 && (n % 2 == 0)) {  
        cont++;
        n = n / 2; 
    }
    return cont; 
}

// ex6

int qDigFor(unsigned int n) {
    int count;
    if (n == 0) {
        return 1;  
    }
    for (count = 0; n > 0; count++) {
        n /= 10;
    }
    return count;
}

// ex7

char *strcat(char s1[], char s2[]) {
    int i, j;

    for (i = 0; s1[i] != '\0'; i++); 

    for (j = 0; s2[j] != '\0'; j++) {
        s1[i++] = s2[j];
    }
    s1[i] = '\0';

    return s1; 
}

// ex8

char *strcpy(char *dest, char source[]) {
    int i;

    for (i = 0; source[i] != '\0'; i++) {
        dest[i] = source[i];
    }

    dest[i] = '\0'; 
    return dest; 
}

// ex9

int strcmp(const char s1[], const char s2[]) {
    int i;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] < s2[i]) {
            return -1; // s1 é menor que s2
        } else if (s1[i] > s2[i]) {
            return 1;  // s1 é maior que s2
        }
    }
   
   // se chegar aqui, uma das string acabou
    if (s1[i] == '\0' && s2[i] == '\0') {
        return 0;  
    } else if (s1[i] == '\0') {
        return -1; 
    } else {
        return 1;  
    }
}

// ex10

char* strstr(char s1[], char s2[]) {
    int i1, i2;
    int encontrada;
    
    // Se s2 for vazio, retorna s1 
    if (s2[0] == '\0') {
        return s1;
    }
    
    for (i1 = 0; s1[i1] != '\0'; i1++) {
        encontrada = 1;
        for (i2 = 0; s2[i2] != '\0'; i2++) {
            if (s2[i2] != s1[i1 + i2]) {
                encontrada = 0;
                break; // pula para o próximo i1
            }
        }
        if (encontrada == 1) {
            return s1 + i1;
        }
    }
    
    return NULL;
}

// ex11

int tamanhoString(char s[]) {
    int i;
    for(i = 0; s[i] != '\0'; i++);
    return i;
}

void strrev(char s[]) {
    int i, j;
    char t;
    int tam = tamanhoString(s);
    for (i = 0, j = tam - 1; i < j; i++, j--) {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

// ex12

int vogal(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}


int strnoV(char t[]) {
    int i, j = 0; // 'i' percorre o array original e 'j' ajuda a construir o novo array

    for (i = 0; t[i] != '\0'; i++) {
        if (vogal([i])) { // se não é uma vogal, apenas avança no 'i' e não no 'j'
        } else {
            t[j] = t[i]; 
            j++; 
        }
    }

    t[j] = '\0';
}

/* outra forma:

void strnoV(char s[]) {
    int i, j;
    for (i = 0, j = 0; s[i] != '\0'; i++) {
        if (!vogal(s[i])) {
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';
}
*/

// ex13

char truncW(char t[], int n) {
    int i;
    int j=0;
    int contLetras = 0;  

    for(i=0;t[i]!='\0';i++){
        if (contLetras < n && t[i] != ' ') { // segunda condição: para não contar o espaço como um caracter caso contLetras < n
            t[j] = t[i];
            j++;
            contLetras++;
        } 
        else if (t[i] == ' ') {
            t[j] = ' ';
            j++;
            contLetras = 0;  
        }
    } 
    t[j] = '\0';  
}

// ex14

int freqC(char ch, char s[]) {
    int i, freq = 0;
    for(i = 0; s[i]; i++) {
        if(s[i] == ch) freq++;
    }
    return freq;
}

char charMaisFreq(char s[]) {
    char maisFreq = 0;
    int i;
    int freqMax = 0
    int freqAtual;

    for(i = 0; s[i]; i++) {
        if((freqAtual = freqC(s[i],s)) > freqMax) {
            freqMax = freqAtual;
            maisFreq = s[i];
        }
    }
    return maisFreq;
}

// ex15

int iguaisConsecutivos (char s[]) {
    int i;
    int consec = 1
    int max = 0;
    for(i = 0; s[i] != '\0'; i++) {
        if(s[i] == s[i + 1]) consec++;
        else {
            if(consec > max) max = consec;
            consec = 1;
        }
    }
    return max;
}

// ex16

//Verifica se o caracter na posição 'pos','j' atual, já apareceu antes na string
int caracter_nao_repetido(char s[], int pos) {
    for(int i = 0; i < pos; i++) {
        if(s[i] == s[pos]) {
            return 0; // Encontrou caracter repetido
        }
    }
    return 1; // Nenhum caracter repetido encontrado
}


int difConsecutivos(char s[]) {
    int maiorC = 0; // Armazena o maior comprimento encontrado
    int i,j;
    
    for(i = 0; s[i]; i++) {
        int compAtual = 0; // comprimento
        
        // Expande a substring enquanto os caracteres forem únicos
        for(int j = 0; s[i + j] && caracter_nao_repetido(s + i, j); j++) { 
            compAtual++;
        }
        
        // Atualiza o maior comprimento se necessário
        if(compAtual > maiorC) {
            maiorC = compAtual;
        }
    }
    
    return maiorC;
}

/*
Porque i+j?

1) 'i' marca o inicio da subtring 
2) 'j' o deslocamento a partir desse ponto

Quando estamos a procurar  a maior substring sem caracteres repetidos, precisamos:
 1) Fixar um ponto de início (i) na string principal
 2) Expandir a partir desse ponto (j) enquanto os caracteres forem únicos
*/

// ex17

int maiorPrefixo (char s1 [], char s2 []) {
    int i;
    for(i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++);
    return i;
}

// ex18

int tamanhoString(char s[]) {
    int i;
    for(i = 0; s[i] != '\0'; i++);
    return i;
}

int maiorSufixo (char s1 [], char s2 []){
    int i,j,cont;
    int tam1 = tamanhoString(s1);
    int tam2 = tamanhoString(s2);

    for(i=tam1-1,j=tam2-1; s1[i] ==  s2[j] && i != 0 && j != 0; i--,j--) cont++;
    return cont;

}

// ex19

int sufPref (char s1[], char s2[]) {
    int i1, i2 = 0;
    for(i1 = 0; s1[i1]; i1++) {
        if(s1[i1] == s2[i2]) i2++;
        else i2 = 0;
    }
    return i2;
}

// ex20

int contaPal(char s[]) {
    int i, cont = 0;
    int dentroDaPalavra = 0; 

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ' && !dentroDaPalavra) { 
            cont++; 
            dentroDaPalavra = 1; 
        }
        else if (s[i] == ' ') {
            dentroDaPalavra = 0;
        }
    }

    return cont; 
} 

// ex21

int contaVogais(char s[]) {
    char vogais[] = "aeiouAEIOU";
    int i, j;
    int numvogais = 0;
    
    for (i = 0; s[i] != '\0'; i++) {
        for (j = 0; vogais[j] != '\0'; j++) {
            if (s[i] == vogais[j]) {
                numvogais++;
            }
        }
    }
    return numvogais;
}

// ex22

// verifica se o caracter da string a existe na string b
int charCont(char c, char z[]) {
    int i;
    for (i = 0; z[i] != '\0'; i++) {
        if (c == z[i]) {
            return 1; 
        }
    }
    return 0; 
}

// função que verifica todos os caracteres
int contida(char a[], char b[]) {
    int i;
    for (i = 0; a[i] != '\0'; i++) {
        if (charCont(a[i], b) == 0) {
            return 0; 
        }
    }
    return 1; 
}

/*
sem dois returns:

int contida(char a[], char b[]) {
    int i;
    int contido = 1; // assume que todos os caracteres estão contidos

    for (i = 0; a[i] != '\0' && contido == 1; i++) {
        if (charCont(a[i], b) == 0) {
            contido = 0; 
        }
    }

    return contido; 
}

*/

// ex23

int palindromo(char s[]) {
    int i, j;
    int tam = strlen(s);

    for (i = 0, j = tam - 1; i < j; i++, j--) {
        if (s[i] != s[j]) {
            return 0; 
        }
    }

    return 1; 
}

/*
sem dois returns:

int palindromo(char s[]) {
    int i, j;
    int igual = 1; 
    int tam = strlen(s); 

    for (i = 0, j = tam - 1; i < j && igual == 1; i++, j--) {
        if (s[i] != s[j]) {
            igual = 0; 
        }
    }

    return igual; 
}

*/

// ex24

int remRep(char x[]){
    int i,j=0;
    for(i=0;x[i]!='\0';i++){
        if(x[i]==x[i+1]){
        } else {
            x[j]=x[i];
            j++;
        }
    }
    x[j]='\0';
    return j;
}

/* outra forma:

int remRep(char x[]){
    int i,j=0;
    for(i=0;x[i]!='\0';i++){
        if(x[i]!=x[i+1]){
            x[j]=x[i];
            j++;
        }
    }
    x[j]='\0';
    return j;
}

*/

// ex25

int limpaEspacos(char t[]) {
    int i, j = 0;

    for (i = 0; t[i] != '\0'; i++) {        
        if (t[i] == ' ' && t[i + 1] == ' ') {
        } else {
            t[j] = t[i]; 
            j++; 
        }
    }

    t[j] = '\0';
    return j; 
}

/* outra forma:

int limpaEspaços(char s[]) {
    int i, j = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (!(s[i] == ' ' && s[i + 1] == ' ')) {
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0'; 
    return j;
}
*/

// ex26

void insere (int v[], int N, int x) {
    int i, j, inserido = 0;
    for(i = 0; i < N && !inserido; i++) {
        if(x < v[i]) {
            for(j = N; j > i; j--) {
                v[j] = v[j - 1];
            }
            v[i] = x;
            inserido = 1;
        }
    }
    if(!inserido) v[N] = x;
}


// ex27

void merge (int r [], int a[], int b[], int na, int nb){
    int i=0;
    int j=0;
    int k = 0;
    while (i < na && j <nb){
        if (a[i] < b[j]){
            r[k++]=a[i++];
        } else {
            r[k++]=b[j++];
        }
    }
    
    while (i < na){
        r[k++]=a[i++];
    }

    while (j < nb){
        r[k++]=b[j++];
    }
}

// ex28

int crescente(int a[], int i, int j) {
    int x;
    for (x = i; x < j; x++) {
        if (a[x] > a[x + 1]) {
            return 0; 
        }
    }
    return 1; 
}

/*
sem dois returns:

int crescente(int a[], int i, int j) {
    int x;
    int res = 1;
    for (x = i; x < j && res == 1; x++) {
        if (a[x] > a[x + 1]) {
            res = 0; 
        }
    }
    return res; 
}
*/

// ex29

int retiraNeg(int v[], int N) {
    int i, j = 0; 

    for (i = 0; i < N; i++) {
        if (v[i] >= 0) {
            v[j] = v[i];
            j++; 
        }
    }
    return j;
}

// ex30

int freqInt(int n, int v[],int N){
    int i;
    int freq=0;
    for(i=0; i < N ;i++){
        if (v[i] == n) freq ++;
    }
    return freq;
}


int menosFreq (int v[], int N){
    int i;
    int menosFreq;
    int freqMin=N;
    int freqAtual;
    for(i=0; i < N ; i++){
        if((freqAtual=freqInt(v[i],v,N)) < freqMin){
            freqMin= freqAtual;
            menosFreq = v[i];

        } 
    }
    return menosFreq;
}

// ex31

int freqInt(int n, int v[],int N){
    int i;
    int freq=0;
    for(i=0; i < N ;i++){
        if (v[i] == n) freq ++;
    }
    return freq;
}

int maisFreq (int v[], int N){
    int i;
    int freqAtual;
    int freqMax=0;
    int maisFreq;
    for(i=0;i<N;i++){
        if((freqAtual=freqInt(v[i],v,N))>freqMax){
            freqMax=freqAtual;
            maisFreq=v[i];
        }

    }
    return maisFreq;
}

// ex32

int maxCresc (int v[], int N){
    int i;
    int crescConsec=1;
    int maiorConsec=0;
    for(i=0; i< N;i++){
        if(v[i]<v[i+1]) {
            crescConsec++;
        } else if(crescConsec>maiorConsec){
            maiorConsec=crescConsec;
            crescConsec=1;
        }
    }
    return maiorConsec;

}

// ex33

int  elimRep(int v[], int n) {
    int i;
    int j = 0; 
    for (i = 0; i < n; i++) {
        int ehDuplicação = 0; 
        for (int k = 0; k < j; k++) { 
            if (v[i] == v[k]) {
                ehDuplicação = 1; 
            }
        }        
        if (!ehDuplicação) {
            v[j] = v[i]; 
            j++; 
        }
    }

    return j; 
}

/*
com array auxiliar:

int elimRep(int v[], int n) {
    int aux[n]; 
    int j = 0; 

    
    for (int i = 0; i < n; i++) {
        int ehDuplicacao = 0; 
        for (int k = 0; k < j; k++) { 
            if (v[i] == aux[k]) {  
                ehDuplicacao = 1; 
            }
        }        
        if (!ehDuplicacao) {
            aux[j] = v[i]; 
            j++; 
        }
    }
    // novo array agora tem j elementos
    for (int i = 0; i < j; i++) {
        v[i] = aux[i];
    }

    return j; 
}
*/

/*
explicação:

int elimRep(int v[], int n) {
    int i;
    int j = 0; // controla a posição ondes os elementos único são colocados 
    for (i = 0; i < n; i++) {
        int ehDuplicação = 0; 
        // verifica se o v[i] já existe nas posições anteriores, 'k' "reseta" para 0 a cada iteração do 'for' externo 
        for (int k = 0; k < j; k++) { // k percorre a parte que já foi processada, de 0 a j-1 que contem os elementos únicos 
//que já foram encontrados e copiados
            if (v[i] == v[k]) {
                ehDuplicação = 1; 
            }
        }
        // se o elemento não existia nas posições anteriores, adiciona ao vetor (se duplica=1, !duplica=0 e não copia)
        if (!ehDuplicação) {
            v[j] = v[i]; 
            j++; 
        }
    }

    return j; 
}
*/

// ex34

int elimRepOrd(int v[], int n) {
    int i;
    int j = 0; 

    for (i = 0; i < n; i++) {
        if (v[i] != v[j]) { 
            j++;
            v[j] = v[i]; 
        }
    }

    return j + 1; 
}

// ex35

int comunsOrd(int a[], int na, int b[], int nb) {
    int i = 0, j = 0; 
    int iguais = 0;   

    
    while (i < na && j < nb) {
        if (a[i] < b[j]) {
            i++; // Avança no vetor a
        } else if (a[i] > b[j]) {
            j++; // avança no vetor b
        } else {
            iguais++; // encontrou um elemento em comum
            i++; // avança em ambos os arrays
            j++;
        }
    }

    return iguais; 
}

// ex36

int elem(int e, int *v, int N) {
    int i, ans = 0;
    for(i = 0; i < N && !ans; i++)
        if(e == v[i])
            ans = 1;
    return ans;
}

int comuns (int a[], int na, int b[], int nb) {
    int i, ans = 0;
    for(i = 0; i < na; i++) {
        if(elem(a[i], b, nb)) ans++;
    }
    return ans;
}

// ex37

int minInd (int v[], int n){
    int i;
    int indMenor=v[0];
    for(i=1; i < n;i++){
        if(v[i]<v[indMenor]){
            indMenor=i;
        }
    }
    return indMenor;
}

// ex38

void somasAc(int v[], int Ac[], int N) {
    // Inicializa a primeira posição de Ac
    if (N > 0) {
        Ac[0] = v[0]; // A soma acumulada do primeiro elemento é ele mesmo
    }
    // Calcula as somas acumuladas para os demais elementos
    for (int i = 1; i < N; i++) {
        Ac[i] = Ac[i - 1] + v[i]; // Ac[i] é a soma acumulada até v[i]
    }
}

/*
explicação:

/*
Ac[0]=v[0]
Ac[1]=v[0]+v[1]
Ac[2]=v[0]+v[1]+v[2]
Ac[3]=v[0]+v[1]+v[2]+v[3], ou seja Ac[3]=Ac[2]+v[3] 
*/

// ex39

int triSup(int N, float m[N][N]) {
    int i, j;

    for (i = 1; i < N; i++) {
        for (j = 0; j < i; j++) { 
            if (m[i][j] != 0) {
                return 0; 
            }
        }
    }
    return 1; 
}

/*
sem dois returns:

int triSup(int N, float m[N][N]) {
    int i, j, triangularSuperior = 1; // i representa as linhas e o j as colunas, temos de ter 0s quando j<i
    // percorre as linhas da matriz
    for (i = 1; i < N; i++) { // começa em 1 para ignorar a primeira linha
        for (j = 0; j < i; j++) { // percorre as colunas
            if (m[i][j] != 0) { // se encontrar um elemento diferente de zero
                triangularSuperior = 0; // define a flag como falsa (0)
            }
        }
    }
    return triangularSuperior; 

}
*/

// ex40

void transposta (int N, float m[N][N]) {
    int i, j;
    float armz;
    for(i = 0; i < N; i++) {
        for(j = 0; j < i; j++) {
            armz = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = armz;
        }
    }
}

// ex41

void addTo(int N, int M, int a[N][M], int b[N][M]) {
    int i, j;
    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            a[i][j] += b[i][j];
        }
    }
}

// ex42

int unionSet(int N, int v1[N], int v2[N], int r[N]) {
    int i;
    for (i = 0; i < N; i++) {
        if (v1[i] == 1 || v2[i] == 1) {
            r[i] = 1;
        } else {
            r[i] = 0;
        }
    }
    return 0; 
}


// ex43

int intersectSet(int N, int v1[N], int v2[N], int r[N]) {
    int i;
    for (i = 0; i < N; i++) {
        if (v1[i] == 1 && v2[i] == 1) {
            r[i] = 1;
        } else {
            r[i] = 0;
        }
    }
    return 0; 
}

// ex44

int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
    int i;
    for(i=0; i<N; i++){
        if (v1[i]<=v2[i]) r[i]=v1[i];
        else r[i]=v2[i];
    }
}

// ex45

int unionMSet (int N, int v1[N], int v2[N], int r[N]){
    int i;
    for(i=0; i<N; i++){
        if (v1[i]>=v2[i]) r[i]=v1[i];
        else r[i]=v2[i];
    }
}

// ex46

int cardinalMSet (int N, int v[N]) {
    int i, len = 0;
    for(i = 0; i < N; i++) len += v[i];
    return len;
}

// ex47

typedef enum movimento {
    Norte, 
    Oeste, 
    Sul, 
    Este
    } Movimento;

typedef struct posicao {
        int x, y;
        } Posicao;


Posicao posFinal (Posicao inicial, Movimento mov[], int N){
    int i;
    for(i=0;i<N;i++){
        if ((mov[i])==Norte){
            inicial.y++;
        }
        else if((mov[i])==Sul){
            inicial.y--;
        }
        else if((mov[i])==Oeste){
            inicial.x--;
        }
        else if((mov[i])==Este){
            inicial.x++;
        }

    }
    return inicial;
}

/*
int main(){
    Movimento mov[5] = { Norte, Norte, Oeste, Sul, Oeste };
    Posicao inicial = { 0, 0 };
    Posicao final = posFinal(inicial, mov, 5);
    printf("(%d, %d)\n", final.x, final.y);

    return 0;

}
*/

// ex48

int caminho(Posicao inicial, Posicao final, Movimento mov[], int N) {
    int i;
    for(i = 0; i < N && (inicial.x != final.x || inicial.y != final.y); i++) {
        if(inicial.x < final.x) {
            inicial.x++;
            mov[i] = Este;
        }
        else if(inicial.x > final.x) {
            inicial.x--;
            mov[i] = Oeste;
        } 
        else if(inicial.y < final.y) {
            inicial.y++;
            mov[i] = Norte;
        }
        else if(inicial.y > final.y) {
            inicial.y--;
            mov[i] = Sul;
        }
    }
    if(inicial.x != final.x || inicial.y != final.y) return -1;
    else return i;
}

// ex49

int maisCentral(Posicao pos[], int N) {    
    int indiceMP = 0;
    int menorDist = pos[0].x * pos[0].x + pos[0].y * pos[0].y;

    for (int i = 1; i < N; i++) {
        int distancia = pos[i].x * pos[i].x + pos[i].y * pos[i].y; //x² + y²
        if (distancia < menorDist) {
            menorDist = distancia;
            indiceMP = i;
        }
    }

    return indiceMP;
}

// ex50

int vizinho(Posicao a, Posicao b) {
    int dx = abs(a.x - b.x); 
    int dy = abs(a.y - b.y); 
    return (dx + dy == 1); // 1 = adjacente
}

int vizinhos(Posicao p, Posicao pos[], int N) {
    int cont = 0; 
    for (int i = 0; i < N; i++) {
        if (vizinho(p, pos[i])) {
            cont++;
        }
    }
    return cont;
}









