#include <stdio.h>


typedef struct Partes
{

    float r, i;

}Partes;



void somaComplexo(float rz1, float iz1, float rz2, float iz2, float *rz3, float *iz3)
{
    *rz3 = rz1 + rz2;
    *iz3 = iz1 + iz2;
}


void main()
{

    struct Partes z[3];
    int c,yn;

    while (1)
    {
        yn = 0;
        for ( c = 0; c < 2; c ++){
            scanf("%f",&z[c].r);
            if(c == 0 && z[0].r == 0)
            {
                yn = 1;
                break;
            }
            scanf("%f",&z[c].i);
        }
        if(yn == 1){break;}
        somaComplexo(z[0].r, z[0].i, z[1].r, z[1].i, &z[2].r, &z[2].i);
        printf("%.1f + %.1fi\n",z[2].r,z[2].i);
    }

}