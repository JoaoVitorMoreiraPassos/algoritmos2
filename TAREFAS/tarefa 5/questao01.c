#include <stdio.h>
#include <math.h>

void cubo( int *nPtr)
{
    float c;
    c = pow(*nPtr,3);
    *nPtr = c;
}

void main()
{

    int n;

    while(1){
        scanf("%d",&n);
        if(n == 0){
            break;
        }
        cubo(&n);
        printf("%d\n",n);
    }
}