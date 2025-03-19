#include <stdio.h>

int ordenado(int v[], int N) {
    int i;
    for (i = 0; i < N - 1; i++) {
        if (v[i] > v[i + 1]) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {5, 3, 4, 2, 1};

    printf("Array 1 está ordenado? %d\n", ordenado(arr1, 5)); // Saída: 1
    printf("Array 2 está ordenado? %d\n", ordenado(arr2, 5)); // Saída: 0

    return 0;
}