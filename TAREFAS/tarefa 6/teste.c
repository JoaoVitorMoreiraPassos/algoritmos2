#include <string.h>

void main(){
    char a[] = "joao vitor";
    char b[] = "moreira passos";
    strncpy(a,b,10);
    printf("%s",a);
}