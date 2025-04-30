#include <stdio.h>
#include <string.h>

int contaVogais(char *s) {
    char vogais[] = "aeiouAEIOU";
    int numVogais = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        for (int j = 0; vogais[j] != '\0'; j++) {
            if (s[i] == vogais[j]) {
                numVogais++;
            }
        }
    }

    return numVogais;
}

int main() {
    char v [] = "abcgdf";
    contaVogais(v);

    printf("A string '%s' tem %d vogais.\n", v , contaVogais(v));
    return 0;
}


