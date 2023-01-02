#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>



void main(){//>>Dayan Ramos
	setlocale(LC_ALL, "Portuguese");
	srand((unsigned)time(NULL));
	int i, aux;
	
	for(i = 0; i < 5000; i++){
		aux = (rand() % 8999) + 1000;
		printf("%d\n",aux);
	}
}