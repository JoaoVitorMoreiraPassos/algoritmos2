#include <stdio.h>

void main(){

    int x, y;

    scanf("%d %d",&x, &y);

    int i, j;
    
    for (i = 0; i < x; i ++){
        for (j = 0; j < y; j ++){
            if (i == 0 || i == x - 1 || j == 0 || j == y -1){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}