#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Alunos{

    int chave[65000];
    char nome[30];
    char endereco[50];
    char telefone[14];

}Alunos;


void gerarDados(Alunos v[], int n, int ordemChave,int tipo){
	int i, c;

    if(ordemChave == 0){
        for(i = 0, c = 0; c < n; c ++,i ++){
            v->chave[i] = c;
        }
    }
    else if (ordemChave == 1){
        srand(time(NULL));
        for (c = 0; c < n; c ++){
            v->chave[c] = (rand()%10000);
        }
    }
    else if (ordemChave == 2){
        for (i = 0, c = n-1; c >= 0; c --, i ++){
            v->chave[i] = c;
        }
    }
    switch (tipo)
    {
    case 0:
        printf("bolha\n");
        break;
    case 1:
        printf("selecao\n");
        break;
    case 2:
        printf("insercao\n");
        break;
    default:
        break;
    }

}   


void metodos(Alunos v[], int n, int metodo){
    int c;
    if(metodo == 0){
        int i, j, aux;
        for ( i = 0; i < n -1 ; i++){
            for ( j = 1; j < n - i; j ++ ){
                if (v->chave[j] < v->chave[j-1]){
                    aux = v->chave[j];
                    v->chave[j] = v->chave[j-1];
                    v->chave[j-1] = aux;
                }
            }
        }
    }
    else if(metodo == 1){
        int i, j, min, aux;
        for (i = 0 ; i < n ; i ++){
            min = i;
            for(j = i+1 ; j < n ; j ++){
                if(v->chave[j] < v->chave[min]){
                    min = j;
                }
            }
            aux = v->chave[min];
            v->chave[min] = v->chave[i];
            v->chave[i] = aux;        
        }
    }
    else if(metodo == 2){
        int i, j;
        int aux;
        for (i = 1; i < n; i ++){
            aux = v->chave[i];
            j = i - 1;
            while ((j >= 0) && (aux < v->chave[j]))
            {
                v->chave[j+1] = v->chave[j];
                j --;
            }
            v->chave[j+1] = aux;
        }
    }
}


void main(){

    Alunos aluno;
    int n, cont = 0;
    scanf("%d",&n);
    int aux = n;
    while (1){
        int choices[2];
        int c;
        for(c = 0; c < 2; c ++){
            scanf("%d",&choices[c]);
            if(choices[0] == 3){
                break;
            }
        }
        if(choices[0] == 3){break;}
        gerarDados(&aluno.chave,n,choices[0],choices[1]);

        for(c = 0;c < n; c ++){
            printf("%d ",aluno.chave[c]);
        }
        printf("\n");
        metodos(&aluno.chave,n,choices[1]);
        for(c = 0; c < n; c++){
            printf("%d ",aluno.chave[c]);
        }
        printf("\n");
    }

}
