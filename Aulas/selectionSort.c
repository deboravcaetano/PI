/*
explicação:

O array é dividido em duas partes: a parte ordenada e a parte não ordenada. 
Inicialmente, a parte ordenada está vazia e a parte não ordenada contém todos os elementos.

O algoritmo percorre a parte não ordenada do array para encontrar o menor elemento.

O menor elemento encontrado é trocado com o primeiro elemento da parte não ordenada, movendo-o para a parte ordenada.

O processo é repetido para a parte não ordenada, até que todos os elementos estejam ordenados.

*/


void swap(int a[], int i, int j) {
     int aux = a[i];
     a[i] = a[j];
     a[j] = aux;
}

void ssort(int a[], int n) {
     int i, j, m;
     for (i = 0; i < n; i++) {
        m = i;
        for (j = i; j < n; j++)
         if (a[j] < a[m]) m = j;
        swap(a, i, m);
    }
}