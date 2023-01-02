#include <stdio.h>
#include <math.h>


void raizes(float a, float b, float c, float *x1, float *x2)
{
    float delta = ( pow(b,2) + (-4 * a * c) );
    if(delta < 0)
    {
        *x1 = 0;
        *x2 = 0;
    }
    else
    {
        *x1 = ( ( (b*(-1)) + (pow(delta,(0.5))) ) / (2*a) );
        *x2 = ( ( (b*(-1)) - (pow(delta,(0.5))) ) / (2*a) );
    }
}


void main(){
    float coefientes[3],x1,x2;
    int c;

    while(1)
    {
        for (c = 0; c < 3; c ++){
            scanf("%f",&coefientes[c]);
            if (c == 0 && coefientes[c] == 0){
                break;
            }
        }
        if(coefientes[0] == 0){
            break;
        }
        raizes(coefientes[0],coefientes[1],coefientes[2], &x1, &x2);
        if(x1 == 0 && x2 == 0)
        {
            printf("complexo\n");
        }
        else
        {
            printf("%.1f %.1f\n",x1,x2);
        }
    } 
}
