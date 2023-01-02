#include <stdio.h>

int main(){
    int vetor[10];
    int c,i;
    for (c = 0; c < 10; c ++){
        scanf("%d",&vetor[c]);
    }
    printf("%10s %10s %15s\n","Elemento","Valor","Histograma");
    for (c = 0; c < 10; c ++){
        printf("%10d %6d %9c",c,vetor[c],' ');
        for ( i = 0; i < vetor[c]; i ++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}