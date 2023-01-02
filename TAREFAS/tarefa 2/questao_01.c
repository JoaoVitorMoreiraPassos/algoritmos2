#include <stdio.h>


int main(){
    int array[100];
    int i,j,c[11] = {0,0,0,0,0,0,0,0,0,0,0};
    for ( i = 0; i < 100; i ++){
        scanf("%d",&array[i]);
        switch (array[i]){
            case 0:
                c[0] ++;
                break;
            case 1:
                c[1] ++;
                break;
            case 2:
                c[2] ++;
                break;
            case 3:
                c[3] ++;
                break;
            case 4:
                c[4] ++;
                break;
            case 5:
                c[5] ++;
                break;
            case 6:
                c[6] ++;
                break;
            case 7:
                c[7] ++;
                break;
            case 8:
                c[8] ++;
                break;
            case 9:
                c[9] ++;
                break;
            case 10:
                c[10] ++;
                break;
            default:
                break;
        }
        if (array[i] == -1){
            for (j = i; j < 100; j ++){
                array[i] = '\0';
            }
            break;
        }
    }
    int t;
    while (array[t] != '\0'){
        t ++;
    }
    for (i = 0; i < 11; i ++){
        printf("%d %d\n",i,c[i]);
    }

    return 0;

}