#include <stdio.h>
 
int contemChar(char s[],char c){
    int i;
    int encontrado = 0;
    for(i=0; s[i] != '\0' && !(encontrado==1);i++){
        if(s[i]==c){
            encontrado=1;
        }
    }
    return encontrado;
}


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