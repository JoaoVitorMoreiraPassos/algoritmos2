#include <stdio.h>

void upper(char *pont)
{
    char capitulada[100];
    int t = 0;
    while(*(pont + t) != '\0')
    {
        if(*(pont + t) > 96 && *(pont + t) < 123)
        {
            *(pont + t) = *(pont + t) - 32;
        }
        t ++;
    }
}


void main()
{
    char frase[100];
    while(1)
    {
        scanf("%[^\n]s",&frase);
        if(frase[0] == '0')
        {
            break;
        }
        upper(frase);
        printf("%s\n",frase);
        setbuf(stdin,NULL);
    }
}