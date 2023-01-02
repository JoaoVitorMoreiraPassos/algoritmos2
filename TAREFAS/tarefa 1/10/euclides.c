#include <stdio.h>
int euclides(int n1, int n2){
    int temp;
    int cont = 1;
    do{
        temp = n1 % n2;
        n1 = n2;
        n2 = temp;
        cont += 1;
    } 
    while (temp != 0);
    printf("iteracoes: %d\n",cont);
    return n1;
}

void main(){

    int n1, n2, mdc;

    scanf("%d %d", &n1, &n2);

    printf("mdc(%d, %d): %d ",n1, n2,euclides(n1,n2));

}