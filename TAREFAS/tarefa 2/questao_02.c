#include <stdio.h>

char upper(char letra){
    return letra - 32;
}
int contaString(char nome[20]){
    int t = 0;
    while (nome[t] != '\0'){
        t ++;
    }
    return t;
}

int main(){
    char nome[20];
    int i;
    scanf("%[^\n]s",nome);
    int t = contaString(nome);
    for (i = 0; i < t; i ++){
        if(nome[i] > 96 && nome[i] < 123){
            printf("%c ",upper(nome[i]));
        } 
    }
    return 0;
}