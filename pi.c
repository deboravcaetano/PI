#include <stdio.h>


void merge (int r[], int a[], int na, int b[], int nb){
    // Percorre o a
    int i = 0;
    // Percorre o b
    int j = 0;
    // Percorre o r
    int k = 0;

    while(i < na && j < nb ){
        if( a[i] < b [j]){
            r[k++] = a[i++];
        } else{
            r[k++] = b[j++];;
        }
    }
    while(i < na){
        r[k++] = a[i++];
    }
    while(j < nb){
        r[k++] = b[j++];
    }  
}

void mergeSort(int v[], int nv){
    if (nv > 1){
        int meio = nv / 2;
        int esquerda[meio];
        int direita[nv - meio];

        for(int i = 0; i < meio; i++) esquerda[i] = v[i];
        for(int i = 0; i < nv - meio; i++) direita[i] = v[meio + i];

        mergeSort(esquerda, meio);
        mergeSort(direita, nv - meio);
        merge(v, esquerda, meio, direita, nv-meio);
    }
}




int procura (int v[], int n, int e){
    int i = 0;
    int s = n - 1;
    while ( i <= s ){
        int meio = (i + s)/2;
        if ( e == v[meio]) return meio;
        if ( e > v[meio]){
            i = meio + 1;
            
        } else{
            s = meio - 1;
        }
        
    }
    // Se não achou
    return (-1);
}


/*
int delete(int n, LInt *l){
    int i;
    for(i = 0; i < n && *l != NULL; i++){
        // Avança com o ponteiro
        l= &(*l)->prox;
    }
    if (*l == NULL) return 1;

    LInt temp = *l;
    // Avança a lista mexendo no conteúdo
    *l = (*l) -> prox;
    free(temp);
    return 0;
}
*/




int main(){
    int a[] = {44,3677,118,119000};
    int i = procura(a,4,118635);
    printf("%d\n",i);

    return 0;
}


