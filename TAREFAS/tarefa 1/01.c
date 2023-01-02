#include <stdio.h>

float reajuste(float n){
    if (n < 20){
        return (n + (n * 0.45));
    }else{
        return (n + (n * 0.3));
    }
}

void main(){
    
    float preco;

    scanf("%f",&preco);
    printf("%.2f\n",reajuste(preco));

}