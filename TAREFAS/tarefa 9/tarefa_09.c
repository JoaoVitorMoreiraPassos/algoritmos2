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
    int tamanho;
} Tabela;


void criarTabela(Tabela *t)
{
    int c, i;
    char gol[] = "Gol";
    srand(time(NULL));
    for (c = 0; c < 1000;c ++){
        t->itens[c].chave = (rand()%1000 + 1);
        for (i = 0; i <= 3; i ++){
            t->itens[c].nome[i] = gol[i];
        }
    }
}


void analiseDesempenho(Tabela t)
{
    int rand_num;
    int c, i;
    int ctrl, soma = 0;
    float media;
    srand(time(NULL));
    for ( c = 0; c < 100; c ++)
    {
        ctrl = 0;
        rand_num = (rand()%1000) + 1;
        for ( i = 0; i < t.tamanho; i ++)
        {
            if(rand_num == t.itens[i].chave)
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
    printf("A media de registros percorridos por pesquisa eh %.1f\n",media);
    // utilizando o metodo de pesquisa sequencial com casos medios o resultado esperado eh aproximadamente 50;
    // os resultados batem;
}


void count(Tabela t)
{
    int n;
    printf("codigo a ser pesquisado: ");
    scanf("%d",&n);
    int c, cont = 0;
    for (c = 0; c < t.tamanho; c ++)
    {
        if (t.itens[c].chave == n)
        {
            cont ++;
        }
    }
    printf("O codigo %d se repete %d vez(es)\n",n,cont);
}


void remover(Tabela *t)
{
    int chave;
    int c, ctrl = 0;
    printf("Insira um chave a ser removida: ");
    scanf("%d",&chave);
    for (c = 0; c < t->tamanho; c ++)
    {
        if(t->itens[c].chave == chave)
        {
            ctrl ++;
            if(ctrl > 1)
            {
                t->itens[c].chave = t->itens[t->tamanho - 1].chave;
                -- t->tamanho;
            }
        }
    }
}


int askName(Tabela t,char nome[])
{
    int c,aux;
    for (c = 0; c < t.tamanho; c ++)
    {
        aux = strcmp(t.itens[c].nome,nome);
        if(aux == 0)
        {
            return t.itens[c].chave;
        }
    }
    return -1;
}


void insert(Tabela *t)
{
    int chave;
    printf("chave a ser inserida: ");
    scanf("%d", &chave);
    char nome[20];
    printf("nome a ser inserido: ");
    scanf(" %[^\n]s", nome);
    int aux = askName(*t, nome);
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
        ++ t->tamanho;
        int i;
        t->itens[t->tamanho - 1].chave = chave;
        for(i = 0; i < 20; i ++)
        {
            t->itens[t->tamanho - 1].nome[i] = '\0';
        }
        for (i = 0; i <= strlen(nome)-1; i ++)
        {
            t->itens[t->tamanho - 1].nome[i] = nome[i];
        }
        printf("insercao completa.\n");
    }
    else
    {
        printf("insercao cancelada.\n");
    }
}


void main()
{
    Tabela tabela;
    tabela.tamanho = 1000;
    int c;
    char nome[20];
    
    criarTabela(&tabela);
    
    analiseDesempenho(tabela);
    
    count(tabela);
    
    remover(&tabela);
    
    printf("nome a ser pesquisado: ");
    scanf(" %[^\n]s",nome);
    if(askName(tabela,nome) != -1){
        printf("A chave para esse veiculo eh: %d\n",askName(tabela,nome));
    }
    else{
        printf("Esse modelo nao esta registrado.\n");
    }
    insert(&tabela);
}