// Joao Vitor Moreira Passos

#include <stdio.h>
#include <string.h>


typedef struct Celular{
    int codigo;
    char descricao[30];
    float preco;
}Celular;


typedef struct Tabela{
    Celular itens[1000];
}Tabela;


void cadastrar()
{
    Tabela t;
    Celular cel;
    FILE *ptr;
    int aux, i;
    if(ptr = fopen("data.txt","r") == NULL)
	{
        ptr = fopen("data.txt","w");
        printf("Codigo descricao preco: ");
        scanf("%d %s %f",&cel.codigo, &cel.descricao, &cel.preco);
        fprintf(ptr,"%d %s %.2f\n",cel.codigo, cel.descricao, cel.preco);
        fclose(ptr);
    }else{
        ptr = fopen("data.txt","r");
        printf("Codigo descricao preco: ");
        scanf("%d %s %f",&cel.codigo, &cel.descricao, &cel.preco);
        i = 0;
        while (!feof(ptr))
        {
            fscanf(ptr,"%d %s %f",&t.itens[i].codigo, &t.itens[i].descricao, &t.itens[i].preco);
            i ++;
        }
        ptr = fopen("data.txt","w");
        int c, repete = 0;
        for (c = 0; c < i; c ++)
        {
            if(cel.codigo == t.itens[c].codigo)
            {
                repete ++;
                break;
            }
        }
        if(repete == 0)
        {
            t.itens[i-1].codigo = cel.codigo;
            strcpy(t.itens[i-1].descricao, cel.descricao);
            t.itens[i-1].preco = cel.preco;
            for (c = 0; c < i; c ++)
            {
                fprintf(ptr, "%d %s %.2f\n", t.itens[c].codigo, t.itens[c].descricao, t.itens[c].preco);
            }
        }else{
            printf("Codigo ja foi cadastrado!\n");
            for (c = 0; c < i-1; c ++)
            {
                fprintf(ptr, "%d %s %.2f\n", t.itens[c].codigo, t.itens[c].descricao, t.itens[c].preco);
            }
        }
        fclose(ptr); 
    }
}


void vizualizar()
{
    Celular t;
    FILE *ptr;
    ptr = fopen("data.txt","r");
    fscanf(ptr,"%d %s %f",&t.codigo, &t.descricao, &t.preco);
    while (!feof(ptr))
    {
        printf("%d, %s, %.2f\n",t.codigo,t.descricao,t.preco);
        fscanf(ptr,"%d %s %f",&t.codigo, &t.descricao, &t.preco);
    }
    fclose(ptr);
    printf("\n");
}


void remover()
{
    FILE *ptr;
    Tabela t;
    if(ptr = fopen("data.txt","r") == NULL)
    {
        printf("Nao foi possivel abrir o arquivo!\n");
    }
    else{
        int i = 0;
        ptr = fopen("data.txt","r+");
        while (!feof(ptr))
        {
            fscanf(ptr,"%d %s %f",&t.itens[i].codigo, t.itens[i].descricao, &t.itens[i].preco);
            i ++;
        }
        int choice;
        printf("Codigo: ");
        scanf("%d",&choice);
        int c;
        for (c = 0; c < i; c ++)
        {
            if(t.itens[c].codigo == choice)
            {
                t.itens[c].codigo = -1;
            }
        }
        ptr = fopen("data.txt","w");
        for (c = 0; c < i - 1; c ++)
        {
            if(t.itens[c].codigo != -1)
            {
                fprintf(ptr,"%d %s %.2f\n",t.itens[c].codigo, t.itens[c].descricao, t.itens[c].preco);
            }
        }
        fclose(ptr);
        printf("\n");
    }
}


void removerMultiplos()
{
    FILE *ptr;
    Tabela t;
    Celular cel;
    int c, i;
    float choice;
    scanf("%f",&choice);
    if (ptr = fopen("data.txt","r") == NULL)
    {
        printf("Nao foi possivel abrir o aquivo.\n");
    }else{
        i = 0;
        ptr = fopen("data.txt","r+");
        while (!feof(ptr))
        {
            fscanf(ptr,"%d %s %f",&t.itens[i].codigo, t.itens[i].descricao, &t.itens[i].preco);
            i ++;
        }
        for (c = 0; c < i; c ++)
        {
            if(t.itens[c].preco < choice)
            {
                t.itens[c].codigo = -1;
            }
        }
        ptr = fopen("data.txt","w");
        for (c = 0; c < i - 1; c ++)
        {
            if(t.itens[c].codigo != -1)
            {
                fprintf(ptr,"%d %s %.2f\n",t.itens[c].codigo, t.itens[c].descricao, t.itens[c].preco);
            }
        }
        fclose(ptr);
        printf("\n");
    }
}


void main()
{
    int choice, cancelar;
    printf("1-cadastrar\n2-visualizar\n3-remover registro\n4-remover multiplos registros\n5-finalizar\n");
    while (1)
    {
        cancelar = 0;
        printf("Informe o modulo desejado: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            cadastrar();
            break;
        case 2:
            vizualizar();
            break;
        case 3:
            remover();
            break;
        case 4:
            removerMultiplos();
            break;
        default:
            if(choice == 5)
            {
                cancelar = 1;
            }
            break;
        }
        if(cancelar == 1)
        {
            break;
        }
    }
}
