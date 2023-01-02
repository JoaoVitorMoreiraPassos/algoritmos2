#include <stdio.h>
#include <string.h>


typedef struct Numeros
{
    int pares[100000];
    int impares[100000];
    int tam_pares;
    int tam_impares;
}Numeros;

void ordenaVetores(int *vetor, int tam);
void importaValores(const char *nome, Numeros *nums);
void exportaValores(const char *nome, Numeros nums);

int main(int argc, char **argv)
{
    int i;
    int num_comp = 0, num_mov = 0;
    char nome_arquivo_entrada[20];
    char nome_arquivo_saida[20];
    
    strcpy(nome_arquivo_entrada,argv[1]);
    strcpy(nome_arquivo_saida,argv[2]);
    
    Numeros nums;
    nums.tam_impares = 0;
    nums.tam_pares = 0;   
    importaValores(nome_arquivo_entrada,&nums);

    ordenaVetores(nums.pares, nums.tam_pares);
    ordenaVetores(nums.impares, nums.tam_impares);
    
    exportaValores(nome_arquivo_saida,nums);
 
    return 0;
}


void ordenaVetores(int *vetor, int tam)
{
    // método de ordenação por inserção
    int i, j, aux;
    for (i = 1; i < tam; i ++){
        aux = vetor[i];
        j = i - 1;
        while ((j >= 0) && (aux < vetor[j]))
        {
            vetor[j+1] = vetor[j];
            j --;
        }
        vetor[j+1] = aux;
    }
}


void importaValores(const char *nome, Numeros *nums)
{
    FILE *arquivo;
    arquivo = fopen(nome, "r");
    int i, temp;
    i = 0;
    nums->tam_impares = 0;
    nums->tam_pares = 0;
    while (!feof(arquivo))
    {
        fscanf(arquivo," %d ",&temp);
        if(i > 0)
        {
            if(temp % 2 == 0)
            {
                nums->pares[nums->tam_pares] = temp;
                nums->tam_pares ++;
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
}


void exportaValores(const char *nome, Numeros nums)
{
    FILE *arquivo;
    int i;
    arquivo = fopen(nome,"w");
    // imprime os valores pares em ordem crescente;
    for (i = 0; i < nums.tam_pares; i ++)
    {
        fprintf(arquivo,"%d\n",nums.pares[i]);
    }
    // imprime os valores impares em ordem decrescente;
    for (i = nums.tam_impares-1; i >= 0; i --)
    {
        fprintf(arquivo,"%d\n",nums.impares[i]);
    }

    fclose(arquivo);
}