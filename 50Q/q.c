#include <stdio.h>

int elimRepOrd(int v[], int n) {
    int i, j = 0;
    for (i = 0; i < n - 1; i++) { // itera até o penúltimo elemento
        if (v[i] != v[i + 1]) { // cuidado ao comparar com posições fora do array por isso ´i<n-1´
            v[j] = v[i]; 
            j++; 
        }
    }
    v[j] = v[n - 1]; 
    j++; 
    return j; 
}

int main(){
    int t[] ={1,1,2,3,3,4,4};
    int numeroElem = elimRepOrd(t,7);
    printf("O novo número de elementos é: %d\n",numeroElem);
    printf("O novo vetor é: ");
    for(int i=0; t[i]<7;i++){
        printf("%d ", t[i]);
    }
    printf("\n");
    return 0;
}
