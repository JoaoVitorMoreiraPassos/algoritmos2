#include <stdio.h>

void main(){
    int x, y;

    scanf("%d %d", &x, &y);
    int c,soma = 0,produto = 1;

    for ( c = x; c <= y; c ++){
        if ( c % 2 == 0){
            soma += c;
        }else{
            produto *= c;
        }
    }

    printf("%d\n%d",soma,produto);

}