#include <stdio.h>
#define m 2
#define n 3
#define p 2

int main(){
    int matriza[m][n] = {{1,2,3},{-2,0,4}};
    int matrizb[n][p] = {{2,3},{0,1},{-1,4}};
    int matrizc[m][p];
    int i, j,k,cont;
    
    for (i = 0; i < m; i ++){
        for (j = 0; j < p; j ++){
            cont = 0;
            for (k = 0; k < n; k ++){
                cont += (matriza[i][k] * matrizb[k][j]);
            }
            matrizc[i][j] = cont;
        }
    }

    for (i = 0; i < m; i ++){
        for (j = 0; j < m; j ++){
            printf("%d ",matrizc[i][j]);
        }
        printf("\n");
    }

    return 0;

}