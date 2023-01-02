#include <stdio.h>

int contaString(char nome[20]){
    int t = 0;
    while (nome[t] != '\0'){
        t ++;
    }
    return t;
}

int main(){
    char nome[5][20];
    char nome_maior_altura[20], nome_maior_ira[20],nome_maior_peso[20];
    float api[5][3],soma_altura = 0,media_altura,maior_altura,menor_altura;
    float soma_peso = 0, media_peso, maior_peso, menor_peso;
    float soma_ira = 0, media_ira, maior_ira, menor_ira;
    int i,j;

    for (i = 0; i < 5; i ++){
        scanf("%s",&nome[i]);
        for (j = 0; j < 3; j ++){
            scanf("%f",&api[i][j]);

        } 
    }
    int t = contaString(nome[0]);
    for (i = 0; i < t; i ++){
        nome_maior_altura[i] = nome[0][i];
        nome_maior_peso[i] = nome[0][i];
        nome_maior_ira[i] = nome[0][i];
    }
    for (i = 20; i >= t; i --){
        nome_maior_altura[i] = '\0';
        nome_maior_peso[i] = '\0';
        nome_maior_ira[i] = '\0';
    }
    maior_altura = api[0][0];
    menor_altura = api[0][0];
    maior_peso = api[0][1];
    menor_peso = api[0][1];
    maior_ira = api[0][2];
    menor_ira = api[0][3];
    for(i = 0; i < 5; i ++){
        soma_altura += api[i][0];
        soma_peso += api[i][1];
        soma_ira += api[i][2];
        int t = contaString(nome[i]);
        if(api[i][0] > maior_altura){
            for (j = 0; j < t; j ++){
                nome_maior_altura[j] = nome[i][j];
            }
            maior_altura = api[i][0];
        }
        if(api[i][0] < menor_altura){
            menor_altura = api[i][0];
        }

        if(api[i][1] > maior_peso){
            for (j = 0; j < t; j ++){
                nome_maior_peso[j] = nome[i][j];
            }
            maior_peso = api[i][1];
        }
        if(api[i][1] < menor_peso){
            menor_peso = api[i][1];
        }

        if(api[i][2] > maior_ira){
            for (j = 0; j < t; j ++){
                nome_maior_ira[j] = nome[i][j];
            }
            maior_ira = api[i][2];
        }
        if(api[i][2] < menor_ira){
            menor_ira = api[i][2];
        }
    }
    
    printf("-------------------------------------------\naltura:\n");
    printf("media: %.2f | maior: %.2f | menor: %.2f\n-------------------------------------------\n",(soma_altura/5),maior_altura,menor_altura);
    printf("-------------------------------------------\npeso:\n");
    printf("media: %.2f | maior: %.2f | menor: %.2f\n-------------------------------------------\n",(soma_peso / 5),maior_peso,menor_peso);
    printf("-------------------------------------------\nIRA:\n");
    printf("media: %.2f | maior: %.2f | menor: %.2f\n-------------------------------------------\n",(soma_ira/5),maior_ira,menor_ira);

    printf("\n");
    printf("maior altura: %s\n",nome_maior_altura);
    printf("maior peso: %s\n", nome_maior_peso);
    printf("maior IRA: %s\n",nome_maior_ira);
    
    return 0;
}