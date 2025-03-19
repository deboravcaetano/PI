#include <stdio.h>
#include <string.h>

int vogal(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return 1;
    else
        return 0;
}

void duplicaSemAux(char *s) {
    int i, j;
    int len = strlen(s); // Tamanho inicial da string

    // Percorre a string original
    for (i = 0; s[i] != '\0'; i++) {
        if (vogal(s[i])) {
            // Desloca os caracteres para a direita para criar espaço
            for (j = len; j > i; j--) {
                s[j + 1] = s[j];
            }
            // Duplica a vogal
            s[i + 1] = s[i];
            i++; // Pula a vogal duplicada
            len++; // Atualiza o tamanho da string
        }
    }
    s[len] = '\0'; // Adiciona o terminador nulo no final
}

int main() {
    char str[100] = "programacao"; // Certifique-se de que há espaço suficiente para duplicar as vogais
    printf("String original: %s\n", str);
    duplicaSemAux(str);
    printf("String modificada: %s\n", str);
    return 0;
}
