#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int contaString(char vetor[9]){
    int tam = 0;
    while (vetor[tam] !='\0'){
        tam ++;
    }
    return tam;
}

void main(){
    int prime,seg,ter,quar,quint,sext;
    char artigo[5][9] = {"o","um","algum","todo","qualquer"};
    char substantivo[5][9]= {"menino","homem","cachorro","carro","gato"};
    char verbo[5][9] = {"passou","pulou","correu","saltos","andou"};
    char preposicao[5][9] = {"sobre","sob","ante","ate","com"};
    char frases[20][40];
    int i,j, tam,cont;
    srand(time(NULL));
    for (i = 0; i < 20; i ++){
        setbuf(stdin,NULL);
        cont = 0;
        prime = rand() % 5;
        seg = rand() % 5;
        ter = rand() % 5;
        quar = rand() % 5;
        quint = rand() % 5;
        sext = rand() % 5;
        tam = contaString(artigo[prime]);
        for (j = 0; j < tam; j ++){
            frases[i][cont] = artigo[prime][j];
            cont ++;
        }
        frases[i][cont] = ' ';
        cont ++;
        tam = contaString(substantivo[seg]);
        for (j = 0 ; j < tam; j ++){
            frases[i][cont] = substantivo[seg][j];
            cont ++;
        }
        frases[i][cont] = ' ';
        cont ++;
        tam = contaString(verbo[ter]);
        for (j = 0; j < tam; j++){
            frases[i][cont] = verbo[ter][j];
            cont ++;
        }
        frases[i][cont] = ' ';
        cont ++;
        tam = contaString(preposicao[quar]);
        for (j = 0; j < tam; j ++){
            frases[i][cont] = preposicao[quar][j];
            cont ++;
        }
        frases[i][cont] = ' ';
        cont ++;
        tam = contaString(artigo[quint]);
        for (j = 0; j < tam; j ++){
            frases[i][cont] = artigo[quint][j];
            cont ++;
        }
        frases[i][cont] = ' ';
        cont ++;
        tam = contaString(substantivo[sext]);
        for (j = 0; j < tam; j ++){
            frases[i][cont] = substantivo[sext][j];
            cont ++;
        }
        frases[i][cont] = '.';
        frases[i][cont+1] = '\0';
        frases[i][0] = frases[i][0] - 32;
        printf("%s\n",frases[i]);
        setbuf(stdin,NULL);
    }
}