#include <stdio.h>
#include <string.h>

// com array auxiliar

int vogal (char c){
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
       return 1;
    else
       return 0;
}

int retiraVogais (char *s){
    int i,m,j = 0;
    char aux[strlen(s)];
    int rem = 0;
    for (i=0; s[i] != 0;i++){
        if (s[i] == s[i+1] && vogal (s[i])){
            rem ++;
        }
        else {
            aux[j++] = s[i];
        }
    }
    aux [i] = '\0';
    for (m=0;aux[m]!='\0';m++)
         s[m]=aux[m];
    s[m] = '\0';
    return rem;
}


int main() {
    char v[] = "Estaaa string tem vooogais repetiiidas";
    printf("String original: %s\n", v);

    int rem = retiraVogais(v); // Remove vogais repetidas

    printf("String sem vogais repetidas: %s\n", v); // Imprime a string modificada
    printf("Número de vogais removidas: %d\n", rem); // Imprime o número de vogais removidas

    return 0;
}