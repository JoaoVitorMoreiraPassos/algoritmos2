#include <stdio.h>

int main(){
    int array[10];
    int i,j;
    for (i = 0; i < 10; i ++){
        int dupli = 0;
        scanf("%d",&array[i]);
        if ( i > 0){
            for (j = i-1; j >= 0; j --){
                if (array[i] == array[j]){
                    dupli = 1;
                }
            }
        }
        if( array[i] > 100 || array[i] < 10){
            printf("numero invalido.");
            i --;
        }
        else{
            if (dupli == 0 ){
                printf("%d\n",array[i]);
            }
        }
        printf("\n");
    }
    return 0;
}