#include <stdio.h>

void main(){

    char destino;
    int ida_volta;
    float preco[4][2] = {{500,900}, {350,650},{350,600},{300,550}};
    
    scanf("%c",&destino);
    scanf("%d",&ida_volta);
    
    int i = destino - 97;

    printf("R$ %.2f\n",preco[i][ida_volta]);

}