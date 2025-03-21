#include <stdio.h>

float mediaSequencia(){
    int n, j=0;
    float media=0;

    scanf("%d", &n);
    float soma = 0;
    while(n!=0){
        soma+=n;
        scanf("%d", &n);
        j++;
    }

    media=soma/j;

    printf("A média da sequência é:%f\n", media);
    return media;
}

int main(){
    mediaSequencia();
    return 0;
}
