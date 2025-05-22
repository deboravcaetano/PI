#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int calcula(char s[]) {
    int stack[1000];
    int sp = 0; 

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (isdigit(c)) {
            stack[sp] = c - '0';
            sp ++;
        } else if (c == '+' || c == '*') {
            int b = stack[--sp];  // segundo operando
            int a = stack[--sp];  // primeiro operando

            if (c == '+') stack[sp++] = a + b;
            else          stack[sp++] = a * b;
        }
    }

    return stack[0];  // resultado final
}



int main(){
    char v[] = "34+21+*";
    int res = calcula(v);
    printf("%d\n",res);
}