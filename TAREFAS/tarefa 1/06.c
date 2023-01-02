#include <stdio.h>

void main(){

    int n,soma = 0;
    
    while ( 1 ){
        scanf("%d",&n);
        if (n < 0){
            break;
        }
        soma += n;
    }

    printf("%d",soma);

}