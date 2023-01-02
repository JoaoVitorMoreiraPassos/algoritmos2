#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Numeros
{
    int pares[100000];
    int impares[100000];
    int tam_pares;
    int tam_impares;
}Numeros;

gerarTabela( int num_com, int num_mov,char *tipo){

    printf("%8s | %6d | %5d\n",tipo,num_com,num_mov);
 
}

void importaValores(const char *nome, Numeros *nums)
{
    FILE *arquivo;
    arquivo = fopen(nome, "r");
    int i, temp;
    i = 0;
    nums->tam_impares = 0;
    nums->tam_pares = 0;
    printf("Extraindo dados...\n");
    while (!feof(arquivo))
    {
        fscanf(arquivo," %d ",&temp);
        if(i > 0)
        {
            if(temp % 2 == 0)
            {
                nums->pares[nums->tam_pares] = temp;
                nums->tam_pares = nums->tam_pares + 1;
            }
            else if(temp % 2 != 0)
            {
                nums->impares[nums->tam_impares] = temp;
                nums->tam_impares ++;
            }
        }
        else{
            i ++;
        }
    }
    fclose(arquivo);
    printf("Dados extraidos...\n");
}


void metodos(int v[], int n,int *num_comp, int *num_mov,int ordem){
    int c;
    char tipo[15];
    if(ordem == 0){
        printf("melhor caso: %d\n----------------------------\n",n);
    }else if(ordem == 1){
        printf("medio caso:  %d\n-----------------------------\n",n);
    }else{
        printf("pior caso:  %d\n------------------------------\n",n);
    }
        printf("%8s |%6s|%5s\n----------------------------\n","metodo","num comp","num mov");

    // bolha
    int i, j, aux;
    for ( i = 0; i < n -1 ; i++){
        for ( j = 1; j < n - i; j ++ ){
            ++ *num_comp;
            if (v[j] < v[j-1]){
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
                *num_mov += 3;
            }
        }
    }
    gerarTabela(*num_comp,*num_mov,"bolha");
    // seleção
    *num_comp = 0;
    *num_mov = 0;
    int min;
    for (i = 0 ; i < n ; i ++){
        min = i;
        for(j = i+1 ; j < n ; j ++){
            *num_comp = *num_comp + 1;
            if(v[j] < v[min]){
                min = j;
            }
        }
        aux = v[min];
        v[min] = v[i];
        v[i] = aux;    
        *num_mov += 3;
    }
    gerarTabela(*num_comp,*num_mov,"selecao");
    // inserção
    *num_comp = 0;
    *num_mov = 0;
    for (i = 1; i < n; i ++){
        ++ *num_mov;
        aux = v[i];
        j = i - 1;
        ++ *num_comp;
        while ((j >= 0) && (aux < v[j]))
        {
            ++ *num_comp;
            v[j+1] = v[j];
            ++ *num_mov;
            j --;
        }
        ++ *num_mov;
        v[j+1] = aux;
    }
    gerarTabela(*num_comp,*num_mov,"insercao");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}


void main(){
    Numeros nums;
    int num_comp, num_mov;
    importaValores("entrada.txt",&nums);
    metodos(nums.pares,nums.tam_pares,&num_comp, &num_mov, 1);
    metodos(nums.impares, nums.tam_impares, &num_comp, &num_mov, 1);
    FILE *saida = fopen("saida.txt","w");
    for(int i = 0; i < nums.tam_pares; i ++){
        fprintf(saida,"%d\n",nums.pares[i]);
    }
    for (int i = nums.tam_impares -1 ; i >= 0; i --){
        fprintf(saida,"%d\n",nums.impares[i]);
    }
}
