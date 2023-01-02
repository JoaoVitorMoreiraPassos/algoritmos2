#include <stdio.h>


void preencheFibVetor(long long fibVetor[], int tamanho)
{
    int i;
	fibVetor[0] = 0;
	fibVetor[1] = 1;
	for(i = 2; i < tamanho; i ++)
	{
		fibVetor[i] = fibVetor[i -1] + fibVetor[i - 2];
	}
}

void main()
{
    long long fibVetor[64];
    int loop,i,pos;

	preencheFibVetor(fibVetor,64);

    scanf("%d",&loop);
    
    for(i = 0; i < loop; i++)
    {
        scanf("%d",&pos);
		if ( pos == 0)
		{
			printf("Fib(0) = 0\n");
		}
		else
		{
			printf("Fib(%d) = %lld\n",pos,fibVetor[pos]);
		}
        
    }
}
