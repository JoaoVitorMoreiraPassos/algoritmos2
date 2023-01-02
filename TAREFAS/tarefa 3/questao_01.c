#include <stdio.h>

int reverseNumber(int n){
    int reverse = 0;
    while (n % 10 != 0){
        reverse = (reverse*10) + (n % 10);
        n = n / 10;
    }
    return reverse;
}

void main(){
    int n,reverse_n;
    scanf("%d",&n);
    reverse_n = reverseNumber(n);
    printf("%d",reverse_n);
}