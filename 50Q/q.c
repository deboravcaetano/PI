#include <stdio.h>

char truncW(char t[], int n) {
    int i;
    int j=0;
    int contLetras = 0;  

    for(i=0;t[i]!='\0';i++){
        if (contLetras < n && t[i] != ' ') {
            // Se ainda não atingimos o limite da palavra e não é um espaço
            t[j] = t[i];
            j++;
            contLetras++;
        } 
        else if (t[i] == ' ') {
            // Encontramos um espaço: termina a palavra atual
            t[j] = ' ';
            j++;
            contLetras = 0;  // reinicia o contador para a próxima palavra
        }
        // Se contPalavra >= n e não é espaço, ignoramos o caracter (truncamento)
    }
    
    t[j] = '\0';  
}

int main(){
    char t[] ="liberdade, igualdade e fraternidade";
    char novaString = truncW(t,4);
    printf("A nova string é:%s\n",t);
    return 0;
}
