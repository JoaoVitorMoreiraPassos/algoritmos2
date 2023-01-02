#include <stdio.h>

int main(void)
{
    char string1[20] = {}, string2[20]  = {};

    scanf("%[^\n]s", &string1);
    setbuf(stdin,NULL);
    scanf("%[^\n]s", &string2);

    printf("%s %s\n", string1, string2);
    
    return 0;
}
