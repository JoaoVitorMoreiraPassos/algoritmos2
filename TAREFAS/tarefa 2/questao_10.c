#include <stdio.h>

int main(){
    int partidas[30];
    char times[16]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};
    char quartas[8];
    char semi[4];
    char final[2];

    int c,i,j,t = 30,k = 16;
    for(c = 0; c < t; c += 2){
        scanf("%d %d",&partidas[c],&partidas[c+1]);
    }
    int cont = 0;
    for(c = 0; c < t/2; c+=2){ 
        if(partidas[c] > partidas[c+1]){
            quartas[cont] = times[c];
        }else if(partidas[c] < partidas[c+1]){
            quartas[cont] = times[c+1];
        }
        cont ++;
    }
    cont = 0;
    int tam = 0;
    for(c = t/2+1; c < 23; c+=2){
        if(partidas[c] > partidas[c+1]){
            semi[cont] = quartas[tam];
        }else if(partidas[c] < partidas[c+1]){
            semi[cont] = quartas[tam+1];
        }
        cont ++;
        tam += 2;
    }
    cont = 0;
    tam = 0;
    for(c = 24; c < 27;c ++){
        if(partidas[c] > partidas[c+1]){
            final[cont] = semi[tam];
        }else if(partidas[c] < partidas[c+1]){
            final[cont] = semi[tam+1];
        }
        cont ++;
        tam += 2;
    }
    if(partidas[28] > partidas[29]){
        printf("%c",final[0]);
    }else{
        printf("%c",final[1]);
    }
    return 0;
}