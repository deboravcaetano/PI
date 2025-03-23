#include <stdio.h>

int cardinalMSet (int N, int v[N]) {
    int i, len = 0;
    for(i = 0; i < N; i++) len += v[i];
    return len;
}

int main(){
    int i;
    int v[8] = {0, 2, 0, 0, 1, 0, 0, 3};
    int cardinal= cardinalMSet(8,v);
    printf("O número de elementos do conjunto é:%d\n",cardinal);
    return 0;

    
}
