#include <stdio.h>

float desconto(float n){
    if ( n <= 600){
        return n;
    }else if( n > 600 && n <= 1200){
        return (n - (n * 0.2));
    }else if( n > 1200 && n <= 2000){
        return (n - (n * 0.25));
    }else{
        return (n - (n * 0.30));
    }
}

void main(){
    float salario;

    scanf("%f",&salario);
    printf("%.2f\n%.2f\n",salario - desconto(salario),desconto(salario));

}