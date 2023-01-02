#include <stdio.h>
#include "myString.h"

void main(){
    char x[] = "Happy Birthday to you";
    char y[25];
    char z[25];
    
    strcpy(y,x);
    printf( "%s%s\n%s%s\n",
            "The string in array x is: ",x,
            "the string in array y is: ",y);

    printf( "%s%s\n",
            "The string in array y is now: ",y);
    
    strncpy(z, x, 14);
    z[ 14 ] = '\0';
    printf("The string in array z is: %s\n",z);
}
