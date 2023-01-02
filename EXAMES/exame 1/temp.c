#include <stdio.h>

double soma(double m[][12]){
    int i, j;
    double soma = 0;
    int x = 10, y = 1;
    for(i = 0; i < 5; i ++)
    {
        for(j = x; j > 0; j--){
            soma = soma + (m[i][j]);
            if(j == y){
                j = 0;
            }
        }
        y ++;
        x --;
    
    }
    return soma;
}
 
int main() {
 
    char o;
    int i,j,x = 10,y = 1,cont = 0;
    double matriz[12][12],total,media;
  	scanf(" %c",&o);
    for(i = 0;i < 12; i ++){
        for(j = 0;j < 12; j ++){
            scanf("%lf",&matriz[i][j]);
        }
    }
    total = soma(matriz);
    if(o =='S'){
	    printf("%.1lf\n",total);
	}else if(o == 'M'){
		for(i = 0; i < 5; i ++){
	        for(j = x; j > 0; j--){
	            cont ++;
	            if(j == y){
	            	j = 0;
				}
	    	}
	    	y ++;
	    	x --;
		}
		media = total / cont;
		printf("%.1lf\n",media);
	}
    return 0;
}