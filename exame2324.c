#include <stdio.h>
// 3.

int expande(char s[]) {
    // Lê a string original
    int i = 0;
    // Escreve a string a ser expandida
    int j = 0; 

    while (s[i] != '\0') {
        // Caracter a ser repetido
        char c = s[i];       
        // Número de vezes a repetir
        int reps = s[i+1] - '0'; 
        for (int k = 0; k < reps; k++) {
            s[j++] = c;       
        }
        // Avança para o pŕoximo "par"
        i += 2; 
    }
    s[j] = '\0';  
    // Tamanho da nova string
    return j; 
} 

/*
int main() {
    char str[] = "a2b3c1";
    expande(str);
    printf("%s\n", str); // Saída: aabbbc
 
    return 0;
} 
*/


