#include <stdio.h>
#include <string.h>
// 3.


int expandeUmaVez  ( char s[], int rep, char c){
    for(int i = 0; i < rep; i++) s[i] = c;
    return rep;
}


int expandeAux(char s[], int offset){
    if (s[0] == '\0') return 0;
    int r = 0;
    char c = s[0];
    int rep = s[1] - '0';
    // offseet + rep - 2 é para saber o novo offset basicamente
    r += expandeAux(s + 2, offset + rep - 2);
    r += expandeUmaVez(s + offset , rep , c);

    return r;
}


int expande(char s[]){
    // o 0 é o off-set inicial, para ele saber onde escrever
    int n = expandeAux(s,0);
    s[n] = '\0';
    return n;
}



int expandeI(char s[]) {
    // Lê a string original
    int i = 0;
    // Escreve a string a ser expandida
    int j = 0; 
    // Array auxiliar
    char aux[1024];

    while (s[i] != '\0') {
        // Caracter a ser repetido
        char c = s[i];       
        // Número de vezes a repetir
        int reps = s[i+1] - '0'; 
        for (int k = 0; k < reps; k++) {
            aux[j++] = c;       
        }
        // Avança para o pŕoximo "par"
        i += 2; 
    }
    aux[j] = '\0';

    // Copia aux para s
    strcpy(s,aux);

    // Tamanho da nova string
    return j; 
} 


int main() {
    char str[] = "x3y5c1f7";
    expandeI(str);
    printf("%s\n", str); 
 
    return 0;
} 



