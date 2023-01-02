#include <stdio.h>

long int contaNum(long int array[105]){
    int t = 0;
    while (array[t] != 'a'){
        t ++;
    }
    return t;
}

int main(){
    int d,c,i;
    long long int n;
    while(1){
        scanf("%d %lld",&d,&n);
        if(d == 0 && n == 0){
            break;
        }
        long int numero[105];
        int cont = 0;

        while (n > 0){
        	if(n%10 != d){
            	numero[cont] = n % 10;
            	cont ++;
        	}
            n = n / 10;
            
        };
        for(c = 105; c >= cont; c -- ){
            numero[c] = 'a';
        }
        
        int tam = contaNum(numero);
        int rever[tam];
        cont = 0;
        for (c = tam-1; c >= 0; c --){
            rever[cont] = numero[c];
            cont ++;
        }
        int soma = 0;
        for (c = 0; c < tam;c ++){
        	soma += rever[c];
		}
		if(soma == 0 || cont == 0){
			printf("0\n");
		}else{
	        for (c = 0; c < tam; c ++){
	        	printf("%d",rever[c]);
			}
			printf("\n");
		}
    }


    return 0;
}
