#include <stdio.h>

void main(){

    int n1, n2, mdc;

    scanf("%d %d", &n1, &n2);
    int c,cont = 1;
    for (c = 1; c <= n1; c ++){
        cont ++; 
        if ((n1 % c == 0) && (n2 % c == 0)){
            mdc = c;
        }  
    }

    printf("mdc(%d, %d): %d \nnumero de iteracoes: %d",n1,n2,mdc,cont);

}