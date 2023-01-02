#include <stdio.h>
#include <math.h>


void raizes(float a, float b, float c, float *x1, float *x2){
    float delta = ( pow(b,2) + (-4 * a * b) );
    if(delta < 0){
        printf("complexo\n");
    }else{
        *x1 = ( ( (b*(-1)) + (pow(delta,(0.5))) ) / (2*a) );
        *x2 = ( ( (b*(-1)) - (pow(delta,(0.5))) ) / (2*a) );
        printf("%.1f %.1f\n",*x1,*x2);
    }
}


void main(){
    float a,b,c,x1 = 0.0,x2 = 0.0;
    float *x1Ptr = &x1;
    float *x2Ptr = &x2;

    while(1){
        scanf("%f %f %f",&a,&b,&c);
        if ( a == 0){
            break;
        }
        raizes(a,b,c, *x1Ptr, *x2Ptr);
    } 
}
