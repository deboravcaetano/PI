#include <stdio.h>

void swap(int a[], int i, int j) {
     int aux = a[i];
     a[i] = a[j];
     a[j] = aux;
}

void bubble(in v[], int N){
    int i;
    for(i=0; i < N-1 ;i++){
        if(v[i]>v[i+1]){
            swap(v,i,i+1);
        }
    }
}

void bsort(int a[], int n) {
     int i;
     for (i = n; i > 0; i--)
     bubble(a, i);
}

// 