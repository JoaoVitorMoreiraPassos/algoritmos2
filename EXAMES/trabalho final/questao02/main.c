#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void ordena(char nomes[20][20], int tam)
{
    int i, j, aux;
    char temp[20],caux[20];
    for (i = 1; i < tam; i ++)
    {
        strcpy(caux,nomes[i]);
        j = i - 1;
        while(j >= 0 && (strcmp(caux, nomes[j])) == -1)
        {
            strcpy(temp, nomes[j+1]);
            strcpy(nomes[j+1], nomes[j]);
            strcpy(nomes[j], temp);
            j --;
        }
        strcpy(nomes[j+1],caux);
    }
}


void main()
{
    char nomes[20][20];
    FILE *entrada, *saida;
    
    int i,n, k;
    i = 0;
    n = -1;
    entrada = fopen("entrada.txt","r");
    while(!feof(entrada))
    {
        if(n != -1 && i < n)
        {
            fscanf(entrada,"%s",nomes[i]);
            i ++;
        }
        else{
            fscanf(entrada,"%d %d", &n, &k);
        }
    }    
    fclose(entrada);

    ordena(nomes,n);

    saida = fopen("saida.txt","w");
    fprintf(saida,"%s\n",nomes[k-1]);
    fclose(saida);
}