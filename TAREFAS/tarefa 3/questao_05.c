#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
    srand(time(NULL));
    int numero = (rand() % 1000)+1,chute,chances = 10;
    printf("%d\n",numero);
    while(chances > 0){
        scanf("%d",&chute);
        chances --;
        if(chances > 0){
            if(chute < numero){
                printf("Muito baixo. Tente Novamente!\nChutes restantes: %d\n",chances);
            }else if(chute > numero){
                printf("Muito alto. Tente Novamente!\nChutes restantes: %d\n",chances);
            }else{
                printf("Excelente! Voce adivinhou o numero!\n");
                break;
            }
        }else{
            if(chute == numero){
                printf("Excelente! Voce adivinhou o numero!\n");
            }else{
                printf("Esgotou os chutes.\n");
            }
        }
    }
}