#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int arremesso(){
    return (rand()%2);
}

void main(){
    int cara_coroa,cont_cara = 0,c;
    srand(time(NULL));
    for (c = 0; c < 100; c ++){
        cara_coroa = arremesso();
        if(cara_coroa == 1){
            printf("cara\n");
            cont_cara ++;
        }else{
            printf("coroa\n");
        }
    }
    printf("caiu cara %d vezes\n",cont_cara);
}