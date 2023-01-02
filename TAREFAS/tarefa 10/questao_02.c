#include <stdio.h>


typedef struct Registro
{
    int codigo;
    char nome[20];
    float valor;
}Registro;


void Formatacao()
{
    Registro infos = {0, "", 0.0};
    FILE *ptr;
    int c;
    
    if((ptr = fopen("data.bin","wb")) == NULL)
    {
        printf("Nao foi possivel abrir o arquivo.\n");
    }
    else{
        for (c = 0; c < 1000; c ++)
        {
            fwrite(&infos, sizeof(Registro), 1, ptr);
        }
    }
    fclose(ptr);
}


void Escrita()
{
    Registro infos;
    FILE *ptr;
    
    if((ptr = fopen("data.bin","rb+")) == NULL)
    {
        printf("Nao foi possivel acessar o arquivo.\n");
    }
    else
    {
        while (1)
        {
            printf("=-=-=-Novo veiculo-=-=-=\n");
            printf("codigo de locacao: ");
            scanf("%d",&infos.codigo);
            if(infos.codigo == 0)
            {   printf("=-=-=-=Encerrado-=-=-=-=\n");break;}
            printf("nome do veiculo: ");
            scanf("%[^\n]s",infos.nome);
            printf("valor da locacao: ");
            scanf("%f",&infos.valor);
            fseek(ptr,(infos.codigo-1) * sizeof(Registro), SEEK_SET);
            fwrite(&infos,sizeof(Registro), 1, ptr);
            printf("=-=-=-=-=-=-=-=-=-=-=-=-\n");
        }
        fclose(ptr);
    }    
}


void Leitura()
{
    Registro infos;
    FILE *ptr;

    if((ptr = fopen("data.bin","rb")) == NULL)
    {
        printf("Nao foi possivel acessar o arquivo.\n");
    }
    else
    {
        printf("%-6s%-16s%-11s\n","Cod","Nome","Valor");
        while (!feof(ptr))
        {
            fread(&infos, sizeof(Registro), 1, ptr);
            if(infos.codigo != 0)
            {
                printf("%-6d%-16sR$ %-12.2f\n",
                infos.codigo,
                infos.nome,
                infos.valor
                );
            }
            
        }
        fclose(ptr);
    }
}


void Busca()
{
    Registro infos;
    FILE *ptr;
    int cod_user;

    if( (ptr = fopen("data.bin","rb")) == NULL)
    {
        printf("Nao foi possivel acessar o arquivo.\n");
    }
    else
    {
        printf("insira um codigo: ");
        scanf("%d",&cod_user);

        fseek(ptr,(cod_user-1) * sizeof(Registro), SEEK_SET);
        fread(&infos,sizeof(Registro),1,ptr);
        printf("%-6s%-16s%-11s\n","Cod","Nome","Valor");
        printf("%-6d%-16sR$ %-12.2f\n",
                                        infos.codigo,
                                        infos.nome,
                                        infos.valor
              );
    }
    fclose(ptr);
}


void main()
{
    int choice,cancel;
    printf("Sistema de locacao baseado em arquivo\n");
    while (1)
    {   
        cancel = 0;
        printf("Informe a opcao desejada (1-formatar, 2-escrever, 3-ler, 4-buscar, 0-finalizar):\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            Formatacao();
            break;
        case 2:
            Escrita();
            break;
        case 3:
            Leitura();
            break;
        case 4:
            Busca();
            break;
        default:
            if(choice == 0)
            {cancel = 1;}
            else{printf("Valor invalido\n");}
            break;
        }
        if(cancel == 1){break;}
    }
}