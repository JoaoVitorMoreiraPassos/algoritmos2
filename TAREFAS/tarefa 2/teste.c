#include <stdio.h>

char contaNum(char array[101]){
    int t = 0;
    while (array[t] != '\0'){
        t ++;
    }
    return t;
}
int main(){
    long long int d = 9999919999999999999999999999999999999999999999999999999999999999;
    char c[101];
    int i;
    printf("%lld",d);
    sprintf(c,"%ld",d);
    int tam = contaNum(c);
    printf("%s",c);
    printf("\n");
//    for(i = 0; i < tam; i ++){
//    	printf("%c",c[i]);
//	}
    return 0;
}
