#include <stdio.h>

void main(){

    int h1, h2, m1, m2;
    
    scanf("%d %d %d %d",&h1, &h2, &m1, &m2);

    int hn,hv,mn,mv;
    if (h1 > h2){
        hn = h2;
        hv = h1;
    }else{
        hn = h1;
        hv = h2;
    }
    if (m1 > m2){
        mn = m2;
        mv = m1;
    }else{
        mn = m1;
        mv = m2;
    }

    printf("%d %d\n", (hv + mn), (hn * mv));

}