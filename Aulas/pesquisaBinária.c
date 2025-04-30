int search(int x, int a[], int n) {
    int i = 0, f = n-1, m;
    while (i <= f) {
           m = (i+f) / 2;
           if (x==a[m]) return 1;
           if (x>a[m]) i = m+1;
           else f = m-1;
    }
    return 0;
}


int main() {
    int a[10] = {3,6,7,8,10,15,16,21,27,32};
    search(8,a,10);
    return 0;
}