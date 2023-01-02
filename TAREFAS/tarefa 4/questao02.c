#include <stdio.h>
#include <math.h>

float calcDistancia(float x1, float y1, float x2, float y2){
    return sqrt(pow((y2-y1),2)+pow((x2-x1),2));
}

struct Ponto
{
    float x,y;
};

void main(){

    struct Ponto ponto1;
    struct Ponto ponto2;

    scanf("%f %f",&ponto1.x, &ponto1.y);
    scanf("%f %f",&ponto2.x, &ponto2.y);

    printf("Distancia: %.4f\n",calcDistancia(ponto1.x,ponto1.y,ponto2.x,ponto2.y));

}
