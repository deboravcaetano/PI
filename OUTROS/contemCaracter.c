#include <stdio.h>
 
int contemChar(char s[],char c){
    int i;
    int encontrado = 0; // usamos uma flag para determinar quando encerrar o loop for
    for(i=0; s[i] != '\0' && !(encontrado==1);i++){ 
        if(s[i]==c){
            encontrado=1;
        }
    }
    return encontrado;
}

/*
O objetivo é que não faça comparações desnecessárias, ou seja, se já encontrou o elemento,
não precisa de procurar a sua existência nos próximos índices.

O loop ´for' deve parar quando for encontrado o elemento, ou seja quando encontrado == 1, ele realiza o ciclo 'for' enquanto
não encontrar -> !(encontrado==1).

*/


int main(){
    char s[] ="a abbc";
    char C;

    printf("Insira um caracter:");
    scanf("%c\n",&C);

    if(contemChar(s,C)){
        printf("O caracter foi encontrado.\n");
    }
    else {
        printf("O caracter não foi encontrado.\n");
    }
    return 0;
}