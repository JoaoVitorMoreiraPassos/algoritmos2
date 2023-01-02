#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Alunos{
    int chave[30];
    char nome[30];
    char endereco[50];
    char telefone[14];
}Alunos;


void gerarDados(Alunos *v, int n, int ordemChave){
	int i, c;
    if(ordemChave == 0){
        for( i = 0, c = 1; c <= n; c ++,i ++){
            v->chave[c] = c;
        }
    }
    else if (ordemChave == 1){
        srand(time(NULL));
        for ( c = 0; c < n; c ++){
            v->chave[c] = (rand()%10);
        }
    }
    else if (ordemChave == 2){
        for ( i = 0, c = n; c > 0; c --, i ++){
            v->chave[i] = c;
        }
    }
    printf("ordem: %d \n",ordemChave);
    for( c = 0; c < n; c ++){
        printf("%d ",v->chave[c]);
    }
}   

void main(){
    Alunos aluno;
    srand(time(NULL));
    int n= 5, ordem = rand()%3;
    gerarDados(aluno.chave,n,ordem);
}
