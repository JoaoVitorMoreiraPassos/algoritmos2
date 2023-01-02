#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int primeiraJogada(){
    int dado1 = (rand() % 6 ) + 1;
    int dado2 = (rand() % 6 ) + 1;
    printf("Soma dos dados %d + %d = %d\n",dado1,dado2,dado1+dado2);
    if(dado1 + dado2 == 11 || dado1 + dado2 == 7){
        return 1;
    }else if(dado1 + dado2 <= 3 || dado1 + dado2 == 12 ){
        return 0;
    }else{
        return dado1+dado2;
    }
}
int pontos(ponto){
    int dado1 = (rand() % 6) + 1;
    int dado2 = (rand() % 6) + 1;
    printf("Soma dos dados %d + %d = %d\n",dado1,dado2,dado2+dado1);
    if(dado1 + dado2 == 7){
        return 0;
    }else if(dado2 + dado1 == ponto){
        return 1;
    }
}
void main(){
    int resultado,soma = 0;
    srand(time(NULL));
    resultado = primeiraJogada();
    if (resultado == 0){
        printf("O jogador perdeu :(\n");
    }else if(resultado == 1){
        printf("O jogador ganhou :)\n");
    }
    else{
        printf("O ponto e %d\n",resultado);
        while (1){
            soma = pontos(resultado);
            if (soma == 0){
                printf("O jogador perdeu :(\n");
                break;
            }else if(soma == 1){
                printf("O jogador ganhou :)\n");
                break;
            }
        }
    }
}