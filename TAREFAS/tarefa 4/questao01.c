#include <stdio.h>

int maiorOuNao(float atual, float concorrente,int indice_atual, int indice_concorrente){

    if(concorrente > atual){
        return indice_concorrente;
    }
    else{
        return indice_atual;
    }

}

struct Aluno{

    char nome[20];
    float altura, peso, ira;

};


void main(){

    struct Aluno dados[5];
    
    int i,indice_maior_peso = 0,indice_maior_altura = 0,indice_maior_ira = 0;
    float maior_peso = 0,maior_altura = 0, maior_ira = 0;
    float soma_peso = 0, soma_altura = 0, soma_ira = 0;

    for ( i = 0; i < 5; i ++){
        scanf("%s %f %f %f", &dados[i].nome, &dados[i].altura, &dados[i].peso,&dados[i].ira);

        soma_peso += dados[i].peso;
        soma_altura += dados[i].altura;
        soma_ira += dados[i].ira;
        
        indice_maior_peso = maiorOuNao( maior_peso,  dados[i].peso,  indice_maior_peso,  i );
        maior_peso = dados[indice_maior_peso].peso;

        indice_maior_altura = maiorOuNao( maior_altura,  dados[i].altura,  indice_maior_altura,  i );
        maior_altura = dados[indice_maior_altura].altura;

        indice_maior_ira = maiorOuNao( maior_ira,  dados[i].ira,  indice_maior_ira,  i );    
        maior_ira = dados[indice_maior_ira].ira;    
    }
    
    printf("Media de peso: %.3f\nMedia de Altura: %.3f\nMedia de IRA: %.3f\n",soma_peso/5,soma_altura/5,soma_ira/5);
    printf("\n");
    printf("Maior peso: %s (%.3f)\nMaior altura: %s (%.3f)\nMaior IRA: %s (%.3f)\n",  dados[indice_maior_peso].nome,  dados[indice_maior_peso].peso,  dados[indice_maior_altura].nome,  dados[indice_maior_altura].altura,  dados[indice_maior_ira].nome,  dados[indice_maior_ira].ira);
    printf("\n");


}