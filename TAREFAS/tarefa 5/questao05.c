#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Carta
{
    char naipe[10];
	char face[10];
} Carta;


void preenche(Carta *deck, char *face[], char *naipe[] )
{
    int c,i,j = 0,cont = 0;
    for(i = 0; i <= 52; i ++)
    {
        for(c = 0; c < len(face[cont]); c ++)
        {
            deck[i].face[c] = face[cont][c];
        }
        deck[i].face[len(face[cont])] = '\0';
        for(c = 0; c < len(naipe[j]); c ++)
        {
            deck[i].naipe[c] = naipe[j][c];
        }
        deck[i].naipe[len(naipe[j])] = '\0';
        if (cont == 12)
        {
            cont = -1;
            j ++;
            if(j == 4)
            {
                break;
            }
        }
        cont ++;
    }
}


void embaralha(Carta *deck)
{
    char face_temp[10],naipe_temp[10];
    int c,i,f,pos1,pos2;
    srand(time(NULL));
    for (c = 0; c < 100; c ++)
    {
        pos1= rand()%52;
        pos2= rand()%52;
        // troca as strings de posicao;
        for(i = 0; i < len(deck[pos1].face); i ++)
        {
            face_temp[i] = deck[pos1].face[i];
        }
        face_temp[len(deck[pos1].face)] = '\0';
        for(i = 0; i < len(deck[pos1].naipe); i ++)
        {
            naipe_temp[i] = deck[pos1].naipe[i];
        }
        naipe_temp[len(deck[pos1].naipe)] = '\0';

        for(i = 0; i < len(deck[pos2].face); i ++)
        {
            deck[pos1].face[i] = deck[pos2].face[i];
        }
        deck[pos1].face[len(deck[pos2].face)] = '\0';
        for(i = 0; i < len(deck[pos2].naipe); i ++)
        {
            deck[pos1].naipe[i] = deck[pos2].naipe[i];
        }
        deck[pos1].naipe[len(deck[pos2].naipe)] = '\0';

        for(i = 0; i < len(face_temp); i ++)
        {
            deck[pos2].face[i] = face_temp[i];
        }
        deck[pos2].face[len(face_temp)] = '\0';
        for(i = 0; i < len(naipe_temp); i ++)
        {
            deck[pos2].naipe[i] = naipe_temp[i];
        }
        deck[pos2].naipe[len(naipe_temp)] = '\0';
    }
}


void imprime(Carta *deck)
{
    int c;
    for ( c = 0; c < 52; c ++ )
    {
        printf("%s de %s\n",deck[c].face,deck[c].naipe);
    }
}


int len(char vetor[]){
    // retorna um inteiro que representa o tamanho da string;
    int t = 0;
    while (vetor[t] != 0)
    {
        t ++;
    }
    return t;
}


void main()
{
    Carta deck[52];
    char *faces[] = {"As", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"};
	char *naipes[] = {"Paus", "Ouro", "Copas", "Espadas"};	
    int n;
    scanf("%d",&n);

    preenche(&deck,faces,naipes);
    
    if( n == 1)
    {	
        imprime(&deck);
    }
    else
    {
        embaralha(&deck);
        imprime(&deck);
    }
}
