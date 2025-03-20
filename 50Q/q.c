#include <stdio.h>

#include <stdio.h>

int comunsOrd (int a[], int na, int b[], int nb){
    int i;
    int iguais=0;
    for(i=0; i<na;i++){
        for(int j=0;j<nb;j++){
            if(a[i]==b[j]) iguais++;
        }
    } 
    return iguais; 
    
}



int main() {
    int exemplo[] = {1,2,3,4,5};
    int exemplo1[]={4,5,6,7,8,9};
    int comuns = comunsOrd(exemplo,5,exemplo1,6);
    printf("O número de elementos em comum é: %d\n", comuns);
    return 0;
}

