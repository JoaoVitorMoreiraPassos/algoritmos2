#include <stdio.h>

int main(){
    int vetor[10];
    int c;
    printf("%10s %10s\n","Elemento","Valor");
    for (c = 0; c < 10; c ++){
        vetor[c] = (c+1)*2;
        printf("%10d %6d\n",c,vetor[c]);
    }

    return 0;
}