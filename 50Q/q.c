#include <stdio.h>

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

int main(){
    char exemplo[]="aa  b c";
    char comprimento= limpaEspaços(exemplo);
    printf("A string modificada é: %s\n",exemplo);
    printf("O comprimento da nova string é: %d\n",comprimento);
    return 0;
}