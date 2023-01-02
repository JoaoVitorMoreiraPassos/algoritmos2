#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

const max = 65536;

typedef struct Carro
{
    int chave;
    char nome[20];
} Carro;


void criarTabela(Carro carro[], int *t)
{
    int c,i;
    char gol[] = "Gol";
    srand(time(NULL));
    for (c = 0; c < *t; c ++)
    {
        carro[c].chave = (rand()%1000)+ 1;
        for(i = 0; i < 3; i ++)
        {
            carro[c].nome[i] = gol[i];
        }
    }
}


void analiseDesempenho(Carro carro[],int *t)
{
    int rand_num;
    int c, i;
    int ctrl;
    int valores[101], soma = 0;
    float media;
    srand(time(NULL));
    for ( c = 0; c < 100; c ++)
    {
        ctrl = 0;
        rand_num = (rand()%1000) + 1;
        for ( i = 0; i < *t; i ++)
        {
            if(rand_num == carro[i].chave)
            {
                ctrl = 1;
            }
            if(ctrl == 1)
            {
                break;
            }
        }
        soma += (i+1);
    }
    media = soma / 100;
    printf("A media de registros percorridos por pesquisa eh %.2ff\n",media);
    // utilizando o metodo de pesquisa sequencial com casos medios o resultado esperado eh aproximadamente 50;
    // os resultados batem;
}


void count(Carro carro[],int chave,int *t)
{
    int c, cont = 0;
    for (c = 0; c < *t; c ++)
    {
        if (carro[c].chave == chave)
        {
            cont ++;
        }
    }
    printf("O codigo %d se repete %d vez(es)\n",chave,cont);
}


void remover(Carro carro[], int *t)
{
    int chave;
    int c, ctrl = 0;
    printf("Insira um chave: ");
    scanf("%d",&chave);
    for (c = 0; c < 1000; c ++)
    {
        if(carro[c].chave == chave)
        {
            ctrl ++;
            if(ctrl > 1)
            {
                carro[c].chave = carro[*t-1].chave;
                -- *t ;
            }
        }
    }
    count(carro,chave, &*t);
}


int askName(Carro carro[],char nome[], int *t)
{
    int c,aux;
    for (c = 0; c < *t; c ++)
    {
        aux = strcmp(carro[c].nome,nome);
        if(aux == 0)
        {
            return carro[c].chave;
        }
    }
    return -1;
}


void insert(Carro carro[], int *t)
{
    int chave;
    printf("chave a ser inserida: ");
    scanf("%d", &chave);
    char nome[20];
    printf("nome a ser inserido: ");
    scanf(" %s", &nome);
    int aux = askName(carro, nome, &*t);
    int simounao;
    if( aux == -1 )
    {
        printf("Nao existem registros desse veiculo. Digite 0 para cancelar e 1 para confirmar a insercao: ");
    }
    else
    {
        printf("Existem registros desse veiculo Digite 0 para cancelar e 1 para confirmar a insercao: ");
    }
    scanf("%d", &simounao);
    if( simounao == 1 )
    {
        ++ *t;
        int i;
        carro[*t - 1].chave = chave;
        for(i = 0; i < 20; i ++)
        {
            carro[*t - 1].nome[i] = '\0';
        }
        for (i = 0; i <= strlen(nome)-1; i ++)
        {
            carro[*t - 1].nome[i] = nome[i];
        }
    }
    else
    {
        printf("insercao cancelada");
    }

}


void main()
{
    const tamanho = 65000;
    int t = 1000;
    Carro carro[tamanho];
    int key_choiced;
    char nome[20];
    criarTabela(carro,&t);
    analiseDesempenho(carro, &t);
    printf("Insira uma chave: ");
    scanf("%d",&key_choiced);
    count(carro,key_choiced,&t);
    remover(carro,&t);
    
    printf("Insira um nome: ");
    scanf("%s",&nome);
    if(askName(carro, nome, &t) != -1)
    {
        printf("Já existe um modelo com esse nome sua chave eh: %d\n",askName(carro, nome, &t));
    }
    else
    {
        printf("Esse modelo ainda nao foi registrada.\n");
    }
    insert(carro,&t);

}