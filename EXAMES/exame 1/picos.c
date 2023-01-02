#include <stdio.h>
int tipoPaisagem(int padrao[], int tamanho)
{
    int c, tf = 1;
    if(tamanho == 2 && padrao[0] == padrao[1]){
	    tf = 0;
	}else{
        for(c = 2; c < tamanho; c ++){
            if(padrao[c] >= padrao[c - 1] && padrao[c - 1] >= padrao[c - 2]){
                tf = 0;
                break;
            }else if(padrao[c] <= padrao[c - 1] && padrao[c - 1] <= padrao[c - 2]){
                tf = 0;
                break;
            }
        }
	}
    return tf;

}


int main() {
 
    int n, c, tf;
    scanf("%d",&n);
    int h[n];
    for(c = 0; c < n; c ++)
    {
    	scanf("%d",&h[c]);
	}
	tf = tipoPaisagem(h,n);
	if(tf == 0){
	    printf("0\n");
	}else{
	    printf("1\n");
	}
    return 0;
}