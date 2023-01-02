#include <stdio.h>
#include <string.h>

void main(){
    int i,j,loop,n,cont = 0;;
    char idiomas[101][12];
    scanf("%d",&loop);
    for (i = 0; i < loop; i ++)
    {
        scanf("%d",&n);
        for (j = 0; j < n; j ++ )
        {
            scanf("%s",&idiomas[j]);
        }
        for (j = 1; j < n; j ++ )
        {
            if(strcmp(idiomas[j],idiomas[j-1]) != 0)
            {
                cont ++;
                break;
            }
        }
        if(cont > 0)
        {
            printf("ingles\n");
        }
        else
        {
            printf("%s\n",idiomas[0]);
        }
    }
}