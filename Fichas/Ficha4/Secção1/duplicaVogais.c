#include <stdio.h>

int vogal(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return 1;
    else
        return 0;
}

void duplicaVogais(char *s) {
    int i, j;
    char aux[200];  

    // percorrer a string original 
    for (i = 0, j = 0; s[i] != '\0'; i++, j++) {
        aux[j] = s[i];  // copia o caracter atual
        if (vogal(s[i])) { // se o caracter atual é vogal, duplica
            j++; // avança j para a próxima posição
            aux[j] = s[i]; // insere a vogal novamente
        }
    }
    aux[j] = '\0';  // termina a string auxiliar

    // copia a string auxiliar de volta para a string original 
    for (i = 0; aux[i] != '\0'; i++) {
        s[i] = aux[i];
    }
    s[i] = '\0';  // termina a string original
}

int main() {
    char v[100] = "Ola tuudo bem";
    printf("String original: %s\n", v);

    duplicaVogais(v);  

    printf("String com vogais repetidas: %s\n", v);  // imprime a string modificada

    return 0;
}