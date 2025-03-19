#include <stdio.h>



void maiorSequencia(int *s, int tamanho) {
    int i;
    int m = s[0];  

    for (i = 1; i < tamanho; i++) {  
        if (s[i] > m) {
            m = s[i];  
        }
    }

    printf("O maior valor no array é: %d\n", m);  
}

int main(){
    int v[7] = {40,20,70,10};
    maiorSequencia (v , 7); 
}