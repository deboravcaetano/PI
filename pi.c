
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
        for(int i = 0; i < nv - meio; i++) direita[i] = v[meio + 1];

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





