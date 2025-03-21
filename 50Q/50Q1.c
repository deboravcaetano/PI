#include <stdio.h>

/*
Notas:
- verificar :10,26,34
- importantes: 13,16,33


*/

// ex1

int maiorSequencia(int n){
    int n ,maior=0;

    scanf("%d", &n);
    maior = n;

    while(n!=0){
        scanf("%d", &n);
        if(n>maior){
            maior=n;
        }
    }
    printf("O maior valor da sequência é:%d\n", maior);
    return maior;

}


// ex2

float mediaSequencia(){
    int n, j=0; // j conta o número de números lidos
    float media=0;

    scanf("%d", &n);
    float soma = 0;
    while(n!=0){
        soma+=n;
        scanf("%d", &n);
        j++;
    }

    media=soma/j;

    printf("A média da sequência é:%f\n", media);
    return media;
}

// ex3

int segundoMaior(){
    int n, maior=0, smaior=0;

    scanf("%d", &n);
    maior=n;

    while(n!=0){
        scanf("%d", &n);
        if(n>maior){
            smaior = maior;
            maior = n;
        }
    }

    printf("%d", smaior);

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
}

// ex5

int trailingZ(unsigned int n) {
    int cont = 0;
    while (n > 0 && (n % 2 == 0)) {  // Continua enquanto o último bit é 0
        cont++;
        n = n / 2; 
    }
    return cont; 
}

/*
Nota: o 0 ou 1 que sai da primeira divisão por 2 é o do bit menos signficativo
Ex: n = 12 que em binário é 1100, trailingZ vai verificar se n em binário tem 0s da direita para a esquerda
*/


// ex6

int qDigFor(unsigned int n) {
    int count;
    if (n == 0) {
        return 1;  // Caso especial: o número 0 tem 1 dígito
    }
    for (count = 0; n > 0; count++) {
        n /= 10;
    }
    return count;
}

// ex7

char *strcat(char s1[], char s2[]) {
    int i, j;

    // Encontra o final da string s1
    for (i = 0; s1[i] != '\0'; i++); // Loop vazio: apenas avança 'i'

    // Copia s2 para o final de s1
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

    // Se chegamos aqui, uma das strings (ou ambas) terminou
    if (s1[i] == '\0' && s2[i] == '\0') {
        return 0;  // As strings são iguais
    } else if (s1[i] == '\0') {
        return -1; // s1 é mais curta, então é menor
    } else {
        return 1;  // s2 é mais curta, então s1 é maior
    }
}

// ex10

char *strstr(char s1[], char s2[]) {
    int i, j;
    
    
    for (i = 0; s1[i] != '\0'; i++) {
        // Verifica se os caracteres de s2 correspondem aos de s1 a partir de i
        for (j = 0; s2[j] != '\0' && s1[i + j] == s2[j]; j++);
        
        // Se chegamos ao final de s2, encontramos a substring
        if (s2[j] == '\0') {
            return &s1[i];
        }
    }

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

// ver explicação folha 50 questões

// ex13

char truncW(char t[], int n) {
    int i;
    int j=0;
    int contLetras = 0;  

    for(i=0;t[i]!='\0';i++){
        if (contLetras < n && t[i] != ' ') {
            // se ainda não atingimos o limite da palavra e não é um espaço
            t[j] = t[i];
            j++;
            contLetras++;
        } 
        else if (t[i] == ' ') {
            // encontramos um espaço: termina a palavra atual
            t[j] = ' ';
            j++;
            contLetras = 0;  // reinicia o contador para a próxima palavra
        }
        // se contPalavra >= n e não é espaço, ignoramos o caracter (truncamento)
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
    int i, freqMax = 0, freqAtual;
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
    int i, consec = 1, max = 0;
    for(i = 0; s[i]; i++) {
        if(s[i] == s[i + 1]) consec++;
        else {
            if(consec > max) max = consec;
            consec = 1;
        }
    }
    return max;
}

// ex16

// ex17

int maiorPrefixo (char s1 [], char s2 []) {
    int i;
    for(i = 0; s1[i] == s2[i] && s1[i]; i++);
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
    int dentroDaPalavra = 0; // vai funcionar como flag indicar se estamos dentro de uma palavra

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

/*
-> o ' ' indica se estou dentro de uma palavra ou não, se s[i]= ' ' então não estou dentro de uma palavra
-> se s[i] não é um ' ' e estamos dentro de uma palavra, então aumentamos o contador que conta o número de palavras

nota: podemos colocar no (!dentroDaPalavrs)==1, na próxima iteração já não entra nesse if pois (!1) é 0 
*/

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

// verifica se o caracter de da string a existe na string b
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

// função que verifica todos os caracteres
int contida(char a[], char b[]) {
    int i;
    int contido = 1; // Assume que todos os caracteres estão contidos

    for (i = 0; a[i] != '\0' && contido == 1; i++) {
        if (charCont(a[i], b) == 0) {
            contido = 0; // Se algum caractere não estiver em b, marca como falso
        }
    }

    return contido; // Retorna o resultado
}

*/

// ex23

int palindromo(char s[]) {
    int i, j;
    int igual = 1; // assume que a string é um palíndromo
    int tam = strlen(s); 

    for (i = 0, j = tam - 1; i < j && igual == 1; i++, j--) {
        if (s[i] != s[j]) {
            igual = 0; 
        }
    }

    return igual; 
}

// ex24

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

/*
int remRep (char x[]){
    int i,j=0;
    for(i=0;x[i]!='\0';i++){
        while(x[i]==x[i+1]){
            for(j=i;x[j]!='\0';j++){
                x[j]=x[j+1];
            }
        }
    } 
    x[j] = '\0'; 
    return j;
}  

int main(){
    char exemplo[]="aaabaaabbbaaa";
    int novoComprimento = remRep(exemplo);
    printf("A string modificada é: %s\n",exemplo);
    printf("O tamanho da nova string é: %d\n", novoComprimento);
    return 0;
}
*/

// ex25

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

/*
int limpaEspacos(char t[]) {
    int i, j = 0;


    for (i = 0; t[i] != '\0'; i++) {
        // se o caractere atual for um espaço e o próximo também for um espaço, não copia
        if (t[i] == ' ' && t[i + 1] == ' ') {
        } else {
            t[j] = t[i]; 
            j++; 
        }
    }

    t[j] = '\0';
    return j; 
}
*/

// ex26

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


/*
int main() {
    int a[] = {1, 3, 5, 7}; // Vetor a
    int na = 4; // Tamanho de a

    int b[] = {2, 4, 6, 8, 10}; // Vetor b
    int nb = 5; // Tamanho de b

    int r[na + nb]; // Vetor resultante

    // Chama a função merge
    merge(r, a, b, na, nb);

    // Imprime o vetor resultante
    printf("Vetor resultante (merge de a e b): ");
    for (int i = 0; i < na + nb; i++) {
        printf("%d ", r[i]);
    }
    printf("\n");

    return 0;
}
*/

// ex28 

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

int elimRep(int v[], int n) {
    int i, j = 0; 
    for (i = 0; i < n; i++) {
        int duplica = 0; // flag para verificar se é duplicação
        // verifica se o v[i] já existe nas posições anteriores, k "reseta" para 0 a cada iteração do for externo pois é uma variável local
        for (int k = 0; k < j; k++) {
            if (v[i] == v[k]) {
                duplica = 1; 
            }
        }
        // se não for duplicação, adiciona ao vetor (se duplica=1, !duplica=0 e não copia)
        if (!duplica) {
            v[j] = v[i]; 
            j++; 
        }
    }

    return j; 
}

// ex34

int elimRepOrd(int v[], int n) {
    int i, j = 0;
    for (i = 0; i < n - 1; i++) { // itera até o penúltimo elemento
        if (v[i] != v[i + 1]) { // cuidado ao comparar com posições fora do array por isso ´i<n-1´
            v[j] = v[i]; 
            j++; 
        }
    }
    v[j] = v[n - 1]; 
    j++; 
    return j; 
}

// ex35

int comunsOrd(int a[], int na, int b[], int nb) {
    int i = 0, j = 0; 
    int iguais = 0;   

    // Enquanto não chegarmos ao final de nenhum dos arrays
    while (i < na && j < nb) {
        if (a[i] < b[j]) {
            i++; // Avança no vetor a
        } else if (a[i] > b[j]) {
            j++; // Avança no vetor b
        } else {
            iguais++; // Encontrou um elemento em comum
            i++; // Avança em ambos os arrays
            j++;
        }
    }

    return iguais; // Retorna o número de elementos em comum
}

// ex36

int comuns (int a[], int na, int b[], int nb){
    int i;
    int iguais=0;
    for(i=0; i<na;i++){
        for(int j=0;j<nb;j++){
            if(a[i]==b[j]) iguais++;
        }
    } 
    return iguais; 
    
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

/*
Ac[0]=v[0]
Ac[1]=v[0]+v[1]
Ac[2]=v[0]+v[1]+v[2]
Ac[3]=v[0]+v[1]+v[2]+v[3], ou seja Ac[3]=Ac[2]+v[3] 
*/

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

// ex39

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

/*
int main() {
    float matriz[3][3] = {
        {1, 2, 3},
        {0, 5, 0},
        {0, 0, 9}
    };
    if (triSup(3, matriz)) {
        printf("A matriz é triangular superior.\n");
    } else {
        printf("A matriz não é triangular superior.\n");
    }
    return 0;
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

// ver desenho na folha das 50 questoes


// ex41

void addTo(int N, int M, int a[N][M], int b[N][M]) {
    int i, j;
    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            a[i][j] += b[i][j];
        }
    }
}

/*
int main(){
    int a[3][4] = { {3,4,5,1}, {6, 7,8,1} ,{9,10,11,1}};
    int b[3][4] = { {0,1, 2,1}, {3, 1,1,1},{1,1,1,1} };
    addTo(3,4,a,b);
    for (int i = 0; i < 3; i++) {
        for(int j=0;j<4;j++){
            printf("%d ", a[i][j]);
        }
    }
    printf("\n");
}
*/

// ex42









