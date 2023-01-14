#include "myString/myString.h"

void main(){
    char a[] = "joao vitor";
    char b[] = "moreira passos";
    strncpy(a,b,10);
    strcat(a,b);
    printf("%s\n",a);
}