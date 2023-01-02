#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
int tam = 0;

typedef struct{
	int codigo;
	char descricao[30];
	float preco;
}Celular;

typedef struct{
	Celular cel[MAX];
}Gerencia;


void cadastrarCelular();
void visualizarTab();
void removerUm();
void removerVarios();

void main(){//>>Dayan Ramos
	setlocale(LC_ALL, "Portuguese");
	
	Celular cel[MAX];
	int x;
	printf("1-Cadastrar\n2-Visualizar\n3-Remover Registro\n");
	printf("4-Remover Múltiplos Registros\n5-Finalizar");
	
	x=0;
	while(x != 5){
		printf("\nInforme o módulo desejado: ");
		scanf("%d", &x);
	
		if(x == 1){
			cadastrarCelular();
		}
		else if(x == 2){
			visualizarTab();
		}
		else if(x == 3){
			removerUm();
		}
		else if(x == 4){
			removerVarios();
		}
	}	
}

void cadastrarCelular(){
	FILE *salvar;
	Gerencia tab;
	Celular c;
	
	printf("Informe o codigo, descrição e preço: ");
	if((salvar = fopen("celular.txt","r")) == NULL){
        salvar = fopen("celular.txt","w");
        scanf("%d %s %f",&c.codigo, &c.descricao, &c.preco);
        fprintf(salvar,"%d %s %.2f\n",c.codigo, c.descricao, c.preco);
        fclose(salvar);
    }
	else{
		int i = 0;
    	salvar = fopen("celular.txt", "r");
    	scanf("%d%s%f", &c.codigo, &c.descricao, &c.preco);
    	
    	while( !feof(salvar) ){
    		fscanf(salvar, "%d%s%f", &tab.cel[i].codigo, tab.cel[i].descricao, &tab.cel[i].preco);
			i += 1;
		}
		int x, aux = 0;
		salvar = fopen("celular.txt", "w");
		for(x = 0; x < i; x++){
			if(c.codigo == tab.cel[x].codigo){
				aux += -1;
				break;
			}
		}
		if(aux == 0){
			tab.cel[i-1].codigo = c.codigo;
			strcpy(tab.cel[i-1].descricao, c.descricao);
			tab.cel[i-1].preco = c.preco;
			x = 0;
			while(x < i){
				fprintf(salvar, "%d %s %.2f\n", tab.cel[x].codigo, tab.cel[x].descricao, tab.cel[x].preco);
				x += 1;
			}
		}
		else{
			printf("\nCódigo já Cadastrado.");
			x = 0;
			while(x < i-1){
				fprintf(salvar, "%d %s %.2f\n", tab.cel[x].codigo, tab.cel[x].descricao, tab.cel[x].preco);
				x += 1;
			}
		}
		fclose(salvar);
	}
}

void visualizarTab(){
	FILE *vis;
	Celular c;
    vis = fopen( "celular.txt", "r" );
    
    if((vis = fopen( "celular.txt", "r" )) == NULL){
        printf( "File could not be opened\n" );
    }
    else{
        printf( "\nCódigo - Descrição - Valor\n");
        fscanf( vis, "%d%s%f", &c.codigo, &c.descricao, &c.preco);
        while ( !feof(vis) ){
            printf( "%d, %s, %.2f\n", c.codigo, c.descricao, c.preco);
            fscanf( vis, "%d%s%f", &c.codigo, &c.descricao, &c.preco);
//            i += 1;
        }
        fclose(vis); 
    }
}

void removerUm(){
	FILE *remove;
	Gerencia c;
	remove = fopen("celular.txt", "r");
	
	if(remove == NULL){
		printf("Erro ao abrir!");
	}
	else{
		remove = fopen("celular.txt", "r+");
		int i = 0;
		while( !feof(remove) ){
			fscanf(remove, "%d%s%f", &c.cel[i].codigo, c.cel[i].descricao, &c.cel[i].preco);
			i += 1;
		}
		int cod;
		printf("Código: ");
		scanf("%d", &cod);
		int x;
		for(x = 0; x < i; x++){
			if(c.cel[x].codigo == cod){
				c.cel[x].codigo = -1;
			}
		}
		remove = fopen("celular.txt", "w");
		for(x = 0; x < i-1; x++){
			if(c.cel[x].codigo != -1){
				fprintf(remove, "%d %s %.2f\n", c.cel[x].codigo, c.cel[x].descricao, c.cel[x].preco);
			}
		}
		fclose(remove);
	}
}

void removerVarios(){
	FILE *remove;
    Gerencia tab;
    Celular c;
	remove = fopen("celular.txt","r");
    if(remove == NULL){
        printf("Nao foi possivel abrir o aquivo.\n");
    }else{
        remove = fopen("celular.txt","r+");
        int i = 0;
        while( !feof(remove) ){
            fscanf(remove,"%d %s %f",&tab.cel[i].codigo, tab.cel[i].descricao, &tab.cel[i].preco);
            i += 1;
        }
        float valor;
        int x, aux;
        printf("Valor: ");
        scanf("%f",&valor);
        for (x = 0; x < i; x++){
            if(tab.cel[x].preco < valor){
            	tab.cel[x].preco = -1.0;
            	}
        	}

    	int y;
        remove = fopen("celular.txt", "w");
        for (y = 0; y < i - 1; y++){
        	if(tab.cel[y].preco != -1.0){
            	fprintf(remove,"%d %s %.2f\n",tab.cel[y].codigo, tab.cel[y].descricao, tab.cel[y].preco);
            }
        }
        fclose(remove);
	}
}