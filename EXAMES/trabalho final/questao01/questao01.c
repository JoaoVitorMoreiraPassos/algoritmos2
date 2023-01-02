#include <stdio.h>
#include <string.h>

typedef struct Selecao
{
    char nome[20];
    int med[3];
}Selecao;

typedef struct Tabela
{
    Selecao itens[500];
    int tam;
}Tabela;


void seTiverEmpatado(Tabela *tab)
{
    int i, j, temp;
    char ctemp[20]; 
    for (i = 1; i < tab->tam; i ++)
    {
        if((tab->itens[i].med[0] == tab->itens[i-1].med[0] && tab->itens[i].med[1] == tab->itens[i-1].med[1] && tab->itens[i].med[2] == tab->itens[i-1].med[2]) && (strcmp(tab->itens[i].nome, tab->itens[i-1].nome) ==  -1))
        {
            temp = tab->itens[i].med[0];
            tab->itens[i].med[0] = tab->itens[i-1].med[0];
            tab->itens[i-1].med[0] = temp;

            temp = tab->itens[i].med[1];
            tab->itens[i].med[1] = tab->itens[i-1].med[1];
            tab->itens[i-1].med[1] = temp;

            temp = tab->itens[i].med[2];
            tab->itens[i].med[2] = tab->itens[i-1].med[2];
            tab->itens[i-1].med[2] = temp;

            strcpy(ctemp, tab->itens[i].nome);
            strcpy(tab->itens[i].nome, tab->itens[i-1].nome);
            strcpy(tab->itens[i-1].nome,ctemp);
            i -= 2;
        }
    }
}


void ordenacao(Tabela *tabela, int opb)
{
    int i, j, aux,temp;
    char ctemp[20];
    for (i = 1; i < tabela->tam; i ++)
    {
        aux = tabela->itens[i].med[opb];
        j = i - 1;
        while ((j >= 0) && (aux > tabela->itens[j].med[opb]))
        {
            temp = tabela->itens[j+1].med[0];
            tabela->itens[j+1].med[0] = tabela->itens[j].med[0];
            tabela->itens[j].med[0] = temp;
            
            temp = tabela->itens[j+1].med[1];
            tabela->itens[j+1].med[1] = tabela->itens[j].med[1];
            tabela->itens[j].med[1] = temp;

            temp = tabela->itens[j+1].med[2];
            tabela->itens[j+1].med[2] = tabela->itens[j].med[2];
            tabela->itens[j].med[2] = temp;

            strcpy(ctemp, tabela->itens[j+1].nome);
            strcpy(tabela->itens[j+1].nome, tabela->itens[j].nome);
            strcpy(tabela->itens[j].nome,ctemp);
            
            j --;
        }
        tabela->itens[j+1].med[opb] = aux;
    }

}


void main(int argc, char **argv)
{
    Tabela tabela;
    FILE *entrada, *saida;
    char nome_entrada[20], nome_saida[20];
    int i, n;

    strcpy(nome_entrada, argv[1]);
    strcpy(nome_saida, argv[2]);
    entrada = fopen(nome_entrada,"r");
    saida = fopen(nome_saida,"w");
    
    tabela.tam = 0;
    i = 0;
    while (!feof(entrada))
    {
        if(i > 0 && tabela.tam < n)
        {
            fscanf(entrada,"%s %d %d %d",&tabela.itens[tabela.tam].nome, &tabela.itens[tabela.tam].med[0], &tabela.itens[tabela.tam].med[1], &tabela.itens[tabela.tam].med[2]);
            tabela.tam ++;            
        }
        else{
            fscanf(entrada,"%d",&n);
            i ++;
        }
    }
    fclose(entrada);
    ordenacao(&tabela,2);
    ordenacao(&tabela,1);
    ordenacao(&tabela,0);
    seTiverEmpatado(&tabela);
    
    for (i = 0; i < tabela.tam; i ++)
    {
        fprintf(saida,"%s %d %d %d\n",tabela.itens[i].nome, tabela.itens[i].med[0], tabela.itens[i].med[1], tabela.itens[i].med[2]);
    }
    fclose(saida);
    printf("deu certo\n");
}   