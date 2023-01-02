#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char faces[][7] = {"As", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"};
char naipes[][8] = {"Paus", "Ouro", "Copas", "Espadas"};


struct Carta{

    int face, naipe;

};


void ordenada(){

    int i, j = 0;
    for(i = 0; i < 13; i ++){
        printf("%s de %s\n",faces[i],naipes[j]);
        if(i == 12 && j <3){
            j ++;
            i = 0;
        }
    } 

}


void embaralhada(){

    struct Carta deck[52];
    int i,j,cont;
    srand(time(NULL)); 
    for (i = 0; i < 52;i ++){
        while(1){
            cont = 0;
            deck[i].face = (rand() % 13);
            deck[i].naipe = (rand() % 4);
            for(j = 0;j < i; j ++){
                if( deck[i].face == deck[j].face && deck[i].naipe == deck[j].naipe ){
                    cont ++;
                }
            }
            if(cont == 0){
                break;
            }
        }
    }
    for (i = 0; i < 52; i ++){
        printf("%s de %s\n",faces[deck[i].face],naipes[deck[i].naipe]);
    }
}


void main(){

    struct Carta deck[52];
    int entrada;

    scanf("%d",&entrada);
    if(entrada == 1){
        ordenada();
    }else{
        embaralhada(deck[52]);
        printf("\n");
    }

}