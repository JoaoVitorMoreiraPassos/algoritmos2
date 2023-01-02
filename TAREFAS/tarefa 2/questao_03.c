#include <stdio.h>

char cebolador(char letra){
    if (letra == 'R'){
        return 'L';
    }
    else{
        return 'l';
    }
}
int contaString(char nome[20]){
    int t = 0;
    while (nome[t] != '\0'){
        t ++;
    }
    return t;
}

int main(){

    char palavra[20];
    int i,cont_trocas[20],k = 0,c = 0;
    printf("informe uma palavra: ");
    scanf("%[^\n]s",&palavra);
    int t = contaString(palavra);
    char cebolinha[t];
    for (i = 0; i < t; i ++){
        if(palavra[i] == 'R' || palavra[i] == 'r'){
            c ++;
            cont_trocas[k] = i+1;
            cebolinha[i] = cebolador(palavra[i]); 
            k ++;
        }else{
            cebolinha[i] = palavra[i];
        }
    }
    cebolinha[t] = '\0';
    printf("Cebolinha falaria: %s\n",cebolinha);
    printf("Houve troca nos caracteres: ");
    for (i = 0; i < c; i ++){
        if(i != (c - 1)){
            printf("%d, ",cont_trocas[i]);
        }else{
            printf("%d",cont_trocas[i]);
        }
    }
    return 0;
}