#include <stdio.h>

float valor(int n){
    if ( n < 12 ){
        return n * 1.3;
    }else{
        return n;
    }
}

void main(){

    int quant;
    scanf("%d",&quant);
    printf("R$ %.2f\n",valor(quant));

}