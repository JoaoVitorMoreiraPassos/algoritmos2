#include <stdio.h>

void main(){

    int x, y;

    scanf("%d %d",&x, &y);
    
    int i , j;
    
    for (i = 0; i < x; i ++){
        for ( j = 0; j < y ; j ++){
            printf("*");
        }
        printf("\n");
    }

}