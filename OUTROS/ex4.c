#include <stdio.h>

void bitsUm (unsigned int n){
    int cont=0;
    while (n > 0) {
        if ( n % 2 == 1) {
           cont ++;
        }
        n = n/2;
    }
    
    printf("O número de bits 1 é: %d\n", cont); 
}

int main(){
    unsigned int n = 00100010101;
    bitsUm(n); 
    return 0;
}