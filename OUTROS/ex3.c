#include <stdio.h>

void segundoMaior (int s[] , int tamanho){
     int i;
     int sm;
     int maior;
     if (s [1] > s [0]) {
        maior = s [1];
        sm = s [0];
     }
     else {
        maior = s [0];
        sm = s [1];
     }
     for (i = 2 ; i < tamanho; i++){
         if ( s[i] > maior){
            sm = maior;
            maior = s[i];
         }
         else if (s [i] > sm) sm = s [i];
     }
     printf("O segundo maior valor no array é: %d\n", sm); 
}

int main(){
    int v[4] = {10,40,70,30};
    segundoMaior (v , 4); 
}