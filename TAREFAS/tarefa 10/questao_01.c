#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


typedef struct Registro
{
    int chave;
    char nome[20];
} Registro;

typedef struct Tabela
{
    Registro itens[6553];
} Tabela;

void criarTabela(Tabela *t)
{
    int c, i, rand_car;
    char *carros[] = {"Gol","Golf","Uno","Camaro","Jetta","Hilux","Sandero","Siena","Focus","Fox","S10"};
    srand(time(NULL));
    for (c = 0; c < 1000;c ++)
    {
        t->itens[c].chave = (rand()%1000 + 1);
        rand_car = (rand()%11);
        for (i = 0; i <= strlen(carros[rand_car]); i ++)
        {
            t->itens[c].nome[i] = carros[rand_car][i];
        }
    }
}


void salvarDados(Tabela *t, const char *nome)
{
    FILE *arquivo;
    int c;
    if((arquivo = fopen(nome,"w")) == NULL)
    {
        printf("Nao foi possivel acessar o arquivo.\n");
    }
    else
    {
        for(c = 0; c < 1000; c ++)
        {
            fprintf(arquivo," %d %s \n",t->itens[c].chave,t->itens[c].nome);
        }
    }
}


void restaurarDados(Tabela *nt, const char *nome)
{
    int c;
    FILE *ptr;
    if((ptr = fopen(nome,"r")) == NULL)
    {
        printf("Nao foi possivel acessar o arquivo\n");
    }
    else{
        c = 0;
        while (!feof(ptr))
        {
            fscanf(ptr,"%d %s",&nt->itens[c].chave,nt->itens[c].nome);
            c ++;
        }
    }
    fclose(ptr);
}


void main()
{
    Tabela tabela;
    int escolha;
    char nome_arquivo[20];
    printf("Sistema de backup de dados\n");

    printf("Informe a operacao desejada (1-salvar, 2-restaurar):");
    scanf("%d",&escolha);

    printf("Informe o nome do arquivo de backup:");
    scanf("%s",nome_arquivo);

    if(escolha == 1)
    {
        criarTabela(&tabela);
        salvarDados(&tabela, nome_arquivo);
    }
    else
    {   
        Tabela nova_tabela;
        restaurarDados(&nova_tabela, nome_arquivo);
    }
    printf("Operacao concluida com sucesso!\n");
}