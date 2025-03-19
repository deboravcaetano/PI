#include <stdio.h>

void mediaSequencia (int *s, int tamanho){
    int i, acum=0;
    float media;
    for (i=0; i < tamanho; i++){
        acum += s[i];
    }
    media = acum / tamanho;

    printf("A média dos valores no array é: %f\n", media);  
}

int main(){
    int v[4] = {70,20,40,10};
    mediaSequencia (v , 4); 
}